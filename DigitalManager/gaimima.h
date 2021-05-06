#ifndef GAIMIMA_H
#define GAIMIMA_H

#include <QWidget>

namespace Ui {
class Gaimima;
}

class Gaimima : public QWidget
{
    Q_OBJECT

public:
    explicit Gaimima(QWidget *parent = nullptr);
    ~Gaimima();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Gaimima *ui;
};

#endif // GAIMIMA_H
