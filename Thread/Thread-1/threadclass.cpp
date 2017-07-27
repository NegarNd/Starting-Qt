#include "threadclass.h"

ThreadClass::ThreadClass(int id)
{
    this->id = id;
}

void ThreadClass::runm()
{

    qDebug() << "currentThread" << QThread::currentThread();
    for(int i=0 ; i<5 ; i++)
    {
        qDebug() <<this->thread() << "classid :"<< id <<"number of counter" <<i;
    }
}
