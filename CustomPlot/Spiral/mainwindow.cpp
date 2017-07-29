#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time = new QTimer();
    //update plot every 10 msec
    time->setInterval(10);
    time->start();
    connect(time , SIGNAL(timeout()), this , SLOT(updatePlot()));
    ui->widget->xAxis->setRange(-60,60);
    ui->widget->yAxis->setRange(-60,60);
    newCurve = new QCPCurve(ui->widget->xAxis,ui->widget->yAxis);
    newCurve->setPen(QPen(Qt::red));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePlot()
{
    x.append(startR*cos(phi));
    y.append(startR*sin(phi));
    phi += M_PI/180;
    startR+=0.01;
    newCurve->addData(x.last(), y.last());
    this->ui->widget->replot(QCustomPlot::rpQueuedRefresh);
}
