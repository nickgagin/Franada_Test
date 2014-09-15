#include "videoform.h"
#include "ui_videoform.h"

VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl::fromLocalFile("D:\\Video Flight\\2014.06.06  08.21-09.30\\2014-06-06-08-20(h264).avi"));
    mediaPlayer->setVolume(50);
//    mediaPlayer->play();

    videoSurface = new QAbstractVideoSurface();

    mediaPlayer->setVideoOutput(videoSurface);
    videoSurface->start();
    if(!videoSurface->isActive()) qDebug << "videoSurface doesn't work properly. Isn't active. Check it out";

}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::TimerTick()
{

}
