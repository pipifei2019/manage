#ifndef YUYUEGUANLI_H
#define YUYUEGUANLI_H

#include <QWidget>

namespace Ui {
class Yuyueguanli;
}

class Yuyueguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Yuyueguanli(QWidget *parent = nullptr);
    ~Yuyueguanli();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Yuyueguanli *ui;
};

#endif // YUYUEGUANLI_H
