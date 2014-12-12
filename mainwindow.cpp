#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMaximumSize(255, 544);
    setMinimumSize(255, 544);
}

MainWindow::~MainWindow()
{
    delete ui;
}
