#ifndef MANAGER_C_H
#define MANAGER_C_H

#include <QWidget>

namespace Ui {
class Manager_c;
}

class Manager_c : public QWidget
{
    Q_OBJECT

public:
    explicit Manager_c(QWidget *parent = nullptr);
    ~Manager_c();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Manager_c *ui;
};

#endif // MANAGER_C_H
