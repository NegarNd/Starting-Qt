#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListIterator>
#include <QMainWindow>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

struct _DataPackVector{
    QVector <double> X;
    QVector <double> Y;
    QVector <double> Power;
    QVector <double> neighborAVG;
    QVector <double> thresholdPoint;
    _DataPackVector(){}
    ~_DataPackVector(){}
};

class dataPack{
    friend class Monitoring3GHz;
protected:
public:
//    QVector <double> Power;
//    QVector <double> Frequency;
    dataPack(){}
    ~dataPack(){}
    _DataPackVector QCPData;
    quint64 time_ms;
    QList<int> maxIndexList;
};

class maxHold{
public:
    QVector <double> Power;
    QVector <double> Frequency;
    bool feed(QVector<double> FrequencyIn, QVector<double> PowerIn);
    void clear();
    quint64 holdTime_ms = 10000;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     QList<dataPack> dataStorage;

     maxHold _maxHold;


     void setMaxHoldData();
     quint64 pastTime;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
