#include "videoform.h"
#include "ui_videoform.h"

VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm)
{
    ui->setupUi(this);

//    *fmt_ctx = NULL;
//    *video_dec_ctx = NULL;
//    *video_stream = NULL;
//    *audio_stream = NULL;
//    *src_filename = NULL;
//    *video_dst_filename = NULL;
//    *audio_dst_filename = NULL;
//    *video_dst_file = NULL;
//    *audio_dst_file = NULL;

//    *video_dst_data[4] = {NULL};
//    video_stream_idx = -1;
//    audio_stream_idx = -1;
////    *frame = NULL;
//    video_frame_count = 0;
//    audio_frame_count = 0;

//    api_mode = API_MODE_OLD;




//    int ret = 0, got_frame;
////    QString filename = "D:\\2014-06-06-08-20(h264).avi";
//    *src_filename = 'D:\\2014-06-06-08-20(h264).avi';
//    *video_dst_filename = 'D:\\2014-06-06-08-20(h264)_video.avi';
//    *audio_dst_filename = 'D:\\2014-06-06-08-20(h264)_audio.avi';

//    // Register all formats and codecs
//    av_register_all();

//    // Open video file
//    if(avformat_open_input(&fmt_ctx, src_filename, NULL, NULL) < 0)
//        qDebug() << "Couldn't open file";

//    if (avformat_find_stream_info(fmt_ctx, NULL) < 0)
//        qDebug() << "Could not find stream information";

//    if (open_codec_context(&video_stream_idx, fmt_ctx, AVMEDIA_TYPE_VIDEO) >= 0) {
//            video_stream = fmt_ctx->streams[video_stream_idx];
//            video_dec_ctx = video_stream->codec;
//            video_dst_file = fopen(video_dst_filename, "wb");
//            if (!video_dst_file) {
//                qDebug()<< "Could not open destination videofile";
//                goto end;
//            }

//            /* allocate image where the decoded image will be put */
//            ret = av_image_alloc(video_dst_data, video_dst_linesize, video_dec_ctx->width, video_dec_ctx->height, video_dec_ctx->pix_fmt, 1);
//            if (ret < 0) {
//                qDebug() << "Could not allocate raw video buffer";
//                goto end;
//            }
//            video_dst_bufsize = ret;
//    }

//    if (open_codec_context(&audio_stream_idx, fmt_ctx, AVMEDIA_TYPE_AUDIO) >= 0)
//    {
//        audio_stream = fmt_ctx->streams[audio_stream_idx];
//        audio_dec_ctx = audio_stream->codec;
//        audio_dst_file = fopen(audio_dst_filename, "wb");
//        if (!audio_dst_file) {
//            qDebug() << "Could not open destination audio file";
//            ret = 1;
//                goto end;
//        }
//    }

//    /* dump input information to stderr */
//    av_dump_format(fmt_ctx, 0, src_filename, 0);

//    if (!audio_stream && !video_stream) {
//        qDebug() << "Could not find audio or video stream in the input, aborting";
//        ret = 1;
//        goto end;
//    }

//    /* When using the new API, you need to use the libavutil/frame.h API, while
//    * the classic frame management is available in libavcodec */
//    if (api_mode == API_MODE_OLD)
//        frame = avcodec_alloc_frame();
//    else
//        frame = av_frame_alloc();
//    if (!frame) {
//        qDebug() << "Could not allocate frame";
//        ret = AVERROR(ENOMEM);
//        goto end;
//    }

//    /* initialize packet, set data to NULL, let the demuxer fill it */
//    av_init_packet(&pkt);
//    pkt.data = NULL;
//    pkt.size = 0;
//    if (video_stream)
//        qDebug() << "Demuxing video from file source_file into video_dst_filename";
//    if (audio_stream)
//        qDebug() << "Demuxing audio from file source_file into audio_dst_filename";
//    /* read frames from the file */
//    while (av_read_frame(fmt_ctx, &pkt) >= 0) {
//        AVPacket orig_pkt = pkt;
//        do {
//            ret = decode_packet(&got_frame, 0);
//            if (ret < 0)
//                break;
//            pkt.data += ret;
//            pkt.size -= ret;
//        } while (pkt.size > 0);
//        av_free_packet(&orig_pkt);
//   }

//        /* flush cached frames */
//        pkt.data = NULL;
//        pkt.size = 0;
//        do {
//            decode_packet(&got_frame, 1);
//        } while (got_frame);

//        qDebug() << "Demuxing succeeded";

////        if (video_stream) {
////            qDebug() << "Play the output video file with the command"
////                   "ffplay -f rawvideo -pix_fmt %s -video_size %dx%d %s\n",
////                   av_get_pix_fmt_name(video_dec_ctx->pix_fmt), video_dec_ctx->width, video_dec_ctx->height,
////                   video_dst_filename);
////        }

////        if (audio_stream) {
////            enum AVSampleFormat sfmt = audio_dec_ctx->sample_fmt;
////            int n_channels = audio_dec_ctx->channels;
////            const char *fmt;

////            if (av_sample_fmt_is_planar(sfmt)) {
////                const char *packed = av_get_sample_fmt_name(sfmt);
////                printf("Warning: the sample format the decoder produced is planar "
////                       "(%s). This example will output the first channel only.\n",
////                       packed ? packed : "?");
////                sfmt = av_get_packed_sample_fmt(sfmt);
////                n_channels = 1;
////            }

////            if ((ret = get_format_from_sample_fmt(&fmt, sfmt)) < 0)
////                goto end;

////            printf("Play the output audio file with the command:\n"
////                   "ffplay -f %s -ac %d -ar %d %s\n",
////                   fmt, n_channels, audio_dec_ctx->sample_rate,
////                   audio_dst_filename);
////        }

//    end:
//        avcodec_close(video_dec_ctx);
//        avcodec_close(audio_dec_ctx);
//        avformat_close_input(&fmt_ctx);
//        if (video_dst_file)
//            fclose(video_dst_file);
//        if (audio_dst_file)
//            fclose(audio_dst_file);
//        if (api_mode == API_MODE_OLD)
//            avcodec_free_frame(&frame);
//        else
//            av_frame_free(&frame);
//        av_free(video_dst_data[0]);

////        return ret < 0;
}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::TimerTick()
{
}

