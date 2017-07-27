#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    classOne(1),
    classTwo(2)
{
    ui->setupUi(this);
    connect(ui->pushButton , SIGNAL(clicked(bool)) , &classOne , SLOT(runm()));
    connect(ui->pushButton_2 , SIGNAL(clicked(bool)), &classTwo , SLOT(runm()));
    qDebug() <<"mainwindow thread id" <<QThread::currentThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    delete &classOne;
}
