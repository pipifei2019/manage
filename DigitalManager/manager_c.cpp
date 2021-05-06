#include "manager_c.h"
#include "ui_manager_c.h"
#include <QWidget>
#include"mainwindow.h"
#include"globle.h"
#include"zhunjiarenyuan.h"
#include"yuyueguanli.h"

Manager_c::Manager_c(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manager_c)
{
    ui->setupUi(this);

    QLabel *lab= ui->label;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_qj+"登录！");
}

Manager_c::~Manager_c()
{
    delete ui;
}

void Manager_c::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow;
    this->hide();
    w->show();
}

void Manager_c::on_pushButton_2_clicked()
{
    Zhunjiarenyuan *z=new Zhunjiarenyuan;
    this->hide();
    z->show();
}

void Manager_c::on_pushButton_3_clicked()
{
    Yuyueguanli *y =new Yuyueguanli;
    this->hide();
    y->show();
}
