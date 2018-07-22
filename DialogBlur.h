#ifndef DIALOGBLUR_H
#define DIALOGBLUR_H
#include <QDialog>
#include <opencv2/core.hpp>
#include "MainWindow.h"


namespace Ui {
    class DialogBlur;
}

class DialogBlur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBlur(MainWindow *parent = 0);
    ~DialogBlur();

private:
    MainWindow *window;
    Ui::DialogBlur *ui;

private slots:
    void setBlurSize(int);
};

#endif // DIALOGBLUR_H
