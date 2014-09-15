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
#include <QVideoFrame>


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


    QMediaPlayer* mediaPlayer;
    QAbstractVideoSurface* videoSurface;
    QVideoFrame* videoFrame;


public slots:
    void TimerTick();
};

#endif // VIDEOFORM_H
