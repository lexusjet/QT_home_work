#ifndef COMANDSAVE_H
#define COMANDSAVE_H

#include "comand.h"
#include "comandsreceiver.h"
#include <QtCore>

class ComandSave:public Comand
{
private:

public:
    ComandSave(ComandsReceiver* recv, QString pth):reciver(recv), path(pth){};
    virtual void execute() override
    {
        reciver->save_file_as(path);
    }
private:
    ComandsReceiver* reciver;
    QString path;
};

#endif // COMANDSAVE_H
