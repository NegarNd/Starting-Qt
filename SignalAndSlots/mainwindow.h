#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
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

private:
    Ui::MainWindow *ui;
    int current_v , last_v;
private slots:
    void move_to_left(int value);
    void reaching_50(int value);
signals:
    void changeCheckBox();
};

#endif // MAINWINDOW_H
