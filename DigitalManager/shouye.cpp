#include "shouye.h"
#include "ui_shouye.h"
#include"globle.h"
#include"yewuyuyue.h"
#include"quxiaoyewu.h"
#include"gaimima.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QLabel *lab= ui->label;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_qj+"登录！");


    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("management");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'utf-8'");
    query.exec("select time,yewuid,request,project,type,addr,beizhu from daibanyewu order by time");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString time = query.value(0).toString();
        QString yewuid = query.value(1).toString();
        QString request = query.value(2).toString();
        QString project =query.value(3).toString();
        QString type=query.value(4).toString();
        QString addr=query.value(5).toString();
        QString beizhu=query.value(6).toString();

        q<<time<<yewuid<<request<<project<<type<<addr<<beizhu;
        list_all_daibanyewu.append(q);
    }

    //for(int i=0;i<list_all_daibanyewu.size();i++)
    //{
    //    qDebug()<<list_all_daibanyewu[i];

    //}

    for(int i=0;i<list_all_daibanyewu.size();i++)
    {

        int row = ui->tableWidget->rowCount();

        qDebug()<<row;
        ui->tableWidget->insertRow(row);
        QStringList rowdata=list_all_daibanyewu[i].toStringList();

        for(int j  = 0 ; j <rowdata .size() ; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row , j , item);
        }

    }
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_7_clicked()
{
    list_all_daibanyewu.clear();
    ui->tableWidget->clear();
    MainWindow *w=new MainWindow;
    this->hide();
    w->show();
}

void Form::on_pushButton_8_clicked()
{
    list_all_daibanyewu.clear();
    //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);

    QString yewuid_c=ui->lineEdit->text();


    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("management");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'utf-8'");
    query.exec("select time,yewuid,request,project,type,addr,beizhu from daibanyewu  where yewuid='"+yewuid_c+"' order by time");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString time = query.value(0).toString();
        QString yewuid = query.value(1).toString();
        QString request = query.value(2).toString();
        QString project =query.value(3).toString();
        QString type=query.value(4).toString();
        QString addr=query.value(5).toString();
        QString beizhu=query.value(6).toString();

        q<<time<<yewuid<<request<<project<<type<<addr<<beizhu;
        list_all_daibanyewu.append(q);
    }

    //for(int i=0;i<list_all_daibanyewu.size();i++)
    //{
    //    qDebug()<<list_all_daibanyewu[i];

    //}

    for(int i=0;i<list_all_daibanyewu.size();i++)
    {

        int row = ui->tableWidget->rowCount();
        qDebug()<<row;
        ui->tableWidget->insertRow(row);
        QStringList rowdata=list_all_daibanyewu[i].toStringList();

        for(int j  = 0 ; j <rowdata .size() ; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row , j , item);
        }

    }

}

void Form::on_pushButton_2_clicked()
{
    Yewuyuyue *y=new Yewuyuyue;
    this->hide();
    y->show();
}

void Form::on_pushButton_3_clicked()
{
    Quxiaoyewu *q=new Quxiaoyewu;
    this->hide();
    q->show();
}

void Form::on_pushButton_clicked()
{
    Gaimima *g=new Gaimima;
    this->hide();
    g->show();
}
