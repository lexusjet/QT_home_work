#ifndef TASKSMODEL_H
#define TASKSMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>

#include "task.h"

class TasksModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TasksModel(QObject *parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex&index , int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

public:
    void addNewTask(const Task&);
    void dleteTask(QModelIndex& index);

protected:
    QList<Task> task_list;
};

#endif // TASKSMODEL_H
