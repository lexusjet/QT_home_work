#include "taskcontroler.h"
#include <QDebug>
#include <QStringList>
TaskControler::TaskControler(QObject *parent) : QObject(parent)
{

}

void TaskControler::addTask(QString task)
{
    QStringList buf  = task.split(" ");
    Task a;
    a.setName(buf[0]);
    a.setDeadline(QDate::fromString(buf[1], Qt::RFC2822Date));
    a.setProgres(buf[2].toInt());
    basereader->writeNewTask(a);
}

BaseReader *TaskControler::getBase() const
{
    return basereader;
}

void TaskControler::setBase(BaseReader *value)
{
    basereader = value;
}
