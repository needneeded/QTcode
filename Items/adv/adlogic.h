#ifndef ADLOGIC_H
#define ADLOGIC_H

#include <QObject>
#include <QList>
#include "ad.h"
#include "adresource.h"

class AdLogic : public QObject
{
    Q_OBJECT
public:
    explicit AdLogic(QObject *parent = nullptr);

    // 处理广告列表
    void dealAdPlayList(QByteArray adStr);
private:
    QList<Ad> adListParse(QByteArray adStr);
};

#endif // ADLOGIC_H
