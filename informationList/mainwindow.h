#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <informationClass.h>
#include <dialogclass.h>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <QJsonDocument>
#include <QLayout>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVBoxLayout *scrollLayout;
    DialogClass *dialogObj;
    informationClass  *newPerson;
    QJsonObject personInformation;

private slots:
    void on_addButton_clicked();
     void addNew();


     void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
