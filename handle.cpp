/**
 * 文件名：handle.cpp
 * 文件功能：定义handle类的所有函数
 * 类的作用：所有界面的业务操作函数集合
 * 类的继承：QObejct
 * 作者：NoCo_jancojie
 */
#include "handle.h"

Handle::Handle(QObject *parent) :
    QObject(parent)
{
//    从配置文件中读取服务器的ip
    ip=config.getValue("ip");
//    从配置文件中读取服务器的端口
    port=config.getValue("port").toInt();
}
/**
 * @brief 信息处理
 * @param message 服务器返回的源信息
 * 协议例子[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码
 * @return 返回处理后的信息（清楚相应的标记头保留信息源）
 */
QString Handle::changeMessage(QString message)
{
<<<<<<< HEAD
    QString pattern="(?:\\[length=)(\\d+)(?:\\])";
    QRegExp reg(pattern);
    //QString message="[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码";
    QStringList list=message.split(reg);
    return list[1];


=======
//    正则规范:提取[length=15]中的15
    QString pattern="(?:\\[length=)(\\d+)(?:\\])";
//    使用正则规范创建正则表达式对象
    QRegExp reg(pattern);
//    使用字符串对象中的分割函数，并使用正则对象进行分割，0为分割前 1为分割后
    QStringList list=message.split(reg);
//    返回相应的信息
    return list[1];
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c

}
/**
 * @brief 协议信息提取（提取协议中相关信息并保存）
 * @param command 经过处理的信息
 * @return 一个key value集合对<信息名,信息>
 * 返回信息使用方法 QMap map=return 信息=map[信息名]
 */
QMap<QString, QString> Handle::getCommand(QString command)
{
//    正则规范：提取<TYPE：>信息 中的TYPE和信息
    QString pattern="(?:<)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)(?::>)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)";
<<<<<<< HEAD
     //QString message="[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码";
=======
//        使用正则规范创建正则表达式对象
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c
    QRegExp reg(pattern);
//    定义一个标志位，用于判断是否已到达字符串的末尾
    int i=0;
//    创建QMap对象保存查找后的信息
    QMap<QString,QString> map;
//    定义循环，重复查找，直到字符串结束
    while(true){
//        查找符合正则规范的字符串，并返回是否查找成功 -1为不成功
        i=command.indexOf(reg,i+1);
//        当返回的标志位为-1，则跳出循环
        if(i==-1)
        {
            break;
        }
//        把查找到的key和value放进map<key,value>
        map.insert(reg.cap(1),reg.cap(2));
    }
//    返回结果集
    return map;

}
/**
 * @brief 注册处理函数（用于进行注册操作业务处理，并返回处理结果）
 * @param userId 用户名的id 唯一标示不可变
 * @param userName 用户的昵称
 * @param pwd 用的密码
 * @return 返回是否注册成功 true注册成功 false 注册不成功(用户名被占用等原因)
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
bool Handle::registered(QString userId, QString userName, QString pwd)
{
//    拼接服务器请求协议
    QString command="<loginuser><userid:>"+userId+"<name:>"+userName+"<password:>"+pwd;
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    tcp.tcpconnect(ip,port);
//    发送协议
    tcp.send(command);
<<<<<<< HEAD
    QMap<QString,QString>result=getCommand(changeMessage(tcp.read()));
=======
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap result=getCommand(changeMessage(tcp.read()));
//    若返回的type字段值为1则注册成功，否则注册失败
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c
    if(result["type"]=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
<<<<<<< HEAD
bool Handle::signin(QString userId, QString pwd)
{
    QString command="<signin><userid:>"+userId+"<password:>"+pwd+"<ip:>"+tcp.getLocalAddress()+"<port:>端口";
=======
/**
 * @brief 创建聊天室处理函数（用于进行创建聊天室操作业务处理，并返回处理结果）
 * @param userId 用户名的id 群主的id
 * @param talkroomid 聊天室的id
 * @param talkroomname 聊天室的名字
 * @return 返回是否创建成功 true创建成功 false 创建不成功(用户名被占用等原因)
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
bool Handle::creatTalkroom(QString userId, QString talkroomid, QString talkroomname)
{
//    拼接服务器请求协议
    QString command="<login talkroom><userid:>"+userId+"<talkroomid:>"+talkroomid+"<talkroomname:>"+talkroomname;
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    tcp.tcpconnect(ip,port);
//    发送协议
    tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap result=getCommand(changeMessage(tcp.read()));
//    若返回的type字段值为1则注册成功，否则注册失败
    if(result["type"]=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief 登录处理函数（用于进行登录操作业务处理，并返回处理结果）
 * @param userId 用户名的id 群主的id
 * @param pwd 用户密码
 * @param port(int) 程序开始时绑定的端口
 * @return 返回是否登录成功 0登录成功 1用户名或密码错误 2已有用户登录 3未知错误
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
int Handle::signIn(QString userId, QString pwd,int port)
{
//    拼接服务器请求协议
    QString command="<signin><userid:>"+userId+"<password:>"+pwd+"<ip:>"+tcp.getLocalAddress()+"<port:>端口"+QString::number(port);
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    tcp.tcpconnect(ip,port);
//    发送协议
    tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap result=getCommand(changeMessage(tcp.read()));
//    若返回的type字段值为1则注册成功，否则注册失败
//    遍历map
    QMap<QString,QString>::iterator it;
    for ( it = result.begin(); it != result.end(); ++it ) {
          if(it.key()=="username")
          {
              return 0;
          }
          else if(it.key()=="type")
          {
              return it.value().toInt();
          }
    }
    return 3;
>>>>>>> 94ca8d59868df8251ef3667d2b67764f3e7f1b0c
}
