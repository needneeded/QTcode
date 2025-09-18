#ifndef AD_H
#define AD_H

#include <QObject>
#include <QList>
#include "adresource.h"

class Ad : public QObject
{
    Q_OBJECT
public:
    explicit Ad(QObject *parent = nullptr);
    Ad(const Ad& ad);

    Ad(int templateId, int index, const QString &startTime, const QString &endTime, int state);
    Ad(int id, int templateId, int index, const QString &startTime, const QString &endTime, int state);

    void operator=(const Ad& ad);

    int getId() const;
    void setId(int newId);
    int getTemplateId() const;
    void setTemplateId(int newTemplateId);
    int getIndex() const;
    void setIndex(int newIndex);
    const QString &getStartTime() const;
    void setStartTime(const QString &newStartTime);
    const QString &getEndTime() const;
    void setEndTime(const QString &newEndTime);
    int getState() const;
    void setState(int newState);


    QList<AdResource> *getAdResources() const;
    void setAdResources(QList<AdResource> *newAdResources);

private:
    int id;
    int templateId;
    int index;
    QString startTime;
    QString endTime;
    int state;

    // 一个广告会有多个广告资源
    QList<AdResource> *adResources;
};

#endif // AD_H
