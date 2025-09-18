#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QObject>
#include <QNetworkAccessManager>

#include <QFile>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDebug>
#include <QBuffer>
#include <QSaveFile>

class FileUtil : public QObject
{
    Q_OBJECT
public:
    explicit FileUtil(QObject *parent = nullptr);

    void downloadFile(QString remoteUrl,QString localPath);

    static QString aesFile(QString localPath);
signals:

private:
    QNetworkAccessManager *manager;
};

#endif // FILEUTIL_H
