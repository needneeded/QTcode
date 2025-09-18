#ifndef TCONVERSION_HPP
#define TCONVERSION_HPP
#include <QString>
#include <QStringList>
#include <vector>

class TConversion{
public:
    template<typename T>
    static QString vecToStr(std::vector<T> v)
    {
        QString rst = "";
        for(int i=0;i<v.size();i++)
        {
            rst+=QString::number(v[i]);
            if(i!=v.size()-1)
            {
                rst+=",";
            }
        }
        return rst;
    }

    template<typename T>
    static std::vector<T> strToVec(QString str);

    //全特化
    template<>
    static std::vector<float> strToVec(QString str)
    {
        std::vector<float> rst;
        QStringList strList = str.split(",");
        for(int i=0;i<strList.length();i++)
        {
            float value = strToNum<float>(strList[i]);
            rst.push_back(value);
        }
        return rst;
    }

    template<typename T>
    static T strToNum(QString s);
    //全特化
    template<>
    static float strToNum<float>(QString s)
    {
        return s.toFloat();
    }

};

#endif // TCONVERSION_HPP
