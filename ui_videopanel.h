/********************************************************************************
** Form generated from reading UI file 'videopanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPANEL_H
#define UI_VIDEOPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
// #include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_videoPanel
{
public:
    // QCameraViewfinder *viewFinder;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *recordingSettingsButton;
    QPushButton *recordButton;
    QLabel *label_5;
    QLineEdit *requestedFR;
    QLabel *label_4;
    QLineEdit *actualFR;
    QLabel *label_3;
    QLineEdit *frameCount;
    QLabel *label_2;
    QLineEdit *timeStamp;
    QLabel *label_7;
    QLineEdit *resolutionEdit;

    void setupUi(QWidget *videoPanel)
    {
        if (videoPanel->objectName().isEmpty())
            videoPanel->setObjectName(QString::fromUtf8("videoPanel"));
        videoPanel->resize(731, 444);
   /*     viewFinder = new QCameraViewfinder(videoPanel);
        viewFinder->setObjectName(QString::fromUtf8("viewFinder"));
        viewFinder->setEnabled(true);
        viewFinder->setGeometry(QRect(230, 10, 491, 421));
        viewFinder->setAutoFillBackground(true);*/
        verticalLayoutWidget = new QWidget(videoPanel);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 211, 279));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recordingSettingsButton = new QPushButton(verticalLayoutWidget);
        recordingSettingsButton->setObjectName(QString::fromUtf8("recordingSettingsButton"));
        recordingSettingsButton->setEnabled(true);

        verticalLayout->addWidget(recordingSettingsButton);

        recordButton = new QPushButton(verticalLayoutWidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setEnabled(false);

        verticalLayout->addWidget(recordButton);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        requestedFR = new QLineEdit(verticalLayoutWidget);
        requestedFR->setObjectName(QString::fromUtf8("requestedFR"));
        requestedFR->setEnabled(true);
        requestedFR->setReadOnly(true);

        verticalLayout->addWidget(requestedFR);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        actualFR = new QLineEdit(verticalLayoutWidget);
        actualFR->setObjectName(QString::fromUtf8("actualFR"));
        actualFR->setEnabled(true);
        actualFR->setReadOnly(true);

        verticalLayout->addWidget(actualFR);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        frameCount = new QLineEdit(verticalLayoutWidget);
        frameCount->setObjectName(QString::fromUtf8("frameCount"));
        frameCount->setEnabled(true);
        frameCount->setReadOnly(true);

        verticalLayout->addWidget(frameCount);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        timeStamp = new QLineEdit(verticalLayoutWidget);
        timeStamp->setObjectName(QString::fromUtf8("timeStamp"));
        timeStamp->setEnabled(true);
        timeStamp->setReadOnly(true);

        verticalLayout->addWidget(timeStamp);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        resolutionEdit = new QLineEdit(verticalLayoutWidget);
        resolutionEdit->setObjectName(QString::fromUtf8("resolutionEdit"));
        resolutionEdit->setReadOnly(true);

        verticalLayout->addWidget(resolutionEdit);


        retranslateUi(videoPanel);

        QMetaObject::connectSlotsByName(videoPanel);
    } // setupUi

    void retranslateUi(QWidget *videoPanel)
    {
        videoPanel->setWindowTitle(QApplication::translate("videoPanel", "Form", 0, QApplication::UnicodeUTF8));
        recordingSettingsButton->setText(QApplication::translate("videoPanel", "Recording Settings", 0, QApplication::UnicodeUTF8));
        recordButton->setText(QApplication::translate("videoPanel", "Select video settings first", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("videoPanel", "Requested Frame Rate", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("videoPanel", "Actual Frame Rate", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("videoPanel", "Frame Count", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("videoPanel", "Timestamp", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("videoPanel", "Resolution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class videoPanel: public Ui_videoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPANEL_H
