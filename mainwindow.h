#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// windows
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "videopanel.h"

// Qt
#include <QtWidgets\QMainWindow>
#include <QtGui\QCloseEvent>
#include <QtWidgets\QMessageBox>
#include <QtNetwork\QHostInfo>
#include <QCameraInfo>


// opencv -- for webcams and such
#include "opencv2/opencv.hpp"

// pointgrey -- for interfacing with pointgrey cameras


// LSL
#include "../../LSL/liblsl/include/lsl_cpp.h"

// STL
#include <string>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:    
	// close event: used to disable closing while linked
    void closeEvent(QCloseEvent *ev);
	void newVideo(void);


private:
	Ui::MainWindow *ui;										// window pointer
	QList<QCameraInfo> cameraInfos;
	std::vector<boost::shared_ptr<VideoPanel>> videoPanels; // need this and videopanel.h or new VideoPanel goes out of scope and closes?

	bool has_camera_;

};

extern MainWindow *theWindow;

#endif // MAINWINDOW_H
