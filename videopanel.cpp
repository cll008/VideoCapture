
#include "videopanel.h"
#include "ui_videopanel.h"
#include "mf_enumerate_cameras.h"

#include <Objbase.h>
#include <iostream>

std::vector<wmfCameraInfo> camera_infos;

VideoPanel::VideoPanel(QString& cameraName, QWidget *parent) :

	QWidget(parent),
	ui(new Ui::videoPanel)
{
	ui->setupUi(this);
	this->setWindowTitle(cameraName);

	// populate GUI with options
	WmfEnumerateCameras wmfNewCamera_obj;
	wmfNewCamera_obj.getCameraInfo(cameraName.toStdString(), camera_infos);

#ifdef _WIN32
	ui->videoResolutionLabel->setEnabled(false);
	ui->videoResolutionBox->setEnabled(false);
	ui->videoFrameRateLabel->setEnabled(false);
	ui->videoFramerateBox->setEnabled(false);
	ui->videoCodecBox->setEnabled(false);
	ui->videoCodecLabel->setEnabled(false);

	ui->videoFormatLabel->setEnabled(true);
	ui->videoFormatBox->setEnabled(true);


	for (int i = 0; i < camera_infos.size(); i++) {
		QString width = QString::number(camera_infos[i].width);
		QString height = QString::number(camera_infos[i].height);
		QString frameRate = QString::number(camera_infos[i].frameRate);
		QString denominator = QString::number(camera_infos[i].denominator);

		ui->videoFormatBox->addItem(QString("%1x%2, %3 frames/%4 denominator").arg(width).arg(height).arg(frameRate).arg(denominator));
	}

#endif

	//
	// signals and slots here
	QObject::connect(ui->recordButton, SIGNAL(clicked()), this, SLOT(record()));
}


void VideoPanel::closeEvent(QCloseEvent *ev) {

	//if (outletButtons_ || outletPosition_)
	//	ev->ignore();
}

VideoPanel::~VideoPanel() {
	stop_read();
	stop_write();
	delete ui;
}

void VideoPanel::record() {
	if (ui->recordButton->text() == QString::fromStdString("Record")) {

		try{
			ui->recordButton->setText("Recording... press to stop");
			ui->videoFormatLabel->setEnabled(false);
			ui->videoFormatBox->setEnabled(false);
			ui->saveFileNameEdit->setEnabled(false);

			int vidFormatIdx = ui->videoFormatBox->currentIndex();
			int frameWidth  = camera_infos[vidFormatIdx].width;
			int frameHeight = camera_infos[vidFormatIdx].height;
				
			
			ui->resolutionEdit->setText(QString("%1x%2").arg(frameWidth).arg(frameHeight));
			ui->requestedFR->setText(QString("Hardcoded at 30fps currently"));

			reader.open(0);

			cv::Mat foo_frame;       // get first frame to find size and type
			reader >> foo_frame;
			if (reader.isOpened()) {   // these methods return 0 if a frame hasn't been grabbed

				
				reader.set(CV_CAP_PROP_FRAME_WIDTH , frameWidth);
				reader.set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);
				//reader.set(CV_CAP_PROP_FPS, fps_);
				
				video_size_ = cv::Size(frameWidth, frameHeight);
				fps_ = camera_infos[vidFormatIdx].frameRate;

				has_camera_ = true;

			}
			else { std::cout << "Could not start camera." << std::endl; } // needs more informative error checking

			r_stop_ = false;
			r_thread_.reset(new boost::thread(&VideoPanel::read_thread, this));

			// for some reason on Windows writers need to be originated in the main thread?
			// http://answers.opencv.org/question/76077/videowriter-fails-to-open-inside-thread/
			// but this also works if the reader and writer are in the same thread (not main thread)
			// all along

			std::string saveName = ui->saveFileNameEdit->text().toStdString();
			writer.open(saveName, -1, fps_, video_size_);//CV_FOURCC('M', 'P', 'E', 'G'), fps_, video_size_);
			w_stop_ = false;
			w_thread_.reset(new boost::thread(&VideoPanel::write_thread, this));
		}

		catch (std::exception &e) {
			QMessageBox::critical(this, "Error", (std::string("Could not start recording: ") += e.what()).c_str(), QMessageBox::Ok);
			return;
		}
	}


	else {
		try {
			// winCapture->finishCapture();
			r_stop_ = true;
			w_stop_ = true;
			ui->recordButton->setText("Record");
			ui->videoFormatLabel->setEnabled(true);
			ui->videoFormatBox->setEnabled(true);
			ui->saveFileNameEdit->setEnabled(true);
		}
		catch (std::exception &e) {
			QMessageBox::critical(this, "Error", (std::string("Could not stop recording: ") += e.what()).c_str(), QMessageBox::Ok);
			return;
		}
	}
}


