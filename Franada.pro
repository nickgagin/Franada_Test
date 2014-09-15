#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T14:07:17
#
#-------------------------------------------------

QT       += core gui multimedia

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



LIBS+=-LD://FFMPEG//lib \
    -llibavutil     \
    -llibavformat   \
    -llibavcodec    \
    -llibavdevice   \
    -llibavfilter   \
    -llibswresample \
    -llibswscale

INCLUDEPATH += C://opencv//qt_build//include

INCLUDEPATH += D://FFMPEG//include


## Requied for some C99 defines
DEFINES += __STDC_CONSTANT_MACROS
