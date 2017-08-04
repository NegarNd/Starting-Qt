#include "udpsocketclass.h"

UdpSocketClass::UdpSocketClass() : bindingIP("192.168.33.1"),
    bindingPort(1028)
{
    udpThread = new QThread;
    this->moveToThread(udpThread);
    udpThread->start();
    connect(this->udpThread , SIGNAL(started()) , this , SLOT(onThreadStarts()));
}



void UdpSocketClass::onThreadStarts()
{
    udpSocket = new QUdpSocket;
     udpSocket->bind(QHostAddress(" 192.168.33.1") , 1028);
    connect(this , SIGNAL(destroyed(QObject*)) , this->udpThread , SLOT(deleteLater()));
    connect(this , SIGNAL(destroyed(QObject*)) , this->udpSocket , SLOT(deleteLater()));

    connect(this->udpSocket,SIGNAL(readyRead()),SLOT(readData()));
}

void UdpSocketClass::readData()
{
    while(this->udpSocket->hasPendingDatagrams()){
        data.resize(udpSocket->pendingDatagramSize());
        QHostAddress sampleIP = this->bindingIP;
        quint16 samplePort = this->bindingPort;
        udpSocket->readDatagram(data.data(), data.size(), &sampleIP , &samplePort);
        qDebug() << data.toHex();
    }
}

UdpSocketClass::~UdpSocketClass()
{
    udpThread->quit();
    udpThread->wait();
}

void UdpSocketClass::disconnectSocket()
{
    udpSocket->abort();
}
