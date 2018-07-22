#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Photowise");

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionBlur, &QAction::triggered, this, &MainWindow::blur);
    connect(ui->actionGrayscale, &QAction::triggered, this, &MainWindow::grayscale);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateImage()
{
    ui->image->setPixmap(QPixmap::fromImage(QImage(imageBuffer.data, imageBuffer.cols, imageBuffer.rows, (int)imageBuffer.step, activeFormat)));
}


void MainWindow::LoadImage(const QString &path)
{
    imageSource = cv::imread(path.toStdString());
    cv::cvtColor(imageSource, imageSource, cv::COLOR_BGR2RGB);
    imageBuffer = imageSource.clone();
    activeFormat = QImage::Format_RGB888;
    updateImage();
}


void MainWindow::open()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    if (!filepath.isEmpty())
        LoadImage(filepath);
}


void MainWindow::blur()
{
    cv::blur(imageBuffer, imageBuffer, cv::Size(5, 5));
    updateImage();
}


void MainWindow::grayscale()
{
    cv::cvtColor(imageBuffer, imageBuffer, cv::COLOR_RGB2GRAY);
    activeFormat = QImage::Format_Grayscale8;
    updateImage();
}
