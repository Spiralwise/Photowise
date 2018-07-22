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
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::LoadImage(const QString &path)
{
    imageSource = cv::imread(path.toStdString());
    cv::cvtColor(imageSource, imageSource, cv::COLOR_BGR2RGB);
    imageBuffer = imageSource.clone();
    ui->image->setPixmap(QPixmap::fromImage(QImage(imageBuffer.data, imageBuffer.cols, imageBuffer.rows, (int)imageBuffer.step, QImage::Format_RGB888)));
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
    ui->image->setPixmap(QPixmap::fromImage(QImage(imageBuffer.data, imageBuffer.cols, imageBuffer.rows, (int)imageBuffer.step, QImage::Format_RGB888)));
}
