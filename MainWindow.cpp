#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "DialogBlur.h"

#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Photowise");

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionBlurMore, &QAction::triggered, this, &MainWindow::dialogBlur);
    connect(ui->actionGrayscale, &QAction::triggered, this, &MainWindow::applyGrayscale);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::open()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    if (!filepath.isEmpty())
    {
        ui->image->LoadImage(filepath);
        ui->menuEffects->setEnabled(true);
    }
}


void MainWindow::applyGrayscale()
{
    ui->image->Grayscale();
    ui->image->CommitChange();
}


void MainWindow::dialogBlur()
{
    DialogBlur dialogBlur(ui->image, this);
    if (dialogBlur.exec() == QDialog::Accepted)
        ui->image->CommitChange();
    else
        ui->image->DiscardChange();
}
