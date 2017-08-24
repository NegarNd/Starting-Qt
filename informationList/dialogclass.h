#ifndef DIALOGCLASS_H
#define DIALOGCLASS_H

#include <QDebug>
#include <QDialog>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class DialogClass;
}

class DialogClass : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClass(QWidget *parent = 0);
    ~DialogClass();
    QJsonObject informationObject;
    QJsonArray licenseArray;
    QJsonObject returnData();
    void clear();

private slots:
  void accept();


private:
    Ui::DialogClass *ui;
};

#endif // DIALOGCLASS_H
