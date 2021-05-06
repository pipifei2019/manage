#ifndef ZHUNJIARENYUAN_H
#define ZHUNJIARENYUAN_H

#include <QWidget>

namespace Ui {
class Zhunjiarenyuan;
}

class Zhunjiarenyuan : public QWidget
{
    Q_OBJECT

public:
    explicit Zhunjiarenyuan(QWidget *parent = nullptr);
    ~Zhunjiarenyuan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Zhunjiarenyuan *ui;
};

#endif // ZHUNJIARENYUAN_H
