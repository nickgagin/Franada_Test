#include "videoform.h"
#include "ui_videoform.h"

VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm)
{
    ui->setupUi(this);

    videoWidget = new QVideoWidget;
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("D:\\Video Flight\\2014.06.06  08.21-09.30\\2014-06-06-08-20.avi")); //(h264)
//    player->setVolume(50);
//    player->setVideoOutput(videoWidget);

//    videoWidget->show();

//    player->

//    videoProbe = new QVideoProbe(this);
//    if(videoProbe->setSource(player))
//    {
//        connect(videoProbe,SIGNAL(videoFrameProbed(QVideoFrame)),
//                this, SLOT(showVideoFrame(QVideoFrame)));
//    }

    myVideoSurface = new MyVideoSurface;
    player->setVideoOutput(myVideoSurface);
    player->play();
    myVideoSurface->startTimer(40);

    QMediaContent mediaContent = player->currentMedia();
    QMediaResource mediaResource = mediaContent.canonicalResource();
    qDebug() << "Video codec" << mediaResource.videoCodec();
    qDebug() << "Video bitrate" << mediaResource.videoBitRate();
    qDebug() << "Audio codec" << mediaResource.audioCodec();
    qDebug() << "Audio bitrate" << mediaResource.audioBitRate();
}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::TimerTick()
{

}

void VideoForm::showVideoFrame(QVideoFrame frame)
{
    QPixmap pixmapFrame = QPixmap();


    if(!frame.isValid()){
        return;
    }
    else qDebug() << "With frame is everything is ok";

    if(frame.map(QAbstractVideoBuffer::ReadOnly)){
//        if(frame.pixelFormat() == QVideoFrame::Format_UYVY){
//            QImage frameImage(frame.size(),QImage::Format_RGB32);

//            const uchar *src = frame.bits();
//            uchar *dst = frameImage.bits();
//            const int srcLineStep = frame.bytesPerLine();
//            const int dstLineStep = frameImage.bytesPerLine();
//            const int height = frame.height();
//            const int width = frame.width();
//            for (int y = 0; y < height; y++) {
//                uyvy422_to_rgb16_line_neon(dst, src, width);
//                src += srcLineStep;
//                dst += dstLineStep;
//            }
//            pixmapFrame = QPixmap::fromImage(frameImage.scaled(frame.size(), Qt::IgnoreAspectRatio, Qt::FastTransformation));
//        }
//        else{
            QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat());
            if(imageFormat != QImage::Format_Invalid){
                QImage frameImage(frame.bits(), frame.width(), frame.height(),frame.bytesPerLine(),imageFormat);
                pixmapFrame = QPixmap::fromImage(frameImage.scaled(frame.size(),Qt::IgnoreAspectRatio, Qt::FastTransformation));
//            }
            }
            else
                qDebug() << "Format is not permitted";
    }
    frame.unmap();
    ui->label->setPixmap(pixmapFrame);
}
