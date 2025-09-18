#ifndef CMDLOGIC_H
#define CMDLOGIC_H

#include <QObject>

class CmdLogic : public QObject
{
    Q_OBJECT
private:
    static CmdLogic *instance;
    explicit CmdLogic(QObject *parent = nullptr);
public:
    static CmdLogic* getInstance();

    void execute(QByteArray cmdStr);

    void executeCmd(QString cmd);
signals:

};

#endif // CMDLOGIC_H
