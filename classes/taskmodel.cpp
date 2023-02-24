#include "taskmodel.h"

TaskModel::TaskModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

//QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    return task_list.size();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
        case Qt::DisplayRole:
            return task_list.at(index.row()).toString();
        default:
            return QVariant();
    }
}

bool TaskModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
        task_list.replace(index.row(), qvariant_cast<Task>(value));
    return true;
}

Qt::ItemFlags TaskModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled| Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

void TaskModel::addTask(const Task &task)
{
    beginInsertRows(QModelIndex(),task_list.size(),task_list.size() + 1);
    task_list.append(task);
    endInsertRows();
}

void TaskModel::deleteTask(const QModelIndex &index)
{
    task_list.removeAt(index.row());

}
