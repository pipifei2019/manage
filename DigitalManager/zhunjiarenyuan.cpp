#include "zhunjiarenyuan.h"
#include "ui_zhunjiarenyuan.h"
#include"manager_c.h"
#include <QWidget>
#include"mainwindow.h"
#include"globle.h"
#include"adddriver.h"
Zhunjiarenyuan::Zhunjiarenyuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zhunjiarenyuan)
{
    ui->setupUi(this);


    //显示准驾人员信息
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
    query.exec("select name,danwei,telephone,yanzhengma,chexing,zhunjiaid,zhunjiadengji,state from zhunjiadriver");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString name = query.value(0).toString();
        QString danwei = query.value(1).toString();
        QString telephone = query.value(2).toString();
        QString yanzhengma =query.value(3).toString();
        QString chexing=query.value(4).toString();
        QString zhunjiaid=query.value(5).toString();
        QString zhunjiadengji=query.value(6).toString();
        QString state=query.value(7).toString();

        q<<name<<danwei<<telephone<<yanzhengma<<chexing<<zhunjiaid<<zhunjiadengji<<state;
        list_all_zhunjiarenyuan.append(q);
    }



    for(int i=0;i<list_all_zhunjiarenyuan.size();i++)
    {

        int row = ui->tableWidget->rowCount();

        qDebug()<<row;
        ui->tableWidget->insertRow(row);
        QStringList rowdata=list_all_zhunjiarenyuan[i].toStringList();

        for(int j  = 0 ; j <rowdata .size() ; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row , j , item);
        }

    }

}

Zhunjiarenyuan::~Zhunjiarenyuan()
{
    delete ui;
}

void Zhunjiarenyuan::on_pushButton_clicked()
{
    list_all_zhunjiarenyuan.clear();
    ui->tableWidget->clear();

    Manager_c *m=new Manager_c;
    this->hide();
    m->show();
}

void Zhunjiarenyuan::on_pushButton_2_clicked()
{
    QString name_c=ui->lineEdit->text();
    if(name_c=="")
    {
        QMessageBox::information(this ,tr("提示") , tr("请输入姓名后重新查询!"));
        return;
    }


    list_all_zhunjiarenyuan.clear();
    //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);


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
    query.exec("select name,danwei,telephone,yanzhengma,chexing,zhunjiaid,zhunjiadengji,state from zhunjiadriver where name='"+name_c+"'");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString name = query.value(0).toString();
        QString danwei = query.value(1).toString();
        QString telephone = query.value(2).toString();
        QString yanzhengma =query.value(3).toString();
        QString chexing=query.value(4).toString();
        QString zhunjiaid=query.value(5).toString();
        QString zhunjiadengji=query.value(6).toString();
        QString state=query.value(7).toString();

        q<<name<<danwei<<telephone<<yanzhengma<<chexing<<zhunjiaid<<zhunjiadengji<<state;
        list_all_zhunjiarenyuan.append(q);
    }



    for(int i=0;i<list_all_zhunjiarenyuan.size();i++)
    {

        int row = ui->tableWidget->rowCount();
        qDebug()<<row;
        ui->tableWidget->insertRow(row);

        QStringList rowdata=list_all_zhunjiarenyuan[i].toStringList();

        for(int j  = 0 ; j <rowdata .size() ; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row , j , item);
        }

    }
}

void Zhunjiarenyuan::on_pushButton_4_clicked()
{
    QString name_c=ui->lineEdit->text();


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
    query.exec("select name from zhunjiadriver");
    bool T2=true;
    while(query.next())
    {
        QString name= query.value(0).toString();
        if(name_c.compare(name)==0)
        {

            QString sql;
            sql = QString("DELETE FROM zhunjiadriver "
                         " where name = '%1' ").arg(name);
            QSqlQuery query;
            bool ok = query.exec(sql);
            if(ok)
            {
                QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
                T2=false;
            }
            else
            {
                QMessageBox::information(this ,tr("提示") , tr("删除失败!"));
                T2=false;
            }
        }
    }
    if(T2==true)
    {
        QMessageBox::information(this ,tr("提示") , tr("该驾驶员不存在无法删除"));
    }
}

void Zhunjiarenyuan::on_pushButton_5_clicked()
{

    QString name_c=ui->lineEdit->text();
    int rows=ui->tableWidget->rowCount();
    //int columns=ui->tableWidget->columnCount();

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
    query.exec("select id from zhunjiadriver where name='"+name_c+"' ");
    query.next();
    int id1= query.value(0).toInt();
    QString tableText1;
    QString tableText2;
    QString tableText3;
    QString tableText4;
    QString tableText5;
    QString tableText6;
    QString tableText7;
    QString tableText8;

    for(int i=0; i<rows; i++)
    {
        if(ui->tableWidget->item(i,0)->text()==name_c)
        {

            tableText1 = ui->tableWidget->item(i,0)->text();
            tableText2 = ui->tableWidget->item(i,1)->text();
            tableText3 = ui->tableWidget->item(i,2)->text();
            tableText4 = ui->tableWidget->item(i,3)->text();
            tableText5 = ui->tableWidget->item(i,4)->text();
            tableText6 = ui->tableWidget->item(i,5)->text();
            tableText7 = ui->tableWidget->item(i,6)->text();
            tableText8 = ui->tableWidget->item(i,7)->text();

            break;
        }

    }

    query.exec("select name from zhunjiadriver");
    bool T2=true;
    while(query.next())
    {
        QString name= query.value(0).toString();

        if(name_c.compare(name)==0)
        {
            QString sql;
            sql = QString("UPDATE zhunjiadriver "
                         "set  id= '%1',name= '%2',danwei='%3',telephone='%4',yanzhengma='%5',chexing='%6',zhunjiaid='%7',zhunjiadengji='%8',state='%9'"
                          "where id='%10'")
                   .arg(id1).arg(tableText1).arg(tableText2).arg(tableText3).arg(tableText4).arg(tableText5).arg(tableText6).arg(tableText7).arg(tableText8).arg(id1);

            qDebug()<<tableText2;
            //QSqlQuery query(db);
            bool ok = query.exec(sql);
            if(ok)
            {

                QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
                T2=false;
            }
            else
            {
                QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
                T2=false;
            }
        }
    }

    if(T2==true)
    {
       QMessageBox::information(this ,tr("提示") , tr("该驾驶员不存在或输入姓名为空，无法更改！"));
    }
}

void Zhunjiarenyuan::on_pushButton_3_clicked()
{
    Adddriver *d=new Adddriver;
    this->hide();
    d->show();
}
