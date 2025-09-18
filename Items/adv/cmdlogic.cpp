#include "cmdlogic.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>
#include <QDebug>
#include <QTextCodec>

CmdLogic::CmdLogic(QObject *parent) : QObject(parent)
{

}

CmdLogic *CmdLogic::getInstance()
{
    // 这种方式的写法，在多线程的情况下，是容易出现线程安全问题 - 互斥锁解决线程安全
    if(instance == nullptr)
    {
        instance = new CmdLogic();
    }
    return instance;
}


void CmdLogic::execute(QByteArray cmdStr)
{
    QJsonDocument doc = QJsonDocument::fromJson(cmdStr);
    QString cmd;
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        int cmdId = obj.value("cmdId").toInt();
        switch(cmdId)
        {
        case 1: // 重启 echo 123456 | sudo -S reboot
            //                cmd = "echo 123456 | sudo -S reboot";
            qDebug() << "echo 123456 | sudo -S reboot";
            break;
        case 2: // 更新程序 - 调用更新程序的代码就可以了
            break;
        case 3: // 关机  echo 123456 | sudo -S shutdown -h now
            //                cmd = "echo 123456 | sudo -S shutdown -h now";
            qDebug() << "echo 123456 | sudo -S shutdown -h now";
            break;
        default:
            break;
        }
        //        executeCmd(cmd);
    }
}

void CmdLogic::executeCmd(QString cmd)
{
    QProcess process;
    process.start(cmd); // 执行进程，进程的内容就是一个cmd指令

    if(!process.waitForFinished(3000))
    {
        qDebug() << "指令执行失败:" << process.errorString();
    }else{
        // ping www.baidu.com
        QByteArray output = process.readAllStandardOutput();

        QTextCodec* codec = QTextCodec::codecForName("system");
        // 将byteArray转为一个unicode码 - 解决乱码问题
        QString msg = codec->toUnicode(output);
        qDebug() << "execut cmd:" << cmd <<",result is:"<< msg;
    }
}

CmdLogic *CmdLogic::instance = nullptr;
