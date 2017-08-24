#include "informationClass.h"
#include "ui_informationclass.h"

informationClass::informationClass(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::informationClass)
{
    ui->setupUi(this);
}

informationClass::~informationClass()
{
    delete ui;
}

void informationClass::setInformation(QJsonObject information)
{
    QString licenseString;
    ui->nameLable->setText(information.value("name").toString());
    ui->middleLable->setText(information.value("middleName").toString());
    ui->lastLabel->setText(information.value("lastName").toString());
    ui->ageLable->setText(QString::number(information.value("age").toInt()));
    for(int i=0 ; i<information.value("license").toArray().size() ; i++)
    {
        licenseString = licenseString+ "  " + information.value("license").toArray().at(i).toString();
    }
    ui->licenseLabel->setText(licenseString);
}

QString informationClass::getName()
{
    return ui->nameLable->text();
}

void informationClass::on_removeButton_clicked()
{
      this->deleteLater();
}
