#ifndef ADDDRIVER_H
#define ADDDRIVER_H

#include <QWidget>

namespace Ui {
class Adddriver;
}

class Adddriver : public QWidget
{
    Q_OBJECT

public:
    explicit Adddriver(QWidget *parent = nullptr);
    ~Adddriver();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Adddriver *ui;
};

#endif // ADDDRIVER_H
