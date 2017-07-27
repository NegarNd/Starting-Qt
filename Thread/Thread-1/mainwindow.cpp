#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    classOne(1),
    classTwo(2)
{
    ui->setupUi(this);
    classOne.moveToThread(&firstThread);
    classTwo.moveToThread(&secondThread);
    //start the threads to be able to use them
    firstThread.start();
    secondThread.start();
    connect(ui->pushButton , SIGNAL(clicked(bool)) , &classOne , SLOT(runm()));
    connect(ui->pushButton , SIGNAL(clicked(bool)) , &classTwo , SLOT(runm()));

}

MainWindow::~MainWindow()
{
    delete ui;
    //you should quit the threads before ending the program
    firstThread.quit();
    secondThread.quit();
    firstThread.wait();
    secondThread.wait();
}
