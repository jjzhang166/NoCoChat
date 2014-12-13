#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>

namespace Ui {
class AddInfo;
}

class AddInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();

private:
    Ui::AddInfo *ui;
};

#endif // ADDINFO_H
