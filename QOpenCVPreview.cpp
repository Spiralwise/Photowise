#include "QOpenCVPreview.h"

#include <QInputEvent>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


QOpenCVPreview::QOpenCVPreview(QWidget *parent) : parent(parent)
{
    setMouseTracking(true);
}


void QOpenCVPreview::updatePreview()
{
    setPixmap(QPixmap::fromImage(QImage(imageBuffer.data, imageBuffer.cols, imageBuffer.rows, (int)imageBuffer.step, activeFormat)));
}


void QOpenCVPreview::mouseMoveEvent(QMouseEvent *event)
{
    DrawCircle(cv::Point(event->x(), event->y()));
}


void QOpenCVPreview::DiscardChange()
{
    imageBuffer = imageSource.clone();
    updatePreview();
}


void QOpenCVPreview::CommitChange()
{
    imageSource = imageBuffer.clone();
}


void QOpenCVPreview::LoadImage(const QString &path)
{
    imageSource = cv::imread(path.toStdString());
    cv::cvtColor(imageSource, imageSource, cv::COLOR_BGR2RGB);
    imageBuffer = imageSource.clone();
    activeFormat = QImage::Format_RGB888;
    DrawCircle(cv::Point(150, 150));
}


void QOpenCVPreview::DrawCircle(const cv::Point position)
{
    cv::circle(imageBuffer, position, 20, cv::Scalar(255, 0, 0), -1);
    updatePreview();
}


void QOpenCVPreview::Blur(int size)
{
    cv::blur(imageSource, imageBuffer, cv::Size(size, size));
    updatePreview();
}


void QOpenCVPreview::Grayscale()
{
    cv::cvtColor(imageBuffer, imageBuffer, cv::COLOR_RGB2GRAY);
    activeFormat = QImage::Format_Grayscale8;
    updatePreview();
}
