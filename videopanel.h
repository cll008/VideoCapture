#ifndef VIDEOPANEL_H
#define VIDEOPANEL_H

#define WIN32_LEAN_AND_MEAN

// boost
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>

// Qt
#include <QtWidgets>
#include <QMediaRecorder>
#include <QCameraImageCapture>
#include <QCameraViewFinder>
#include <QCameraInfo>
#include <QVideoWidget>
#include <QApplication>
#include <QMediaService>
#include <QMediaRecorder>
#include <QMediaMetaData>
#include <QMainWindow>
#include <QCloseEvent>

// opencv
#include "opencv2/opencv.hpp"

// LSL
#include "../../LSL/liblsl/include/lsl_cpp.h"

// STL
#include <string>
#include <vector>

// custom container for frame data, frame counter, and lsl timestamp
typedef struct _frame_data {
	cv::Mat         frame;
	int             count;
	double          timestamp;
}t_frame_data;

namespace Ui {
class videoPanel;
}

class VideoPanel : public QWidget
{
    Q_OBJECT

public:
    VideoPanel(QString& cameraName, QWidget *parent = 0);

    ~VideoPanel();

private slots:
	void closeEvent(QCloseEvent *ev);
	void configureVideoSettings(void);
	void record(void);

private:
	Ui::videoPanel *ui;
	
	QCamera *camera;
	QList<QCameraInfo> cameraInfos;
	QCameraImageCapture *imageCapture;
    QMediaRecorder* mediaRecorder;

    QImageEncoderSettings imageSettings;
    QAudioEncoderSettings audioSettings;
   // QVideoEncoderSettings videoSettings;
  	QString videoContainerFormat;
    bool isCapturingVideo;

	std::vector<t_frame_data> frame_buf_;                   // new and improved frame buffer
	boost::shared_ptr<boost::thread> r_thread_;             // thread for reading frames
	boost::shared_ptr<boost::thread> w_thread_;             // thread for writing frames
															//boost::timed_mutex mutex_;                              // conditional mutex for r/w threads
	boost::mutex mutex_;
	bool r_stop_;
	bool w_stop_;

	void stop_read(void);
	void stop_write(void);

	void read_thread(void);
	void write_thread(void);

	cv::VideoCapture reader;
	cv::VideoWriter writer;

	cv::Size video_size_;
	bool has_camera_;
	int fps_;
	
	boost::shared_ptr<boost::thread> capture_thread_;
	bool stop_;

};

#endif // VIDEOPANEL_H
