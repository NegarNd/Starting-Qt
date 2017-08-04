#include "tcpsocketclass.h"

TcpSocketClass::TcpSocketClass()
{
    socketThread = new QThread;
    this->moveToThread(socketThread);
    connect(this->socketThread  , SIGNAL(started()) , this , SLOT(onThreadStart()));
    socketThread->start();

}

TcpSocketClass::~TcpSocketClass()
{
    this->socketThread->quit();
    this->socketThread->wait();
}

void TcpSocketClass::onThreadStart()
{
 connect(this , SIGNAL(destroyed(QObject*)) , this->socketThread , SLOT(deleteLater()));
 tcpSocket = new QTcpSocket;
 connect(this , SIGNAL(destroyed(QObject*)) , this->tcpSocket , SLOT(deleteLater()));
 tcpSocket->connectToHost(QHostAddress("192.168.95.1") , 1028);
 connect(this->tcpSocket , SIGNAL(readyRead()) , this , SLOT(readData()));
}

void TcpSocketClass::readData()
{
    qDebug() <<this->tcpSocket->readAll();
}

void TcpSocketClass::deleteSocket()
{
    this->tcpSocket->abort();
    qDebug() <<"socket destroyeeed";
}

