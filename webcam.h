#ifndef WEBCAM_H
#define WEBCAM_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <opencv2/opencv.hpp>

#include <opencv2/gpu/gpu.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class WebCam;
}

class WebCam : public QWidget
{
    Q_OBJECT

public:
    explicit WebCam(QWidget *parent = 0);
    ~WebCam();

private:
    Ui::WebCam *ui;
    cv::VideoCapture videoPlayer;
    cv::VideoWriter videoWriter;
    cv::Mat matOriginal,
            matProcessed,
            matOutput;
//    cv::gpu::GpuMat* gMat;
//    cv::gpu::GpuMat* gMat2;
    QImage qimgOriginal;
    QTimer* tmrTimer;

    bool gpu_use,
         show_processed,
         write_video;

public slots:
    void TimerTick();
private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked();

    void on_pushButton_writeVideo_clicked();
    void on_pushButton_stopVideo_clicked();
    void on_rb_1080p_clicked();
    void on_rb_vga_clicked();
};

#endif // WEBCAM_H
