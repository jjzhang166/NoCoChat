#include "chat.h"
#include <QString>
#include <QStyle>
#include <QFontDialog>
#include <QColor>

Chat::Chat(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint)
{
    init();
    resize(500, 400);
    setMinimumSize(500, 400);   // 设置聊天窗口最小大小为500x400
    setWindowFlags(Qt::WindowMinimizeButtonHint);   // 设置窗口最小化按钮
    setWindowFlags(Qt::WindowMaximizeButtonHint);   // 设置窗口最大化按钮
    splitter->setOpaqueResize(false);   // 设置为不透明
    alltext->resize(1000,550);
    inputtext->resize(500, 50);
    splitter->resize(500,400);
    printf("no problem");
    setComponent();
    setSize();
    setConnect();
    setWindowOpacity(2);
    setAttribute(Qt::WA_TranslucentBackground);
}

Chat::~Chat()
{

}

// 组件初始化
void Chat::init()
{
    splitter = new QSplitter(Qt::Horizontal, this);     // 水平分割窗口，把窗口分成多列-->主分割
    Lsplitter = new QSplitter(Qt::Vertical, splitter) ; // 垂直分割左边部分窗口，把窗口分割成多行
    Rsplitter = new QSplitter(Qt::Vertical,splitter) ;  // 垂直分割右边部分窗口，把窗口分割成多行
    alltext = new QTextEdit ;     // 所有聊天信息显示区域
    inputtext = new QTextEdit ;   // 本地输入区域
    historytext = new QTextEdit ;   // 历史记录显示框
    center = new QDialog;   // 聊天对话框中间用于放置工具栏的 dialog 部件
    fontbtn = new QPushButton(center) ; // 改变字体按钮
    history = new QPushButton(center) ; // 查看历史记录按钮
    frame = new QFrame;
    send = new QPushButton(frame) ;     // 聊天消息发送按钮


}

// 将各部件布局到窗口的函数
void Chat::setComponent()
{
    alltext->setReadOnly(true); // 设置所有聊天信息显示区域为只读，不能写
    fontbtn->setIcon(QPixmap(":/img/font.png"));
    fontbtn->move(0,0);
    history->setText("历史记录");
    send->setText("发送");
    send->resize(50,20);
    send->move(10,10);
    Lsplitter->addWidget(alltext);
    Lsplitter->addWidget(center);
    Lsplitter->addWidget(inputtext);
    Lsplitter->addWidget(frame);
}

// 设置组件大小
void Chat::setSize()
{
    float height, width;
    height = this->height();    // 获取窗口的高度
    width = this->width() ;     // 获取窗口的宽度
    fontbtn->resize(20, 20);
    history->move((center->width())-(history->width()-20), 0);
    center->setMinimumHeight(22);
    center->setMaximumHeight(22);
    center->resize(splitter->width(),height);
    center->setContentsMargins(0,0,0,0);
    alltext->setText(QString::number(frame->width()));
    frame->setMaximumHeight(50);
    //sendlabel->resize(width, 15);
}

// 连接函数
void Chat::setConnect()
{
    connect(fontbtn, SIGNAL(clicked()), this, SLOT(setFont())) ;
    connect(history, SIGNAL(clicked(bool)), this, SLOT(showHistory(bool))) ;
}

// 事件
// 大小改变事件
void Chat::resizeEvent(QResizeEvent *)
{
    setSize();
}

// 槽函数
// 设置字体
void Chat::setFont()
{
    bool ok ;
    font = QFontDialog::getFont(&ok) ;
    if (ok)
    {
        inputtext->setFont(font);
    }
}

// 显示历史记录
void Chat::showHistory(bool ok)
{
    if (ok)
    {
        Rsplitter->resize(300, 400);
        historytext->resize(300, 400);
        Rsplitter->addWidget(historytext);
    }else{
        Rsplitter->resize(0,400);
    }
}
