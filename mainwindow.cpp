#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vietnamese.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(360, 170);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_p2wButton_released()
{
    ui->p2w_wEdit->setText(phone2word(ui->p2w_pEdit->text().toLower()));
}

void MainWindow::on_w2pButton_released()
{
    ui->w2p_pEdit->setText(word2phone(ui->w2p_wEdit->text().toLower()));
}
