#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    class1(1),
    class2(2),
    class3(3),
    class4(4)
{
    ui->setupUi(this);
    firstThread = new QThread;
    secondThread = new QThread;
    class1.moveToThread(firstThread);
    class2.moveToThread(firstThread);
    class3.moveToThread(firstThread);
    class4.moveToThread(secondThread);
    firstThread->start();
    secondThread->start();


    connect(ui->pushButton , SIGNAL(clicked(bool)), &class1 , SLOT(printThreadId()));
    connect(ui->pushButton , SIGNAL(clicked(bool)), &class2 , SLOT(printThreadId()));
    connect(ui->pushButton , SIGNAL(clicked(bool)), &class3 , SLOT(printThreadId()));
    connect(ui->pushButton , SIGNAL(clicked(bool)), &class4 , SLOT(printThreadId()));

    connect(&class4 , SIGNAL(classFourSignal()), &class1 , SLOT(printConnection()), Qt::DirectConnection);
    //connect(&class4 , SIGNAL(classFourSignal()), &class1 , SLOT(printConnection()), Qt::QueuedConnection);
    //connect(&class4 , SIGNAL(classFourSignal()), &class1 , SLOT(printConnection()), Qt::BlockingQueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    firstThread->quit();
    firstThread->wait();
    secondThread->quit();
    secondThread->wait();
}
