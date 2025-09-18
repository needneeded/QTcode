#include "adresourcedao.h"
#include <QDebug>

AdResouceDao::AdResouceDao()
{
    // 加载数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE","ad-resource-connection");
    db.setDatabaseName("D:/Qt/qtCode/ads.db");
    this->isOpen = db.open();
}

void AdResouceDao::add(AdResource ar)
{
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "insert into t_ad_resource(ad_id,type_id,`index`,url,localPath,sign) values(?,?,?,?,?,?)";
    QSqlQuery query(db);
    query.prepare(sql); // 预编译sql
    query.bindValue(0,ar.getAdId());
    query.bindValue(1,ar.getTypeId());
    query.bindValue(2,ar.getIndex());
    query.bindValue(3,ar.getUrl());
    query.bindValue(4,ar.getLocalPath());
    query.bindValue(5,ar.getSign());
    qDebug() << ar.getLocalPath();

    if(query.exec())
    {
        qDebug() << "新增成功";
    }else{
        qDebug() << "新增失败" << query.lastError().text();
    }
}

void AdResouceDao::update(AdResource ar)
{
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "update t_ad_resource set ad_id = ?,type_id = ?,`index` = ?,url = ?,localPath = ?,sign = ? where id = ?";
    QSqlQuery query(db);
    query.prepare(sql); // 预编译sql
    query.bindValue(0,ar.getAdId());
    query.bindValue(1,ar.getTypeId());
    query.bindValue(2,ar.getIndex());
    query.bindValue(3,ar.getUrl());
    query.bindValue(4,ar.getLocalPath());
    query.bindValue(5,ar.getSign());
    query.bindValue(6,ar.getId());

    if(query.exec())
    {
        qDebug() << "修改成功";
    }else{
        qDebug() << "修改失败" << query.lastError().text();
    }
}

void AdResouceDao::deleteByAdId(int adId)
{
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "delete from t_ad_resource where ad_id = ";
    sql.append(QString::number(adId));
    QSqlQuery query(sql,db);

    if(query.exec())
    {
        qDebug() << "删除成功";
    }else{
        qDebug() << "删除失败" << query.lastError().text();
    }
}

QList<QString> AdResouceDao::selectResource(int index)
{
    QList<QString> list;
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return list;
    }

    QString sql = "SELECT localPath FROM t_ad_resource WHERE `index` = %1 ORDER BY ad_id";
    sql = sql.arg(QString::number(index));
    // qDebug()<<"sql:  "<<sql;
    QSqlQuery query(sql,db);
    if(query.exec())
    {
        qDebug() << "查询成功";
    }else{
        qDebug() << "查询失败" << query.lastError().text();
    }
    while(query.next())
    {
        list.push_back(query.value("localPath").toString());
    }
    return list;
}
