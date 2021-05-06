#ifndef QUXIAOYEWU_H
#define QUXIAOYEWU_H

#include <QWidget>

namespace Ui {
class Quxiaoyewu;
}

class Quxiaoyewu : public QWidget
{
    Q_OBJECT

public:
    explicit Quxiaoyewu(QWidget *parent = nullptr);
    ~Quxiaoyewu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Quxiaoyewu *ui;
};

#endif // QUXIAOYEWU_H
