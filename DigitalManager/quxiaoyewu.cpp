#include "quxiaoyewu.h"
#include "ui_quxiaoyewu.h"
#include"globle.h"
#include"shouye.h"

Quxiaoyewu::Quxiaoyewu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quxiaoyewu)
{
    ui->setupUi(this);
}

Quxiaoyewu::~Quxiaoyewu()
{
    delete ui;
}

void Quxiaoyewu::on_pushButton_2_clicked()
{
    list_all_daibanyewu.clear();

    Form *f=new Form;
    this->hide();
    f->show();
}

void Quxiaoyewu::on_pushButton_clicked()
{
    QString yewuid = ui->lineEd->text();

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

    query.exec("select yewuid,beizhu from daibanyewu where beizhu='"+username_qj+"'");
    query.next();
    qDebug()<<query.value(0).toString()<<query.value(1).toString();
    if(query.value(0).toString()==yewuid&&query.value(1).toString()==username_qj)
    {
        qDebug()<<"helloworld";
        QString sql;
        sql = QString("DELETE FROM daibanyewu "
                     " where yewuid = '%1' ").arg(yewuid);
        QSqlQuery query;
        bool ok = query.exec(sql);
        if(ok)
        {
            QMessageBox::information(this ,tr("提示") , tr("取消成功!"));
            T=false;
        }
        else
        {
            QMessageBox::information(this ,tr("提示") , tr("请核对信息后重新取消!"));
            T=false;
        }
    }
    if(T)
    {
        QMessageBox::information(this ,tr("提示") , tr("取消失败!"));

    }


}
