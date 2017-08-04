#ifndef UDPSOCKETCLASS_H
#define UDPSOCKETCLASS_H
#include <QDebug>
#include <QThread>
#include <QObject>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>

class UdpSocketClass : QObject
{
    Q_OBJECT
public:
    UdpSocketClass();
    ~UdpSocketClass();
    QThread *udpThread;
    QUdpSocket *udpSocket;
    QByteArray data;
QHostAddress bindingIP;
    quint16 bindingPort;

public slots:
    void onThreadStarts();
    void readData();
    void disconnectSocket();
};

#endif // UDPSOCKETCLASS_H
