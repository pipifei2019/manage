#include "yuyueguanli.h"
#include "ui_yuyueguanli.h"
#include"manager_c.h"
#include"globle.h"

Yuyueguanli::Yuyueguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yuyueguanli)
{
    ui->setupUi(this);

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

Yuyueguanli::~Yuyueguanli()
{
    delete ui;
}

void Yuyueguanli::on_pushButton_clicked()
{
    list_all_daibanyewu.clear();
    ui->tableWidget->clear();

    Manager_c *m=new Manager_c;
    this->hide();
    m->show();
}

void Yuyueguanli::on_pushButton_1_clicked()
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

void Yuyueguanli::on_pushButton_2_clicked()
{
    QString yewuid = ui->lineEdit->text();
    if(yewuid=="")
    {
        QMessageBox::information(this ,tr("提示") , tr("请输入业务编号后再删除!"));
        return;

    }

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
    QString sql;
    sql = QString("DELETE FROM daibanyewu "
                 " where yewuid = '%1' ").arg(yewuid);
    //QSqlQuery query;
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
    if(T)
    {
        QMessageBox::information(this ,tr("提示") , tr("取消失败!"));

    }

}
