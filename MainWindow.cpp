#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "DialogBlur.h"

#include <QFileDialog>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Photowise");

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionBlurMore, &QAction::triggered, this, &MainWindow::blurMore);
    connect(ui->actionGrayscale, &QAction::triggered, this, &MainWindow::grayscale);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updatePreview()
{
    ui->image->setPixmap(QPixmap::fromImage(QImage(imageBuffer.data, imageBuffer.cols, imageBuffer.rows, (int)imageBuffer.step, activeFormat)));
}


void MainWindow::revertPreview()
{
    imageBuffer = imageSource.clone();
    updatePreview();
}


void MainWindow::updateChange()
{
    imageSource = imageBuffer.clone();
}


void MainWindow::LoadImage(const QString &path)
{
    imageSource = cv::imread(path.toStdString());
    cv::cvtColor(imageSource, imageSource, cv::COLOR_BGR2RGB);
    imageBuffer = imageSource.clone();
    activeFormat = QImage::Format_RGB888;
    updatePreview();
}


void MainWindow::open()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    if (!filepath.isEmpty())
    {
        LoadImage(filepath);
        ui->menuEffects->setEnabled(true);
    }
}


void MainWindow::blur(int size)
{
    cv::blur(imageSource, imageBuffer, cv::Size(size, size));
    updatePreview();
}


void MainWindow::blurMore()
{
    DialogBlur dialogBlur(this);
    if (dialogBlur.exec() == QDialog::Accepted)
        updateChange();
    else
        revertPreview();
}


void MainWindow::grayscale()
{
    cv::cvtColor(imageBuffer, imageBuffer, cv::COLOR_RGB2GRAY);
    activeFormat = QImage::Format_Grayscale8;
    updatePreview();
}
