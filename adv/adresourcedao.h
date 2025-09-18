#ifndef ADRESOUCEDAO_H
#define ADRESOUCEDAO_H

#include "adresource.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class AdResouceDao
{
public:
    AdResouceDao();

    void add(AdResource ar);
    void update(AdResource ar);
    void deleteByAdId(int adId);
    QList<QString> selectResource(int index);

private:
    QSqlDatabase db;
    bool isOpen;
};

#endif // ADRESOUCEDAO_H
