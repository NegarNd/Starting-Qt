#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tcpsocketclass.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    TcpSocketClass mySocket;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
