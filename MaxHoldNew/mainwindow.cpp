#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMaxHoldData()
{
    QDateTime curTime = QDateTime::currentDateTime();
    quint64 curTimeT = curTime.toMSecsSinceEpoch();
    if(this->_maxHold.Power.size() != this->dataStorage.last().QCPData.Power.size()){
        this->_maxHold.Power.resize(this->dataStorage.last().QCPData.Power.size());
        this->_maxHold.Power.fill(-10000,this->dataStorage.last().QCPData.Power.size());
    }


    int iterate = dataStorage.size() - 1;
    quint64 garbageTimeMax = curTimeT - this->_maxHold.holdTime_ms;
    quint64 garbageTimeMin = garbageTimeMax - curTimeT + this->pastTime ;

    QList<bool> dataFound;
    while(iterate>=0)
    {
        quint64  packageTime = dataStorage[iterate].time_ms;
        if((packageTime>garbageTimeMin)&&(packageTime < garbageTimeMax))
        {
            for(int i = dataStorage[iterate].maxIndexList.size()-1 ; i>=0 ; i--)
            {
                int indexFindingMax = dataStorage[iterate].maxIndexList.value(i);

                _maxHold.Power[indexFindingMax] = -10000;
                for(int j = dataStorage.size()-1 ; j>0 ; j--)
                    if(dataStorage[j].time_ms > garbageTimeMax){
                        if(dataStorage[j].QCPData.Power.value(indexFindingMax) > _maxHold.Power[indexFindingMax])
                        {
                            dataFound.insert(indexFindingMax  , true);
                            _maxHold.Power[indexFindingMax] = dataStorage[j].QCPData.Power.value(indexFindingMax);
                            if(!dataStorage[j].maxIndexList.contains(indexFindingMax))
                                dataStorage[j].maxIndexList.append(indexFindingMax);
                        }
                    }
            }
        }
        else if(packageTime < garbageTimeMin){
            break;
        }
        iterate--;
    }
    for(int i = dataStorage.size()-1 ; i>=0 ; i--)
    {
        if(dataStorage[i].time_ms > garbageTimeMax)
        {
            for(int j = 0 ; j<dataStorage.last().QCPData.Power.size() ; j++)
            {
                if((dataFound.value(j)!=true)&& (this->dataStorage[i].QCPData.Power.value(j) > _maxHold.Power.value(j)))
                {
                    dataFound.insert(j , true);
                    _maxHold.Power[j] = this->dataStorage[i].QCPData.Power.value(j);
                    dataStorage[i].maxIndexList.append(j);                }
            }
        }
        else{
            break;
        }
    }
    this->pastTime = curTimeT;
}
