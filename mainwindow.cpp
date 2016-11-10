#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Objbase.h>
#include <iostream>


// enumerate cameras using windows media foundation
// TODO: the same but cross platform -- perhaps using Qt5? this requires
// shifting the whole project to visual studio >= 2010, which is a pain...
#ifdef _WIN32

// calls to mf_enumerate_cameras go here

#endif


MainWindow::MainWindow(QWidget *parent) : 
	QMainWindow(parent), 
	ui(new Ui::MainWindow) 
{
	ui->setupUi(this);
	theWindow = this;
	
	QObject::connect(ui->newVideoButton, SIGNAL(clicked()), this, SLOT(newVideo()));

	has_camera_ = false;

	std::vector<std::string> camera_names;
	WmfEnumerateCameras wmf_obj;

	// will print the names of all available cameras to the console and store them in the vector:
	wmf_obj.getCameraNames(camera_names);

	for (std::vector<std::string>::iterator it = camera_names.begin();
		it != camera_names.end();
		++it) {
		ui->cameraBox->addItem(QString("%1").arg(it->c_str()));
	}
}

void MainWindow::closeEvent(QCloseEvent *ev) {
	//if (outletButtons_ || outletPosition_)
	//	ev->ignore();

	videoPanels.clear();
}


MainWindow::~MainWindow() {

	delete ui;
}

void MainWindow::newVideo(void) {
	
	QString panelCameraName = cameraBox->currentText();
	boost::shared_ptr<VideoPanel> vp(new VideoPanel(0, panelCameraName));
	//VideoPanel *vp = new VideoPanel;
	videoPanels.push_back(vp);
	vp->show();
	
}

