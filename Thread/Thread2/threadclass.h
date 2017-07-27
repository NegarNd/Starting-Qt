#ifndef THREADCLASS_H
#define THREADCLASS_H
#include <QObject>
#include <QThread>
#include <QDebug>

class ThreadClass : public QObject
{
    Q_OBJECT
public:
    ThreadClass(int id);
    ~ThreadClass();
    int id;
    QThread *myThread;
public slots:
    void startOnThread();
    void runm();
};

#endif // THREADCLASS_H
