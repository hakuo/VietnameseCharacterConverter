#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vietnamese.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_p2wButton_released();

    void on_w2pButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
