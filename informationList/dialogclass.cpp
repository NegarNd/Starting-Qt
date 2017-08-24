#include "dialogclass.h"
#include "ui_dialogclass.h"

DialogClass::DialogClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClass)
{
    ui->setupUi(this);
    licenseArray = {"license1" , "license2"};
    connect(this->ui->pushButton , SIGNAL(clicked(bool)) , this , SLOT(accept()));

}

DialogClass::~DialogClass()
{
    delete ui;
}

QJsonObject DialogClass::returnData()
{
    return informationObject;
}

void DialogClass::clear()
{
    ui->nameEdit->clear();
    ui->middleEdit->clear();
    ui->lastEdit->clear();
    ui->ageEdit->clear();
}

void DialogClass::accept()
{
    informationObject.insert("name" , ui->nameEdit->text());
    informationObject.insert("middleName" , ui->middleEdit->text());
    informationObject.insert("lastName" , ui->lastEdit->text());
    informationObject.insert("age" , ui->ageEdit->text().toInt());
    informationObject.insert("license" , licenseArray);
    QDialog::accept();
}
