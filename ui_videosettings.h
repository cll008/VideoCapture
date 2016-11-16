/********************************************************************************
** Form generated from reading UI file 'videosettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOSETTINGS_H
#define UI_VIDEOSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoSettingsUi
{
public:
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *videoCodecBox;
    QLabel *videoResolutionLabel;
    QComboBox *videoResolutionBox;
    QLabel *videoFrameRateLabel;
    QComboBox *videoFramerateBox;
    QLabel *label_6;
    QComboBox *videoFormatBox;
    QLabel *videoFormatLabel;
    QComboBox *containerFormatBox;
    QLabel *label_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *audioSampleRateBox;
    QLabel *label_5;
    QComboBox *audioCodecBox;
    QLabel *label_2;
    QCheckBox *recordAudioCheck;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VideoSettingsUi)
    {
        if (VideoSettingsUi->objectName().isEmpty())
            VideoSettingsUi->setObjectName(QString::fromUtf8("VideoSettingsUi"));
        VideoSettingsUi->resize(561, 280);
        gridLayout_4 = new QGridLayout(VideoSettingsUi);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea = new QScrollArea(VideoSettingsUi);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 543, 231));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        videoCodecBox = new QComboBox(groupBox_2);
        videoCodecBox->setObjectName(QString::fromUtf8("videoCodecBox"));

        gridLayout_2->addWidget(videoCodecBox, 7, 0, 1, 2);

        videoResolutionLabel = new QLabel(groupBox_2);
        videoResolutionLabel->setObjectName(QString::fromUtf8("videoResolutionLabel"));

        gridLayout_2->addWidget(videoResolutionLabel, 0, 0, 1, 2);

        videoResolutionBox = new QComboBox(groupBox_2);
        videoResolutionBox->setObjectName(QString::fromUtf8("videoResolutionBox"));

        gridLayout_2->addWidget(videoResolutionBox, 1, 0, 1, 2);

        videoFrameRateLabel = new QLabel(groupBox_2);
        videoFrameRateLabel->setObjectName(QString::fromUtf8("videoFrameRateLabel"));

        gridLayout_2->addWidget(videoFrameRateLabel, 2, 0, 1, 2);

        videoFramerateBox = new QComboBox(groupBox_2);
        videoFramerateBox->setObjectName(QString::fromUtf8("videoFramerateBox"));

        gridLayout_2->addWidget(videoFramerateBox, 3, 0, 1, 2);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 6, 0, 1, 2);

        videoFormatBox = new QComboBox(groupBox_2);
        videoFormatBox->setObjectName(QString::fromUtf8("videoFormatBox"));
        videoFormatBox->setEnabled(false);

        gridLayout_2->addWidget(videoFormatBox, 5, 0, 1, 2);

        videoFormatLabel = new QLabel(groupBox_2);
        videoFormatLabel->setObjectName(QString::fromUtf8("videoFormatLabel"));
        videoFormatLabel->setEnabled(false);

        gridLayout_2->addWidget(videoFormatLabel, 4, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 4, 1);

        containerFormatBox = new QComboBox(scrollAreaWidgetContents);
        containerFormatBox->setObjectName(QString::fromUtf8("containerFormatBox"));

        gridLayout_3->addWidget(containerFormatBox, 3, 0, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        audioSampleRateBox = new QComboBox(groupBox);
        audioSampleRateBox->setObjectName(QString::fromUtf8("audioSampleRateBox"));
        audioSampleRateBox->setEnabled(false);

        gridLayout->addWidget(audioSampleRateBox, 4, 0, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 2);

        audioCodecBox = new QComboBox(groupBox);
        audioCodecBox->setObjectName(QString::fromUtf8("audioCodecBox"));
        audioCodecBox->setEnabled(false);

        gridLayout->addWidget(audioCodecBox, 2, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        recordAudioCheck = new QCheckBox(groupBox);
        recordAudioCheck->setObjectName(QString::fromUtf8("recordAudioCheck"));

        gridLayout->addWidget(recordAudioCheck, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(VideoSettingsUi);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(VideoSettingsUi);
        QObject::connect(buttonBox, SIGNAL(accepted()), VideoSettingsUi, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VideoSettingsUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(VideoSettingsUi);
    } // setupUi

    void retranslateUi(QDialog *VideoSettingsUi)
    {
        VideoSettingsUi->setWindowTitle(QApplication::translate("VideoSettingsUi", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("VideoSettingsUi", "Video", 0, QApplication::UnicodeUTF8));
        videoResolutionLabel->setText(QApplication::translate("VideoSettingsUi", "Resolution:", 0, QApplication::UnicodeUTF8));
        videoFrameRateLabel->setText(QApplication::translate("VideoSettingsUi", "Framerate:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("VideoSettingsUi", "Video Codec:", 0, QApplication::UnicodeUTF8));
        videoFormatLabel->setText(QApplication::translate("VideoSettingsUi", "Video  Format (windows only):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VideoSettingsUi", "Container Format:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("VideoSettingsUi", "Audio", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VideoSettingsUi", "Sample Rate:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VideoSettingsUi", "Audio Codec:", 0, QApplication::UnicodeUTF8));
        recordAudioCheck->setText(QApplication::translate("VideoSettingsUi", "Record Audio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoSettingsUi: public Ui_VideoSettingsUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOSETTINGS_H
