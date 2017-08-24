#ifndef INFORMATIONCLASS
#define INFORMATIONCLASS

#include <QGroupBox>
#include <QGroupBox>
#include <QString>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <dialogclass.h>
namespace Ui {
class informationClass;
}

class informationClass : public QGroupBox
{
    Q_OBJECT

public:
    explicit informationClass(QWidget *parent = 0);
    ~informationClass();

    struct informationStruct{
        QString name;
        QString middleName;
        QString lastName;
        int age;
    };

    void setInformation(QJsonObject information);
    QString getName();




private slots:
    void on_removeButton_clicked();

private:
    Ui::informationClass *ui;
};

#endif // INFORMATIONCLASS
