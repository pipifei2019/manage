#include "adddriver.h"
#include "ui_adddriver.h"
#include"globle.h"
#include <QWidget>
#include"zhunjiarenyuan.h"
#include <QMessageBox>
Adddriver::Adddriver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adddriver)
{
    ui->setupUi(this);
}

Adddriver::~Adddriver()
{
    delete ui;
}

void Adddriver::on_pushButton_2_clicked()
{
    list_all_zhunjiarenyuan.clear();
    //ui->tableWidget->clear();

    Zhunjiarenyuan *z=new Zhunjiarenyuan;
    this->hide();
    z->show();
}

void Adddriver::on_pushButton_clicked()
{
    QString text1=ui->lineEd1->text();
    QString text2=ui->lineEd2->text();
    QString text3=ui->lineEd3->text();
    QString text4=ui->lineEd4->text();
    QString text5=ui->lineEd5->text();
    //QString text6=ui->lineEd6->text();
    //QString text7=ui->lineEd7->text();
    int index=ui->comboBox->currentIndex();
    QString text8=ui->comboBox->itemText(index);
    int index1=ui->comboBox_2->currentIndex();
    QString text6=ui->comboBox_2->itemText(index1);
    int index2=ui->comboBox_3->currentIndex();
    QString text7=ui->comboBox_3->itemText(index2);
    if(text1==""||text2==""||text3==""||text4==""||text5==""||text6==""||text7==""||text8=="")
    {
        QMessageBox::information(this ,tr("提示") , tr("请核对信息后重新添加!"));
        return;
    }


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
    int id1;
    query.exec("select id from zhunjiadriver order by id desc ");
    query.next();
    id1= query.value(0).toInt()+1;

    db.exec("SET NAMES 'utf-8'");
    query.exec("select name from zhunjiadriver");
    bool T2=true;
    while(query.next())
    {
        QString name= query.value(0).toString();

        if(name.compare(text1)==0)
        {
            QMessageBox::information(this ,tr("提示") , tr("该驾驶员已存在不允许再次添加!"));
            T2=false;
        }
    }
    if(T2==true)
    {
        QString sql;
        sql = QString("insert into zhunjiadriver (id,name,danwei,telephone,yanzhengma,chexing,zhunjiaid,zhunjiadengji,state)"
                  " VALUES ('%0', '%1' , '%2', '%3', '%4', '%5', '%6', '%7', '%8' )")
            .arg(id1).arg(text1).arg(text2).arg(text3).arg(text4).arg(text6).arg(text5).arg(text7).arg(text8);

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
}
