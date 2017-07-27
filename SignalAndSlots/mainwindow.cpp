#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(move_to_left(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(reaching_50(int)));
    connect(this,SIGNAL(changeCheckBox()) , ui->checkBox , SLOT(toggle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_to_left(int value)
{
    int b;
    b=100-value;
    ui->progressBar->setValue(b);
}
void MainWindow::reaching_50(int value)
{
    last_v = current_v;
    current_v = value;
    if(current_v > last_v)
    {
        if((current_v >= 50) && (last_v<50)){
            emit changeCheckBox();

          }}
}
