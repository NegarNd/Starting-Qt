#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "threadclass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    threadClass class1;
    threadClass class2;
    threadClass class3;
    threadClass class4;
    QThread *firstThread;
    QThread *secondThread;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
