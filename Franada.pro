#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T14:07:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Franada
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    projectdialog.cpp \
    videoform.cpp \
    syncprojectclass.cpp \
    webcam.cpp

HEADERS  += mainwindow.h \
    projectdialog.h \
    videoform.h \
    syncprojectclass.h \
    webcam.h

FORMS    += mainwindow.ui \
    projectdialog.ui \
    videoform.ui \
    webcam.ui

RESOURCES += \
    franada.qrc

LIBS+=-LC://opencv//qt_build2//bin// \
    -lopencv_core248 \
    -lopencv_highgui248 \
    -lopencv_imgproc248 \
    -lopencv_video248 \
    -lopencv_gpu248

#LIBS+=-LC://opencv//ocv244_build//x86//mingw//lib// \
#    -lopencv_core244 \
#    -lopencv_highgui244 \
#    -lopencv_imgproc244 \
#    -lopencv_video244 \
#    -lopencv_gpu244

LIBS+=-LD://FFMPEG//lib \
    -llibavutil     \
    -llibavformat   \
    -llibavcodec    \
    -llibavdevice   \
    -llibavfilter   \
    -llibswresample \
    -llibswscale

INCLUDEPATH+=C://opencv//qt_build//include
#INCLUDEPATH += C://opencv//ocv244_build//include

INCLUDEPATH += D://FFMPEG//include



## Set FFMPEG_LIBRARY_PATH to point to the directory containing the FFmpeg import libraries (if needed - typically for Windows), i.e. the dll.a files
#FFMPEG_LIBRARY_PATH = ffmpeg/lib

## Set FFMPEG_INCLUDE_PATH to point to the directory containing the FFMPEG includes (if needed - typically for Windows)
#FFMPEG_INCLUDE_PATH = ffmpeg

#LIBS += -L$$FFMPEG_LIBRARY_PATH

#LIBS += -lavutil \
#    -lavcodec \
#    -lavformat \
#    -lswscale



#INCLUDEPATH += $$FFMPEG_INCLUDE_PATH

## Requied for some C99 defines
DEFINES += __STDC_CONSTANT_MACROS
