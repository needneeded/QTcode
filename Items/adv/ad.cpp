#include "ad.h"

Ad::Ad(QObject *parent) : QObject(parent)
{

}

Ad::Ad(const Ad &ad)
{
    this->id = ad.id;
    this->templateId = ad.templateId;
    this->startTime = ad.startTime;
    this->endTime = ad.endTime;
    this->state = ad.state;
    this->index = ad.index;
    this->adResources = ad.adResources;
}

int Ad::getId() const
{
    return id;
}

void Ad::setId(int newId)
{
    id = newId;
}

int Ad::getTemplateId() const
{
    return templateId;
}

void Ad::setTemplateId(int newTemplateId)
{
    templateId = newTemplateId;
}

int Ad::getIndex() const
{
    return index;
}

void Ad::setIndex(int newIndex)
{
    index = newIndex;
}

const QString &Ad::getStartTime() const
{
    return startTime;
}

void Ad::setStartTime(const QString &newStartTime)
{
    startTime = newStartTime;
}

const QString &Ad::getEndTime() const
{
    return endTime;
}

void Ad::setEndTime(const QString &newEndTime)
{
    endTime = newEndTime;
}

int Ad::getState() const
{
    return state;
}

void Ad::setState(int newState)
{
    state = newState;
}

QList<AdResource> *Ad::getAdResources() const
{
    return adResources;
}

void Ad::setAdResources(QList<AdResource> *newAdResources)
{
    adResources = newAdResources;
}


Ad::Ad(int id, int templateId, int index, const QString &startTime, const QString &endTime, int state) : id(id),
    templateId(templateId),
    index(index),
    startTime(startTime),
    endTime(endTime),
    state(state)
{}

void Ad::operator=(const Ad &ad)
{
    this->id = ad.id;
    this->templateId = ad.templateId;
    this->startTime = ad.startTime;
    this->endTime = ad.endTime;
    this->state = ad.state;
    this->index = ad.index;
    this->adResources = ad.adResources;
}

Ad::Ad(int templateId, int index, const QString &startTime, const QString &endTime, int state) : templateId(templateId),
    index(index),
    startTime(startTime),
    endTime(endTime),
    state(state)
{}
