#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

// For Video Functionality
#include <QMediaPlayer>
#include <QAbstractVideoSurface>
#include <QAbstractVideoBuffer>
#include <QVideoWidget>
#include <QVideoFrame>
#include <QVideoProbe>
#include <QMediaContent>
#include <QMediaResource>


namespace Ui {


class VideoForm;
}

class VideoForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoForm(QWidget *parent = 0);
    ~VideoForm();

private:
    Ui::VideoForm *ui;

    QImage qimgOriginal;
    QTimer* tmrTimer;
    QTime check;

    char *filename;


    QMediaPlayer* player;
    QVideoWidget* videoWidget;
    QVideoFrame* videoFrame;
    QVideoProbe* videoProbe;
//    QAbstractVideoSurface* videoSurface;



public slots:
    void TimerTick();
    void showVideoFrame(QVideoFrame frame);
};


#endif // VIDEOFORM_H
