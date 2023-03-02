#include "taskcontroler.h"
#include <QDebug>
#include <QStringList>
#include <QSqlRecord>

TaskControler::TaskControler(QObject *parent) : QObject(parent)
{

}

void TaskControler::addTask(Task task)
{
    base_interface->insertRecord(task);
    QSqlRecord record  = model->record();
    record.remove(record.indexOf("id"));
    record.setValue("name", task.getName());
    record.setValue("date", task.getDeadline().toString("dd.MM.yyyy"));
    record.setValue("progres", QString::number(task.getProgres()));
    if(model->insertRecord(-1, record))
        model->submitAll();
}




void TaskControler::setBase(BaseInterface *value)
{
    base_interface = value;

}

QSqlTableModel *TaskControler::getModel() const
{
    return model;
}

void TaskControler::setModel(QSqlTableModel *value)
{
    model = value;
}
