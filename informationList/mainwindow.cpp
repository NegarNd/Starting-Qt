#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scrollLayout = new QVBoxLayout;
    dialogObj = new DialogClass;
    connect(dialogObj , SIGNAL(accepted()) , this , SLOT(addNew()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    dialogObj->clear();
    dialogObj->open();
    ui->scrollAreaWidgetContents->setLayout(scrollLayout);
}

void MainWindow::addNew()
{
    newPerson = new informationClass;
    personInformation = dialogObj->returnData();
    dialogObj->close();
    newPerson->setInformation(personInformation);
    ui->scrollAreaWidgetContents->layout()->addWidget(newPerson);
}

void MainWindow::on_pushButton_clicked()
{
    QString allNames;
     auto wList = ui->scrollAreaWidgetContents->findChildren<informationClass*>();
     foreach(informationClass *sample, wList){
         allNames = allNames + " " + sample->getName();
     }
     qDebug() << allNames;
}
