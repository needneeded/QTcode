#include "addao.h"
#include <QDebug>

AdDao::AdDao()
{
    // 加载数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE","ad-add-connection");
    db.setDatabaseName("D:/Qt/qtCode/ads.db");
    this->isOpen = db.open();
}

void AdDao::add(Ad ad)
{


    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "insert into t_ad(id,`index`,template_id,start_time,end_time,state) values(?,?,?,?,?,?)";
    QSqlQuery query(db);
    query.prepare(sql); // 预编译sql
    query.bindValue(0,ad.getId());
    query.bindValue(1,ad.getIndex());
    query.bindValue(2,ad.getTemplateId());
    query.bindValue(3,ad.getStartTime());
    query.bindValue(4,ad.getEndTime());
    query.bindValue(5,ad.getState());
    qDebug() <<sql;

    if(query.exec())
    {
        qDebug() << "新增成功";
    }else{
        qDebug() << "新增失败" << query.lastError().text();
    }
}

void AdDao::update(Ad ad)
{
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "update t_ad set `index` = ?,template_id=?,start_time=?,end_time=?,state = ? where id = ?";
    QSqlQuery query(db);
    query.prepare(sql); // 预编译sql
    query.bindValue("id",ad.getId());
    query.bindValue("index",ad.getIndex());
    query.bindValue("template_id",ad.getTemplateId());
    query.bindValue("start_time",ad.getStartTime());
    query.bindValue("end_time",ad.getEndTime());
    query.bindValue("state",ad.getState());

    if(query.exec())
    {
        qDebug() << "修改成功";
    }else{
        qDebug() << "修改失败" << query.lastError().text();
    }
}

void AdDao::deleteById(int id)
{
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return;
    }

    QString sql = "delete from t_ad where id = ";
    sql.append(QString::number(id));
    QSqlQuery query(sql,db);

    if(query.exec())
    {
        qDebug() << "删除成功";
    }else{
        qDebug() << "删除失败" << query.lastError().text();
    }
}

Ad* AdDao::findById(int id)
{
    Ad *ad = nullptr;
    if(!this->isOpen)
    {
        qDebug() << "数据库打开失败" << db.lastError().text();
        return ad;
    }

    QString sql = "select * from t_ad where id = ";
    sql.append(QString::number(id));
    qDebug() << "sql语句:" <<sql;
    QSqlQuery query(sql,db);

    if(!query.exec())
    {
        qDebug() << "查询失败" << query.lastError().text();
        return ad;
    }
    // 封装查询后的数据
    while(query.next())
    {
        int id = query.value("id").toInt();
        int index = query.value("index").toInt();
        int templateId = query.value("template_id").toInt();
        QString startTime = query.value("start_time").toString();
        QString endTime = query.value("end_time").toString();
        int state = query.value("state").toInt();

        ad = new Ad(id,templateId,index,startTime,endTime,state);
    }
    return ad;
}
