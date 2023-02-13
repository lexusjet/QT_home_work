#ifndef COMANDNEWFILE_H
#define COMANDNEWFILE_H

#include "comand.h"
#include "comandsreceiver.h"
#include <QtCore>

class ComandNewFile:public Comand
{
public:
    ComandNewFile(ComandsReceiver* recv, QString pth):reciver(recv), path(pth){};
    virtual void execute() override
    {
        reciver->save_file_as(path);
    }
private:
    ComandsReceiver* reciver;
    QString path;
};
#endif // COMANDNEWFILE_H
