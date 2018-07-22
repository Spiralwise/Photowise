#include "DialogBlur.h"
#include "ui_dialog_blur.h"


DialogBlur::DialogBlur(QOpenCVPreview *openCVPreview, MainWindow *parent) :
    QDialog(parent),
    window(parent),
    preview(openCVPreview),
    ui(new Ui::DialogBlur)
{
    ui->setupUi(this);
    this->setWindowTitle("Blur");
    this->setModal(true);
    ui->blurSlider->setValue(5);
    ui->blurSpinBox->setValue(5);

    setBlurSize(5);
    connect(ui->blurSlider, &QSlider::valueChanged, this, &DialogBlur::setBlurSize);
   // connect(ui->blurSpinBox, &QSpinBox::valueChanged, this, &DialogBlur::setBlurSize);
}


DialogBlur::~DialogBlur()
{
    delete ui;
}

void DialogBlur::setBlurSize(int value)
{
    if (value)
        preview->Blur(value);
}