//int VideoForm::decode_packet(int *got_frame, int cached)
//{
//    int ret = 0;
//    int decoded = pkt.size;

//    *got_frame = 0;

//    if (pkt.stream_index == video_stream_idx) {
//        /* decode video frame */
//        ret = avcodec_decode_video2(video_dec_ctx, frame, got_frame, &pkt);
//        if (ret < 0) {
//            qDebug() << "Error decoding video frame";
//            return ret;
//        }

//        if (*got_frame) {
//            /* copy decoded frame to destination buffer:
//            * this is required since rawvideo expects non aligned data */
//            av_image_copy(video_dst_data, video_dst_linesize,
//                                (const uint8_t **)(frame->data), frame->linesize,
//                                video_dec_ctx->pix_fmt, video_dec_ctx->width, video_dec_ctx->height);

//            /* write to rawvideo file */
//            fwrite(video_dst_data[0], 1, video_dst_bufsize, video_dst_file);
//        }
//    }
//    else if (pkt.stream_index == audio_stream_idx) {
//        /* decode audio frame */
//        ret = avcodec_decode_audio4(audio_dec_ctx, frame, got_frame, &pkt);
//        if (ret < 0) {
//            qDebug() << "Error decoding audio frame";
//                return ret;
//        }
//        /* Some audio decoders decode only part of the packet, and have to be
//         * called again with the remainder of the packet data.
//         * Sample: fate-suite/lossless-audio/luckynight-partial.shn
//         * Also, some decoders might over-read the packet. */
//        decoded = FFMIN(ret, pkt.size);

//        if (*got_frame)
//        {
//            size_t unpadded_linesize = frame->nb_samples * av_get_bytes_per_sample(frame->format);

//            /* Write the raw audio data samples of the first plane. This works
//             * fine for packed formats (e.g. AV_SAMPLE_FMT_S16). However,
//             * most audio decoders output planar audio, which uses a separate
//             * plane of audio samples for each channel (e.g. AV_SAMPLE_FMT_S16P).
//             * In other words, this code will write only the first audio channel
//             * in these cases.
//             * You should use libswresample or libavfilter to convert the frame
//             * to packed data. */
//             fwrite(frame->extended_data[0], 1, unpadded_linesize, audio_dst_file);
//         }
//    }

//    /* If we use the new API with reference counting, we own the data and need
//     * to de-reference it when we don't use it anymore */
//    if (*got_frame && api_mode == API_MODE_NEW_API_REF_COUNT)
//        av_frame_unref(frame);

//    return decoded;
//    if (pkt.stream_index == video_stream_idx) {
//        /* decode video frame */
//        ret = avcodec_decode_video2(video_dec_ctx, frame, got_frame, &pkt);
//        if (ret < 0) {
//            qDebug() << "Error decoding video frame";
//            return ret;
//        }

