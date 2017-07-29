#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QTimer>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double startR = 10.0;
    double phi = 0.0;
    QTimer *time ;
    QVector<double> x, y;
    QCPCurve *newCurve;
public slots:
    void updatePlot();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