void VideoPanel::read_thread(void) {

	if (reader.isOpened()) {

		//fps_ = reader.get(CV_CAP_PROP_FPS); //opencv webcam fps has to be manually calculated
		if (fps_ == 0)fps_ = 30; 
		has_camera_ = true;

	}
	else { return; } // needs more informative error checking

					 // frame counter
	int cnt = 1;

	// lsl boilerplate
	lsl::stream_info   info("VideoCaptureRead", "Video", 1, fps_, lsl::cf_int32, boost::asio::ip::host_name());
	lsl::stream_outlet outlet(info);

	try {

		while (!r_stop_) {

			double time_now = lsl::local_clock();

			cv::Mat frame;
			t_frame_data frame_data;

			// impose a hard lock
			//boost::unique_lock<boost::timed_mutex> lock(mutex_);
			reader >> frame;
			frame_data.frame = frame;
			frame_data.timestamp = time_now;
			frame_data.count = cnt;
			mutex_.lock();
			frame_buf_.push_back(frame_data);
			mutex_.unlock();
			//if(cnt%5==0){
			//	while(!frame_buf_.empty()){

			//		frameWrite = frame_buf_[0];
			//		writer.write(frameWrite);
			//		frame_buf_.erase(frame_buf_.begin());
			//	}
			//}
			//boost::timed_mutex *m = lock.release();
			//m->unlock();

			// push lsl counter
			outlet.push_sample(&cnt, time_now);
			cnt++;

			cv::imshow("VideoCapture", frame);
			ui->actualFR->setText(QString::number(fps_));
			ui->frameCount->setText(QString::number(cnt));


			// display the frame?
			if (cv::waitKey((int)(1000 / fps_) - 3) >= 0) {// for this duration?
				r_stop_ = true;
				w_stop_ = true;
			}
		}
	}
	catch (std::exception &e) {
		QMessageBox::critical(this, "Error", (std::string("Error reading from camera 0: ") += e.what()).c_str(), QMessageBox::Ok);
		return;
	}

}

void VideoPanel::write_thread(void) {


	try {
		lsl::stream_info   info("VideoCaptureWrite", "Video", 1, fps_, lsl::cf_int32, boost::asio::ip::host_name());
		lsl::stream_outlet outlet(info);

		if (!writer.isOpened()) {
			QMessageBox::critical(this, "Error", "failed to open write file", QMessageBox::Ok);
			//return;
		}
		while (!w_stop_) {

			// make sure the camera is on and reading
			if (has_camera_) {

				// sleep for a moment to rest the CPU
				//boost::this_thread::sleep(boost::posix_time::millisec(5)); // make this a variable?


				// try to empty the frame buffer
				while (!frame_buf_.empty()) {
					//cv::Mat frame;

					// try to lock the mutex
					//boost::unique_lock<boost::timed_mutex> lock(mutex_, boost::try_to_lock);
					// if the reader isn't busy, write some data
					//if(lock.owns_lock()){

					// push the write data (counter and timestamp)
					outlet.push_sample(&frame_buf_[0].count, frame_buf_[0].timestamp);
					// write the frame
					writer.write(frame_buf_[0].frame);
					// pop the top frame
					mutex_.lock();
					frame_buf_.erase(frame_buf_.begin());
					mutex_.unlock();

					//}
					// otherwise, try again
				}


			}
		}


	}
	catch (std::exception &e) {
		QMessageBox::critical(this, "Error", (std::string("Error writing frames: ") += e.what()).c_str(), QMessageBox::Ok);
		return;
	}



}


void VideoPanel::stop_read(void) {

	if (r_thread_) {
		try {
			r_stop_ = true;
			r_thread_->interrupt();
			r_thread_->join();
			r_thread_.reset();
			reader.release();
		}
		catch (std::exception &e) {
			QMessageBox::critical(this, "Error", (std::string("Could not stop camera read: ") += e.what()).c_str(), QMessageBox::Ok);
			return;
		}
	}
}

void VideoPanel::stop_write(void) {
	if (w_thread_) {
		try {
			w_stop_ = true;
			w_thread_->interrupt();
			w_thread_->join();
			w_thread_.reset();
			writer.release();
		}
		catch (std::exception &e) {
			QMessageBox::critical(this, "Error", (std::string("Could not stop camera write: ") += e.what()).c_str(), QMessageBox::Ok);
			return;
		}
	}
}