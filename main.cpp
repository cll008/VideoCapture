#include "mainwindow.h"
#include <QtGui\QApplication>

MainWindow *theWindow = NULL;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
	MainWindow w;
    w.show();
   
    return a.exec();
}
