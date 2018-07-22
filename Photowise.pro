#-------------------------------------------------
#
# Project created by QtCreator 2018-07-20T00:29:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Photowise
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
        DialogBlur.cpp

HEADERS  += MainWindow.h \
            DialogBlur.h

FORMS    += mainwindow.ui \
            dialog_blur.ui

CONFIG(debug, debug|release) {
    LIBS     += -L"D:\dev\opencv\own-build\lib\Debug" \
                -L"D:\dev\opencv\own-build\bin\Debug" \
                -lopencv_core341d \
                -lopencv_imgcodecs341d \
                -lopencv_imgproc341d \
                -lopencv_highgui341d
}

CONFIG(release, debug|release) {
    LIBS     += -L"D:\dev\opencv\own-build\lib\Release" \
                -L"D:\dev\opencv\own-build\bin\Release" \
                -lopencv_core341 \
                -lopencv_imgcodecs341 \
                -lopencv_imgproc341 \
                -lopencv_highgui341
}


INCLUDEPATH += "D:\dev\opencv\build\include"

DISTFILES +=
