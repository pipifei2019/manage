#ifndef SHOUYE_H
#define SHOUYE_H

#include <QWidget>
#include"mainwindow.h"
#include"globle.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // SHOUYE_H
