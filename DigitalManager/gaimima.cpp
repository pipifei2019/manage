#include "gaimima.h"
#include "ui_gaimima.h"
#include"globle.h"
#include"shouye.h"
Gaimima::Gaimima(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gaimima)
{
    ui->setupUi(this);
    //ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

Gaimima::~Gaimima()
{
    delete ui;
}

void Gaimima::on_pushButton_2_clicked()
{
    list_all_daibanyewu.clear();

    Form *f=new Form;
    this->hide();
    f->show();
}

void Gaimima::on_pushButton_clicked()
{
    QString passw = ui->lineEdit->text();
    QString text1 = ui->lineEdit_2->text();
    QString text2 = ui->lineEdit_3->text();

    //qDebug()<<"用户名："<<username<<"密码:"<<password;
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL","localhost1");
        qDebug() << "hello world";
    }
    db.setHostName("localhost");
    db.setDatabaseName("management");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    QSqlQuery query(db);
    db.open();

    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open";

    bool T=true;

    query.exec("select * from user where name='"+username_qj+"'");
    query.next();
    //qDebug()<<query.value(0).toString()<<query.value(1).toString();
    int id1=query.value(0).toInt();
    if(query.value(1).toString()==username_qj&&query.value(2).toString()==passw)
    {
        if(text1==text2)
        {
            QString sql;

            sql = QString("UPDATE user "
                          "set id='%1',name='%2',password='%3'"
                         " where id = '%4' ").arg(id1).arg(username_qj).arg(text1).arg(id1);
            QSqlQuery query;
            bool ok = query.exec(sql);
            if(ok)
            {
                QMessageBox::information(this ,tr("提示") , tr("修改成功!"));
                T=false;
            }
            else
            {
                QMessageBox::information(this ,tr("提示") , tr("修改失败!"));
                T=false;
            }
        }
    }
    if(T)
    {
        QMessageBox::information(this ,tr("提示") , tr("请核对信息后重新修改!"));

    }

}
