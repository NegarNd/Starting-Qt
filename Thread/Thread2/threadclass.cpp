#include "threadclass.h"

ThreadClass::ThreadClass(int id)
{
    this->id = id;
    myThread = new QThread;
    this->moveToThread(myThread);
    this->myThread->start();
    connect(this->myThread , SIGNAL(started()) , this , SLOT(startOnThread()));

}

ThreadClass::~ThreadClass()
{
    qDebug() <<"class with id :" <<this->id <<"closed";
    this->myThread->quit();
    this->myThread->wait();
}

void ThreadClass::startOnThread()
{
    connect(this, SIGNAL(destroyed(QObject*)) , this->myThread , SLOT(deleteLater()));
}

void ThreadClass::runm()
{
    qDebug() <<"current thread id for class" <<id << ":" << QThread::currentThread();
    qDebug() <<"class" <<id <<"thread id" <<this->myThread->thread();
}
