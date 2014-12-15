#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString username ;  // 用户昵称
    QString userId ;    // 用户(帐号)ID

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
