#include "adlogic.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "addao.h"
#include "ad.h"
#include "fileutil.h"
#include <QFileInfo>
#include "adresourcedao.h"
#include "adresource.h"
#include <QFile>

AdLogic::AdLogic(QObject *parent) : QObject(parent)
{

}

void AdLogic::dealAdPlayList(QByteArray adStr)
{

    QList<Ad> ads = this->adListParse(adStr);

    AdDao dao;
    FileUtil fileUtil;
    AdResouceDao arDao;

    for(Ad ad : ads)
    {

        Ad* adByDb = dao.findById(ad.getId());


        if(adByDb == nullptr)
        {
            dao.add(ad);

            QList<AdResource> * ars = ad.getAdResources();
            for(AdResource ar : *ars)
            {

                QFileInfo fileInfo(ar.getUrl());
                QString localPath = "D:/File/RH/adv/%1_%2";
                localPath = localPath.arg(ad.getId()).arg(fileInfo.fileName());
                qDebug() << "localPath:" <<localPath;

                fileUtil.downloadFile(ar.getUrl(),localPath);

                // 并且将这些信息存入数据库
                ar.setLocalPath(localPath);
                arDao.add(ar);
            }
        }
        else{

            dao.update(ad); // 把广告信息都改一下
            arDao.deleteByAdId(ad.getId());
            QList<AdResource> * ars = ad.getAdResources();
            for(AdResource ar : *ars)
            {
                QString remoteSign = ar.getSign();


                QFileInfo fileInfo(ar.getUrl());
                QString localPath = "D:/File/RH/adv/%1_%2";
                localPath = localPath.arg(ad.getId()).arg(fileInfo.fileName());

                QFile file(localPath);
                // 如果本次甲方的广告是之前完全没有的，是一个全新的，那么本次就也不会做判断，而是直接下载
                if(!file.exists())
                {
                    qDebug() << "之前的文件不存在";
                    fileUtil.downloadFile(ar.getUrl(),localPath);
                }else{
                    // 这个文件之前也有，但是本次不知道它是否有修改过，所以要判断sign
                    QString localSign = FileUtil::aesFile(localPath);
                    if(remoteSign != localSign)
                    {
                        fileUtil.downloadFile(ar.getUrl(),localPath);
                        qDebug() << "本次重新下载文件,就是sign不相等";
                    }
                }
                // 怎么把adResouce的数据存入数据库？
                // 这个地方我们要考虑这个广告里面它的资源文件，哪些要在数据库修改，哪些需要再数据库新增
                ar.setLocalPath(localPath);
                arDao.add(ar);
            }
        }
    }

    // 广告列表发生改变，要不要通知主进程去更改媒体的播放列表 QMediaPlayer
    //3 搞一个定时器，比如每天晚上凌晨12:30，去定时删除已经过期的广告
}

QList<Ad> AdLogic::adListParse(QByteArray adStr)
{
    QList<Ad> ads;
    QJsonDocument doc = QJsonDocument::fromJson(adStr);
    if(doc.isArray())
    {
        QJsonArray adList = doc.array();
        for(int i=0;i<adList.size();i++)
        {
            QJsonObject adObj = adList.at(i).toObject();
            // 获取广告的基本信息
            int id = adObj.value("id").toInt();
            int templateId = adObj.value("template_id").toInt();
            QString startTime = adObj.value("start_time").toString();
            QString endTime = adObj.value("end_time").toString();
            int state = adObj.value("state").toInt();

            Ad ad(id,templateId,i+1,startTime,endTime,state);

            QList<AdResource> *adResources = new QList<AdResource>;
            // 假设6是上下分屏
            if(templateId == 6)
            {
                // 这是先处理上半部分的资源信息
                int adId = ad.getId();
                int typeId = adObj.value("top_media_type_id").toInt();
                int index = 1;
                QString url = adObj.value("top_media_url").toString();
                QString sign = adObj.value("top_media_sign").toString();
                AdResource arTop (adId,typeId,index,url,"",sign);

                // 处理下半部分的资源信息
                int adId1 = ad.getId();
                int typeId1 = adObj.value("buttom_media_type_id").toInt();
                int index1 = 2;
                QString url1 = adObj.value("buttom_media_url").toString();
                QString sign1 = adObj.value("buttom_media_sign").toString();
                AdResource arButtom(adId1,typeId1,index1,url1,"",sign1);

                adResources->push_back(arTop);
                adResources->push_back(arButtom);
            }

            ad.setAdResources(adResources);
            ads.push_back(ad);
        }
    }
    return ads;
}
