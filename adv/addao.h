#ifndef ADDAO_H
#define ADDAO_H

#include "ad.h"
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>

class AdDao
{
public:
    AdDao();

    void add(Ad ad);
    void update(Ad ad);
    void deleteById(int id);
    Ad* findById(int id);

private:
    QSqlDatabase db;
    bool isOpen;
};

#endif // ADDAO_H
