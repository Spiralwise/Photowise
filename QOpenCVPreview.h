#ifndef QOPENCVPREVIEW_H
#define QOPENCVPREVIEW_H

#include "QLabel"
#include <opencv2/core.hpp>


class QOpenCVPreview : public QLabel
{
    Q_OBJECT

    cv::Mat imageSource;
    cv::Mat imageBuffer;
    QImage::Format activeFormat;

    void updatePreview();

public:
    QOpenCVPreview(QWidget *parent);

    void LoadImage(const QString &path);
    void CommitChange();
    void DiscardChange();

    void DrawCircle(const cv::Point);
    void Blur(int);
    void Grayscale();
};

#endif // QOPENCVPREVIEW_H
