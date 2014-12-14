#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <QString>

namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();

private slots:
    void on_friend_searchbtn_clicked(); // 查找好友

private:
    Ui::AddInfo *ui;

    QString userid ;    // 用户帐号（ID）
    QString username ;  // 用户昵称
};

#endif // ADDINFO_H
