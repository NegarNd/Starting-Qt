#include "threadclass.h"

threadClass::threadClass(int id)
{
    this->id = id;
}

void threadClass::printThreadId()
{
    for(int i=0 ; i<10 ; i++)
    {
        qDebug() <<"my class id is: " <<id <<"and the thread address is:" <<QThread::currentThread();
        if(i==5)
            emit classFourSignal();
    }


}

void threadClass::printConnection()
{
     qDebug() <<"the thread id that is calling this slot is:" <<QThread::currentThread();
}
