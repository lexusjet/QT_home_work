#ifndef TASKCONTROLER_H
#define TASKCONTROLER_H

#include <QObject>
#include <QString>
#include "baseinterface.h"
#include <QSqlTableModel>
class TaskControler : public QObject
{
    Q_OBJECT
public:
    explicit TaskControler(QObject *parent = nullptr);

    Q_INVOKABLE void addTask(Task task);

    void setBase(BaseInterface *value);

    QSqlTableModel *getModel() const;
    void setModel(QSqlTableModel *value);

signals:

private:
    //    BaseReader* basereader;

    BaseInterface* base_interface;
    QSqlTableModel *model;
public slots:
};

#endif // TASKCONTROLER_H
