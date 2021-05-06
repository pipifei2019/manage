#include "yewuyuyue.h"
#include "ui_yewuyuyue.h"
#include"globle.h"
#include"shouye.h"

Yewuyuyue::Yewuyuyue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yewuyuyue)
{
    ui->setupUi(this);
}

Yewuyuyue::~Yewuyuyue()
{
    delete ui;
}

void Yewuyuyue::on_pushButton_clicked()
{
    list_all_daibanyewu.clear();

    Form *f=new Form;
    this->hide();
    f->show();
}

void Yewuyuyue::on_pushButton_2_clicked()
{
    QString text1=ui->dateEdit->text();
    QString text2=ui->lineEd1->text();
    QString text3=ui->lineEd2->text();
    int index1=ui->comboBox->currentIndex();
    QString text4=ui->comboBox->itemText(index1);
    int index2=ui->comboBox_2->currentIndex();
    QString text5=ui->comboBox_2->itemText(index2);
    int index3=ui->comboBox_3->currentIndex();
    QString text6=ui->comboBox_3->itemText(index3);
    QString text7=username_qj;

    if(text1==""||text2==""||text3==""||text4==""||text5==""||text6==""||text7=="")
    {
        QMessageBox::information(this ,tr("提示") , tr("请核对信息后重新预约!"));
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
    query.exec("select id from daibanyewu order by id desc ");
    query.next();
    id1= query.value(0).toInt()+1;
    QString s = QString::number(id1);
    text6=text6+s;

    db.exec("SET NAMES 'utf-8'");

    bool T2=true;

    if(T2==true)
    {
        QString sql;
        sql = QString("insert into daibanyewu (id,time,yewuid,project,request,type,addr,beizhu)"
                  " VALUES ('%0', '%1' , '%2', '%3', '%4', '%5', '%6', '%7' )")
            .arg(id1).arg(text1).arg(text6).arg(text2).arg(text3).arg(text4).arg(text5).arg(text7);

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
