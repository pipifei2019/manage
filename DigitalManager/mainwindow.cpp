#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<globle.h>

#include "zhucejiemian.h"
#include"manager_c.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("Manager"));
    //connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(on_cancelButton_clicked()));
    //ui->hide();
    //connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(show2()));
    ui->Login_password->setEchoMode(QLineEdit::Password);
    ui->Login_username->setText("feifei");
    ui->Login_password->setText("123");
    ui->radioButton_2->setChecked(true);
    //setFixedSize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
   QString username = ui->Login_username->text();
   QString password = ui->Login_password->text();
   qDebug()<<"用户名："<<username<<"密码:"<<password;
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
   qDebug() << "hello world";

   db.open();
   if (!db.open())
       qDebug() << "Failed to connect to root mysql admin";
   else
       qDebug() << "open";

   if( ui->radioButton->isChecked())
   {
       QSqlQuery query(db);
       db.exec("SET NAMES 'UTF-8'");
       query.exec("select id,username,password from admin");
       bool T1=false;
       while(query.next())
       {
          QString user = query.value(1).toString();
          QString pass = query.value(2).toString();
          qDebug() << user << pass ;
          if(username.compare(user)==0&&password.compare(pass)==0)
          {
              password_qj=password;
              username_qj=username;
              T1=true;
              this->hide();
              Manager_c *s=new Manager_c;
              //emit sendData(username+"&"+password);
              s->show();
          }

       }

       if(T1==false)
           QMessageBox::information(this, "警告", "用户名或密码错误");
    }


   if( ui->radioButton_2->isChecked())
   {
        QSqlQuery query(db);
        db.exec("SET NAMES 'UTF-8'");
        query.exec("select id,name,password from user");
        bool T=false;
        while(query.next())
        {
            QString user = query.value(1).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0)
            {
                password_qj=password;
                username_qj=username;
                T=true;
                this->hide();
                Form* f=new Form;
                //emit sendData(username+"&"+password);
                f->show();

            }
        }

        if(T==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");
   }

}

void MainWindow::show2()
{
    this->hide();
}



void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}

void MainWindow::on_cancelButton_clicked()
{
    this->hide();
    zhucejiemian *zhuce=new zhucejiemian;
    zhuce->show();
}
