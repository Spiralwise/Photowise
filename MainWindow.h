#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    cv::Mat imageSource;
    cv::Mat imageBuffer;
    QImage::Format activeFormat;

    void updatePreview();
    void revertPreview();
    void updateChange();

    void LoadImage(const QString &path);

public:
    void blur(int);

private slots:
    void open();
    void blurMore();
    void grayscale();
};

#endif // MAINWINDOW_H