//        if (*got_frame) {
//            /* copy decoded frame to destination buffer:
//            * this is required since rawvideo expects non aligned data */
//            av_image_copy(video_dst_data, video_dst_linesize,
//                (const uint8_t **)(frame->data), frame->linesize,
//                 video_dec_ctx->pix_fmt, video_dec_ctx->width, video_dec_ctx->height);

//            /* write to rawvideo file */
//                fwrite(video_dst_data[0], 1, video_dst_bufsize, video_dst_file);
//        }
//     }
//    else if (pkt.stream_index == audio_stream_idx) {
//        /* decode audio frame */
//        ret = avcodec_decode_audio4(audio_dec_ctx, frame, got_frame, &pkt);
//        if (ret < 0) {
//            qDebug() << "Error decoding audio frame";
//                return ret;
//        }
//        /* Some audio decoders decode only part of the packet, and have to be
//         * called again with the remainder of the packet data.
//         * Sample: fate-suite/lossless-audio/luckynight-partial.shn
//         * Also, some decoders might over-read the packet. */
//        decoded = FFMIN(ret, pkt.size);

//        if (*got_frame) {
//            size_t unpadded_linesize = frame->nb_samples * av_get_bytes_per_sample(frame->format);

//            /* Write the raw audio data samples of the first plane. This works
//             * fine for packed formats (e.g. AV_SAMPLE_FMT_S16). However,
//             * most audio decoders output planar audio, which uses a separate
//             * plane of audio samples for each channel (e.g. AV_SAMPLE_FMT_S16P).
//             * In other words, this code will write only the first audio channel
//             * in these cases.
//             * You should use libswresample or libavfilter to convert the frame
//             * to packed data. */
//             fwrite(frame->extended_data[0], 1, unpadded_linesize, audio_dst_file);
//        }
//    }

//    /* If we use the new API with reference counting, we own the data and need
//     * to de-reference it when we don't use it anymore */
//    if (*got_frame && api_mode == API_MODE_NEW_API_REF_COUNT)
//        av_frame_unref(frame);

//    return decoded;
//}

//int VideoForm::open_codec_context(int *stream_idx, AVFormatContext *fmt_ctx, AVMediaType type)
//{
//    int ret;
//    AVStream *st;
//    AVCodecContext *dec_ctx = NULL;
//    AVCodec *dec = NULL;
//    AVDictionary *opts = NULL;

//    ret = av_find_best_stream(fmt_ctx, type, -1, -1, NULL, 0);
//    if (ret < 0) {
//        qDebug() << "Could not find stream in input file";
//        return ret;
//    }
//    else {
//        *stream_idx = ret;
//        st = fmt_ctx->streams[*stream_idx];

//        /* find decoder for the stream */
//        dec_ctx = st->codec;
//        dec = avcodec_find_decoder(dec_ctx->codec_id);
//        if (!dec) {
//            qDebug() << "Failed to find codec";
//            return AVERROR(EINVAL);
//        }

//        /* Init the decoders, with or without reference counting */
//        if (api_mode == API_MODE_NEW_API_REF_COUNT)
//            av_dict_set(&opts, "refcounted_frames", "1", 0);
//        if ((ret = avcodec_open2(dec_ctx, dec, &opts)) < 0) {
//            qDebug() << "Failed to open codec";
//            return ret;
//        }
//    }

//    return 0;
//}

//int VideoForm::get_format_from_sample_fmt(const char **fmt, AVSampleFormat sample_fmt)
//{
//    int i;
//    struct sample_fmt_entry {
//        enum AVSampleFormat sample_fmt; const char *fmt_be, *fmt_le;
//    } sample_fmt_entries[] = {
//        { AV_SAMPLE_FMT_U8,  "u8",    "u8"    },
//        { AV_SAMPLE_FMT_S16, "s16be", "s16le" },
//        { AV_SAMPLE_FMT_S32, "s32be", "s32le" },
//        { AV_SAMPLE_FMT_FLT, "f32be", "f32le" },
//        { AV_SAMPLE_FMT_DBL, "f64be", "f64le" },
//    };
//    *fmt = NULL;

//    for (i = 0; i < FF_ARRAY_ELEMS(sample_fmt_entries); i++) {
//        struct sample_fmt_entry *entry = &sample_fmt_entries[i];
//        if (sample_fmt == entry->sample_fmt) {
//            *fmt = AV_NE(entry->fmt_be, entry->fmt_le);
//            return 0;
//        }
//    }

//    qDebug() << "sample format is not supported as output format";
//    return -1;
//}
