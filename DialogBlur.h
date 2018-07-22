#ifndef DIALOGBLUR_H
#define DIALOGBLUR_H

#include "MainWindow.h"
#include "QOpenCVPreview.h"

#include <QDialog>
#include <opencv2/core.hpp>


namespace Ui {
    class DialogBlur;
}

class DialogBlur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBlur(QOpenCVPreview *openCVPreview, MainWindow *parent = 0);
    ~DialogBlur();

private:
    MainWindow *window;
    QOpenCVPreview *preview;
    Ui::DialogBlur *ui;

private slots:
    void setBlurSize(int);
};

#endif // DIALOGBLUR_H
