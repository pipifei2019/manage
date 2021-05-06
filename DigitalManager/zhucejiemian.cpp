#include "zhucejiemian.h"
#include "ui_zhucejiemian.h"
#include"globle.h"
#include<QMessageBox>

zhucejiemian::zhucejiemian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhucejiemian)
{
    ui->setupUi(this);
}

zhucejiemian::~zhucejiemian()
{
    delete ui;
}

void zhucejiemian::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QString passwordcp=ui->lineEdit_3->text();

    QSqlDatabase db;



    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("management");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    db.open();



    QSqlQuery query(db);
    //query=QSqlQuery::QSqlQuery(db);
    //query=QSqlQuery::QSqlQuery(db);
    db.exec("SET NAMES 'UTF-8'");
    int id2;
    query.exec("select id from user order by id desc ");
    query.next();
    id2= query.value(0).toInt()+1;

    qDebug()<<id2;




    query.exec("select name from user ");
    if(username=="" or password=="")
    {
        QMessageBox::information(this ,tr("警告") , tr("用户名或密码不能为空!"));
        return;
    }

    bool T=true;
    while(query.next())
    {
       QString un= query.value(0).toString();
       if(username==un)
       {
           QMessageBox::information(this ,tr("提示") , tr("该用户名已存在，不允许再次添加!"));
           T=false;
       }
    }
    if(T==true)
    {
        if(password==passwordcp)
        {
            if (!db.open())
                qDebug() << "Failed to connect to root mysql user";
            else
                qDebug() << "open";
            QString sql;
            sql = QString("insert into user (id,name,password)"
                           "VALUES ('%1', '%2' , '%3' )")
                    .arg(id2).arg(username).arg(password);

            bool ok = query.exec(sql);
            if(ok)
            {
               QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
            }
            else
            {
               QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
            }
        }
        else
        {
            QMessageBox::information(this ,tr("提示") , tr("请确认密码!"));
        }

   }

}

void zhucejiemian::on_pushButton_2_clicked()
{
    MainWindow *w=new MainWindow;
    this->hide();
    w->show();

}
