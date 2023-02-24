#include "tasksmodel.h"
#include <QVariant>
#include <QDate>

TasksModel::TasksModel(QObject *parent):
    QAbstractListModel(parent)
{

}

int TasksModel::rowCount(const QModelIndex &parent) const
{
    return task_list.count();
}

QVariant TasksModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
        case Qt::DisplayRole:
            return task_list.at(index.row()).toString();
        default:
            return QVariant();
    }
}

bool TasksModel::setData(const QModelIndex &index, const QVariant & value, int role)
{
    bool flag = true;
    if(!index.isValid()) flag = false;
    if(role == Qt::EditRole)
        task_list.replace(index.row(), qvariant_cast<Task>(value));
    return flag;
}

Qt::ItemFlags TasksModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void TasksModel::addNewTask(const Task& task)
{
    task_list.append(task);
}

void TasksModel::dleteTask(QModelIndex & index)
{
    if(index.isValid())
        task_list.removeAt(index.row());
}
