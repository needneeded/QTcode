#include "adresource.h"

AdResource::AdResource(QObject *parent) : QObject(parent)
{

}

AdResource::AdResource(const AdResource &ar)
{
    this->id = ar.id;
    this->adId = ar.adId;
    this->index = ar.index;
    this->url = ar.url;
    this->localPath = ar.localPath;
    this->sign = ar.sign;
}

AdResource::AdResource(int id, int adId, int typeId, int index, const QString &url, const QString &localPath, const QString &sign) : id(id),
    adId(adId),
    typeId(typeId),
    index(index),
    url(url),
    localPath(localPath),
    sign(sign)
{}

void AdResource::operator=(const AdResource &ar)
{
    this->id = ar.id;
    this->adId = ar.adId;
    this->index = ar.index;
    this->url = ar.url;
    this->localPath = ar.localPath;
    this->sign = ar.sign;
}

int AdResource::getId() const
{
    return id;
}

void AdResource::setId(int newId)
{
    id = newId;
}

int AdResource::getAdId() const
{
    return adId;
}

void AdResource::setAdId(int newAdId)
{
    adId = newAdId;
}

int AdResource::getTypeId() const
{
    return typeId;
}

void AdResource::setTypeId(int newTypeId)
{
    typeId = newTypeId;
}

int AdResource::getIndex() const
{
    return index;
}

void AdResource::setIndex(int newIndex)
{
    index = newIndex;
}

const QString &AdResource::getUrl() const
{
    return url;
}

void AdResource::setUrl(const QString &newUrl)
{
    url = newUrl;
}

const QString &AdResource::getLocalPath() const
{
    return localPath;
}

void AdResource::setLocalPath(const QString &newLocalPath)
{
    localPath = newLocalPath;
}

const QString &AdResource::getSign() const
{
    return sign;
}

void AdResource::setSign(const QString &newSign)
{
    sign = newSign;
}

AdResource::AdResource(int adId, int typeId, int index, const QString &url, const QString &localPath, const QString &sign) : adId(adId),
    typeId(typeId),
    index(index),
    url(url),
    localPath(localPath),
    sign(sign)
{}
