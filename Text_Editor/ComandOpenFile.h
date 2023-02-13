#ifndef COMANDOPENFILE_H
#define COMANDOPENFILE_H
#include "comand.h"
#include "comandsreceiver.h"
#include <QtCore>

class ComandOpenFile:public Comand
{
public:
   ComandOpenFile(ComandsReceiver* recv, QString& filepath): reciver(recv), path(filepath){};
   void execute() override
   {
       reciver->open_file(path);
   };
protected:
   ComandsReceiver* reciver;
   QString& path;
};
#endif // COMANDOPENFILE_H
