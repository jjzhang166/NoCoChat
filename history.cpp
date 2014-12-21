#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    setMinimumSize(440,390) ;
    ui->textEdit->setReadOnly(true);    // 设置 textedit 只可读属性
}

History::~History()
{
    delete ui;
}
