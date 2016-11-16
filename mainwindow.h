#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "videopanel.h"
// Qt
#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtNetwork/QHostInfo>
// #include <QCamera>


// opencv -- for webcams and such
#include "opencv2/opencv.hpp"

// pointgrey -- for interfacing with pointgrey cameras

// windows
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "mf_enumerate_cameras.h"
#endif

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
	// QList<QCameraInfo> cameraInfos;
	std::vector<boost::shared_ptr<VideoPanel>> videoPanels; // need this and videopanel.h or new VideoPanel goes out of scope and closes?

	bool has_camera_;

};

extern MainWindow *theWindow;

#endif // MAINWINDOW_H
