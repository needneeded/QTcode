#include "fileutil.h"
#include <QNetworkReply>
#include <QFile>

FileUtil::FileUtil(QObject *parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager();
}

// 将远程文件下载到本地
void FileUtil::downloadFile(QString remoteUrl, QString localPath)
{
    qDebug()<< "远程url："<<remoteUrl;
    qDebug()<< "本地url："<<localPath;
    QNetworkReply *reply = this->manager->get(QNetworkRequest(QUrl(remoteUrl)));

    connect(reply,&QNetworkReply::finished,[=]()->void{
        QFile file(localPath);
        if(!file.exists())
        {
            if(file.open(QIODevice::Append | QIODevice::WriteOnly)){
                file.write(reply->readAll());
            }
        }else{
            if(!file.open(QIODevice::ReadWrite))
            {
                qDebug() << "文件打开失败";
                return;
            }
            file.write(reply->readAll());
        }
        file.close();
        qDebug() << "文件下载成功";
    });
}

QString FileUtil::aesFile(QString localPath)
{
    //yul/6+ixl/cOhv5rDKJSNZlmdvL0F5IuSuupDuCcEWw=
    QFile file(localPath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file for reading";
        return "";
    }
    QByteArray fileContent = file.readAll();
    file.close();

    QByteArray encryptedContent = QCryptographicHash::hash(fileContent, QCryptographicHash::Sha256);

    QString encryptedString = encryptedContent.toBase64(); // 将加密后的数据转换为Base64编码的字符串形式

    qDebug() << "加密后的结果:" << encryptedString;
    return encryptedString;
}
