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

    //cv::blur(image, image, cv::Size(5, 20));
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::LoadImage(const QString &path)
{
    imageSource = cv::imread(path.toStdString());
    cv::cvtColor(imageSource, imageSource, cv::COLOR_BGR2RGB);
    ui->image->setPixmap(QPixmap::fromImage(QImage(imageSource.data, imageSource.cols, imageSource.rows, imageSource.step, QImage::Format_RGB888)));
}


bool MainWindow::open()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    if (!filepath.isEmpty())
        LoadImage(filepath);
    return true;
}
