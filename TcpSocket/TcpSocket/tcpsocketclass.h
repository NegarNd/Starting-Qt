#ifndef TCPSOCKETCLASS_H
#define TCPSOCKETCLASS_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>

class TcpSocketClass :public QObject
{
    Q_OBJECT
public:
    TcpSocketClass();
    ~TcpSocketClass();
    QThread *socketThread;
    QTcpSocket *tcpSocket;
public slots:
    void onThreadStart();
    void readData();
    void deleteSocket();

};

#endif // TCPSOCKETCLASS_H
