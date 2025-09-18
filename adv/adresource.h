#ifndef ADRESOURCE_H
#define ADRESOURCE_H

#include <QObject>

class AdResource : public QObject
{
    Q_OBJECT
public:
    explicit AdResource(QObject *parent = nullptr);
    AdResource(const AdResource& ar);

    AdResource(int adId, int typeId, int index, const QString &url, const QString &localPath, const QString &sign);
    AdResource(int id, int adId, int typeId, int index, const QString &url, const QString &localPath, const QString &sign);

    void operator=(const AdResource& ar);

    int getId() const;
    void setId(int newId);
    int getAdId() const;
    void setAdId(int newAdId);
    int getTypeId() const;
    void setTypeId(int newTypeId);
    int getIndex() const;
    void setIndex(int newIndex);
    const QString &getUrl() const;
    void setUrl(const QString &newUrl);
    const QString &getLocalPath() const;
    void setLocalPath(const QString &newLocalPath);
    const QString &getSign() const;
    void setSign(const QString &newSign);

private:
    int id;
    int adId;
    int typeId;
    int index;
    QString url;
    QString localPath;
    QString sign;

};

#endif // ADRESOURCE_H
