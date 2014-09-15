#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libavutil/file.h>
#include <libavutil/avutil.h>
}


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


//    AVFormatContext *fmt_ctx;
//    AVCodecContext *video_dec_ctx, *audio_dec_ctx;
//    AVStream *video_stream, *audio_stream;
//    char *src_filename;
//    char *video_dst_filename;
//    char *audio_dst_filename;
//    FILE *video_dst_file;
//    FILE *audio_dst_file;

//    uint8_t *video_dst_data[4];
//    int     video_dst_linesize[4];
//    int     video_dst_bufsize;

//    int video_stream_idx, audio_stream_idx;
//    AVFrame *frame;
//    AVPacket pkt;
//    int video_frame_count;
//    int audio_frame_count;

//    int api_mode;

//    enum {
//        API_MODE_OLD                  = 0, /* old method, deprecated */
//        API_MODE_NEW_API_REF_COUNT    = 1, /* new method, using the frame reference counting */
//        API_MODE_NEW_API_NO_REF_COUNT = 2, /* new method, without reference counting */
//    };


//    int decode_packet(int *got_frame, int cached);
//    int open_codec_context(int *stream_idx, AVFormatContext *fmt_ctx, enum AVMediaType type);
//    int get_format_from_sample_fmt(const char **fmt, enum AVSampleFormat sample_fmt);


public slots:
    void TimerTick();
};

#endif // VIDEOFORM_H
