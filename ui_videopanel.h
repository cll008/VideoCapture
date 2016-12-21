/********************************************************************************
** Form generated from reading UI file 'videopanel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPANEL_H
#define UI_VIDEOPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoPanel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
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
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *videoCodecBox;
    QComboBox *videoFramerateBox;
    QLabel *videoFrameRateLabel;
    QLabel *videoResolutionLabel;
    QLabel *videoCodecLabel;
    QComboBox *videoResolutionBox;
    QLabel *videoFormatLabel;
    QComboBox *videoFormatBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *saveFileNameEdit;
    QLabel *label;

    void setupUi(QWidget *videoPanel)
    {
        if (videoPanel->objectName().isEmpty())
            videoPanel->setObjectName(QStringLiteral("videoPanel"));
        videoPanel->resize(622, 306);
        verticalLayoutWidget = new QWidget(videoPanel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 211, 279));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recordButton = new QPushButton(verticalLayoutWidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setEnabled(true);

        verticalLayout->addWidget(recordButton);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        requestedFR = new QLineEdit(verticalLayoutWidget);
        requestedFR->setObjectName(QStringLiteral("requestedFR"));
        requestedFR->setEnabled(true);
        requestedFR->setReadOnly(true);

        verticalLayout->addWidget(requestedFR);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        actualFR = new QLineEdit(verticalLayoutWidget);
        actualFR->setObjectName(QStringLiteral("actualFR"));
        actualFR->setEnabled(true);
        actualFR->setReadOnly(true);

        verticalLayout->addWidget(actualFR);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        frameCount = new QLineEdit(verticalLayoutWidget);
        frameCount->setObjectName(QStringLiteral("frameCount"));
        frameCount->setEnabled(true);
        frameCount->setReadOnly(true);

        verticalLayout->addWidget(frameCount);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        timeStamp = new QLineEdit(verticalLayoutWidget);
        timeStamp->setObjectName(QStringLiteral("timeStamp"));
        timeStamp->setEnabled(true);
        timeStamp->setReadOnly(true);

        verticalLayout->addWidget(timeStamp);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        resolutionEdit = new QLineEdit(verticalLayoutWidget);
        resolutionEdit->setObjectName(QStringLiteral("resolutionEdit"));
        resolutionEdit->setReadOnly(true);

        verticalLayout->addWidget(resolutionEdit);

        groupBox_2 = new QGroupBox(videoPanel);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 10, 368, 230));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        videoCodecBox = new QComboBox(groupBox_2);
        videoCodecBox->setObjectName(QStringLiteral("videoCodecBox"));

        gridLayout_2->addWidget(videoCodecBox, 7, 0, 1, 2);

        videoFramerateBox = new QComboBox(groupBox_2);
        videoFramerateBox->setObjectName(QStringLiteral("videoFramerateBox"));

        gridLayout_2->addWidget(videoFramerateBox, 3, 0, 1, 2);

        videoFrameRateLabel = new QLabel(groupBox_2);
        videoFrameRateLabel->setObjectName(QStringLiteral("videoFrameRateLabel"));

        gridLayout_2->addWidget(videoFrameRateLabel, 2, 0, 1, 2);

        videoResolutionLabel = new QLabel(groupBox_2);
        videoResolutionLabel->setObjectName(QStringLiteral("videoResolutionLabel"));

        gridLayout_2->addWidget(videoResolutionLabel, 0, 0, 1, 2);

        videoCodecLabel = new QLabel(groupBox_2);
        videoCodecLabel->setObjectName(QStringLiteral("videoCodecLabel"));

        gridLayout_2->addWidget(videoCodecLabel, 6, 0, 1, 2);

        videoResolutionBox = new QComboBox(groupBox_2);
        videoResolutionBox->setObjectName(QStringLiteral("videoResolutionBox"));

        gridLayout_2->addWidget(videoResolutionBox, 1, 0, 1, 2);

        videoFormatLabel = new QLabel(groupBox_2);
        videoFormatLabel->setObjectName(QStringLiteral("videoFormatLabel"));
        videoFormatLabel->setEnabled(false);

        gridLayout_2->addWidget(videoFormatLabel, 4, 0, 1, 1);

        videoFormatBox = new QComboBox(groupBox_2);
        videoFormatBox->setObjectName(QStringLiteral("videoFormatBox"));
        videoFormatBox->setEnabled(false);

        gridLayout_2->addWidget(videoFormatBox, 5, 0, 1, 2);

        layoutWidget = new QWidget(videoPanel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 260, 351, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveFileNameEdit = new QLineEdit(layoutWidget);
        saveFileNameEdit->setObjectName(QStringLiteral("saveFileNameEdit"));

        horizontalLayout->addWidget(saveFileNameEdit);

        label = new QLabel(videoPanel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 240, 931, 20));

        retranslateUi(videoPanel);

        QMetaObject::connectSlotsByName(videoPanel);
    } // setupUi

    void retranslateUi(QWidget *videoPanel)
    {
        videoPanel->setWindowTitle(QApplication::translate("videoPanel", "Form", Q_NULLPTR));
        recordButton->setText(QApplication::translate("videoPanel", "Record", Q_NULLPTR));
        label_5->setText(QApplication::translate("videoPanel", "Requested Frame Rate", Q_NULLPTR));
        requestedFR->setText(QString());
        label_4->setText(QApplication::translate("videoPanel", "Actual Frame Rate", Q_NULLPTR));
        label_3->setText(QApplication::translate("videoPanel", "Frame Count", Q_NULLPTR));
        label_2->setText(QApplication::translate("videoPanel", "Timestamp", Q_NULLPTR));
        label_7->setText(QApplication::translate("videoPanel", "Resolution", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("videoPanel", "Video Settings", Q_NULLPTR));
        videoFrameRateLabel->setText(QApplication::translate("videoPanel", "Framerate:", Q_NULLPTR));
        videoResolutionLabel->setText(QApplication::translate("videoPanel", "Resolution:", Q_NULLPTR));
        videoCodecLabel->setText(QApplication::translate("videoPanel", "Video Codec:", Q_NULLPTR));
        videoFormatLabel->setText(QApplication::translate("videoPanel", "Video  Format (windows only):", Q_NULLPTR));
        saveFileNameEdit->setText(QApplication::translate("videoPanel", "videoCapture.avi", Q_NULLPTR));
        label->setText(QApplication::translate("videoPanel", "Save File Name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoPanel: public Ui_videoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPANEL_H
