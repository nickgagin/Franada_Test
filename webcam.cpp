#include "webcam.h"
#include "ui_webcam.h"

WebCam::WebCam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebCam)
{
    ui->setupUi(this);
    write_video = false;

    videoPlayer.open(0);
//    videoPlayer.open("D:\\Video Flight\\2014.06.06  08.21-09.30\\2014-06-06-08-20(h264).avi");

    if(!videoPlayer.isOpened())
    {
        this->setWindowTitle(trUtf8("Не могу открыть видео"));
        return;
    }

    qDebug() << "Frame width:" << videoPlayer.get(CV_CAP_PROP_FRAME_WIDTH);
    qDebug() << "Frame height:" << videoPlayer.get(CV_CAP_PROP_FRAME_HEIGHT);
//    videoPlayer.set(CV_CAP_PROP_FRAME_WIDTH,1920);
//    videoPlayer.set(CV_CAP_PROP_FRAME_HEIGHT,1080);

    videoPlayer.read(matOriginal);
//    if(matOriginal.empty()) return;
//    cv::imshow("try",matOriginal);


    tmrTimer = new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(TimerTick()));
    tmrTimer->start(40);
}

WebCam::~WebCam()
{
    delete ui;
}

void WebCam::TimerTick()
{
    videoPlayer.read(matOriginal);
    if(matOriginal.empty()) return;

    if(show_processed)
    {
        cv::cvtColor(matOriginal, matProcessed, CV_BGR2GRAY);
        //    gMat = new cv::gpu::GpuMat(matProcessed);
        //    gMat2 = new cv::gpu::GpuMat(matProcessed);
        cv::GaussianBlur(matProcessed, matProcessed, cv::Size(7,7), 1.5, 1.5);
        cv::Canny(matProcessed, matProcessed, 0, 30, 3);
        //    cv::gpu::Canny(*gMat, *gMat2, 0, 30,3);
        //    cv::imshow("edges", (cv::Mat) *gMat2);
        cv::imshow("edges", matProcessed);
    }

    if(write_video)
    {
        videoWriter << matOriginal;
    }
    cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
    cv::resize(matOriginal, matOutput, cv::Size(640,480));
    QImage qimgOriginal((uchar*)matOutput.data,matOutput.cols,matOutput.rows,matOutput.step,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qimgOriginal));
}

void WebCam::on_pushButton_clicked()
{
    if(ui->rb_bmp->isChecked())
        cv::imwrite("D:\\img.bmp",matOriginal);

    if(ui->rb_jpg->isChecked())
        cv::imwrite("D:\\img.jpg",matOriginal);

    if(ui->rb_png->isChecked())
        cv::imwrite("D:\\img.png",matOriginal);
}

void WebCam::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
        show_processed = true;
    else
        show_processed = false;
}


void WebCam::on_pushButton_writeVideo_clicked()
{
    switch(ui->comboBox->currentIndex())
    {
        case 0:
            videoWriter.open("D:\\test-video.avi",CV_FOURCC('X','2','6','4'),25,cv::Size(videoPlayer.get(CV_CAP_PROP_FRAME_WIDTH),videoPlayer.get(CV_CAP_PROP_FRAME_HEIGHT)));
        break;

        case 1:
            videoWriter.open("D:\\test-video.avi",CV_FOURCC('M','J','P','G'),25,cv::Size(videoPlayer.get(CV_CAP_PROP_FRAME_WIDTH),videoPlayer.get(CV_CAP_PROP_FRAME_HEIGHT)));
        break;

        case 2:
            videoWriter.open("D:\\test-video.avi",CV_FOURCC('M','P','4','2'),25,cv::Size(videoPlayer.get(CV_CAP_PROP_FRAME_WIDTH),videoPlayer.get(CV_CAP_PROP_FRAME_HEIGHT)));
        break;
    }
    if(videoWriter.isOpened())
        write_video = true;
}

void WebCam::on_pushButton_stopVideo_clicked()
{
    write_video = false;
    videoWriter.release();
}

void WebCam::on_rb_1080p_clicked()
{
    if(ui->rb_1080p->isChecked())
    {
        videoPlayer.set(CV_CAP_PROP_FRAME_WIDTH,1920);
        videoPlayer.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
    }
}

void WebCam::on_rb_vga_clicked()
{
    if(ui->rb_vga->isChecked())
    {
        videoPlayer.set(CV_CAP_PROP_FRAME_WIDTH,640);
        videoPlayer.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    }
}
