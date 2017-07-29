#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<double> x(251) , y0(251) , y1(251);
    for(int i=0 ; i<251 ; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0);
        y1[i] = qExp(-i/150.0);
    }
    myGraph1 = ui->widget->addGraph();
    myGraph1->setData(x,y0);

    QCPGraph *myGraph2 = ui->widget->addGraph();
    myGraph2->setData(x,y1);

    myGraph1->setPen(QPen(Qt::DashLine));
    myGraph1->setPen(QPen(Qt::red));
    myGraph1->setBrush(QBrush(Qt::green));
    myGraph1->setLineStyle(QCPGraph::lsStepCenter);
    myGraph1->setName("first Graph");

    myGraph2->setPen(QPen(Qt::yellow));

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->yAxis->setRange(0,1);
    ui->widget->xAxis2->setVisible(true);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setTickLabels(false);
    //set range of xAxis and yAxis
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
    myGraph1->rescaleAxes();
    myGraph2->rescaleAxes(true);

    // make ticks on bottom axis go outward:
    //first parameter is length for inside and the next parameter is the length for outside
    ui->widget->xAxis->setTickLength(0,5);
    ui->widget->xAxis->setSubTickLength(0, 3);
    //we can use ui->widget->rescaleAxes(); instead of the two above codes

    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    myGraph1->setChannelFillGraph(myGraph2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
