#ifndef ZHUCEJIEMIAN_H
#define ZHUCEJIEMIAN_H
#include"mainwindow.h"

#include <QWidget>

namespace Ui {
class zhucejiemian;
}

class zhucejiemian : public QWidget
{
    Q_OBJECT

public:
    explicit zhucejiemian(QWidget *parent = nullptr);
    ~zhucejiemian();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zhucejiemian *ui;

};

#endif // ZHUCEJIEMIAN_H
