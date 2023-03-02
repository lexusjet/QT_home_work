#include "task.h"

Task::Task()
{

}

Task::Task(const Task &b)
{
    name = b.name;
    deadline = b.deadline;
    progres = b.progres;
}

void Task::incrementProgres()
{
    progres++;
}

QString Task::toString() const
{
    QString anser;
    anser += name;
    anser +=" ";

    anser += QString::number(deadline.day());
    anser +=".";
    anser += QString::number(deadline.month()).size() == 1 ? ("0" + QString::number(deadline.month())) : (QString::number(deadline.month()));
    anser +=".";
    anser += QString::number(deadline.year());
    anser +=" ";
    anser += QString::number(progres);

    return anser;
}

const QString &Task::getName() const
{
    return name;
}

void Task::setName(const QString &newName)
{
    name = newName;
}

const QDate &Task::getDeadline() const
{
    return deadline;
}

void Task::setDeadline(const QDate &newDeadline)
{
    deadline = newDeadline;
}


int Task::getProgres() const
{
    return progres;
}

void Task::setProgres(int newProgres)
{
    progres = newProgres;
}


