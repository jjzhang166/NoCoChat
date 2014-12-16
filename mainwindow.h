#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "signin.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Signin signin;

    QString username ;  // 用户昵称
    QString userId ;    // 用户(帐号)ID

    QString getUserName();
    QString getUserId();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
