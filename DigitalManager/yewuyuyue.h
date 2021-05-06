#ifndef YEWUYUYUE_H
#define YEWUYUYUE_H

#include <QWidget>

namespace Ui {
class Yewuyuyue;
}

class Yewuyuyue : public QWidget
{
    Q_OBJECT

public:
    explicit Yewuyuyue(QWidget *parent = nullptr);
    ~Yewuyuyue();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Yewuyuyue *ui;
};

#endif // YEWUYUYUE_H
