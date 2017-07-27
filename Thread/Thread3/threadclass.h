#ifndef THREADCLASS_H
#define THREADCLASS_H
#include <QObject>
#include <QThread>
#include <QDebug>

class threadClass : public QObject
{
    Q_OBJECT
public:
    threadClass(int id);
    int id;
    QThread threadId;
signals:

    void classFourSignal();
public slots:
    void printThreadId();
    void printConnection();
};

#endif // THREADCLASS_H
