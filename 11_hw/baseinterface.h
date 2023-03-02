#ifndef BASEINTERFACE_H
#define BASEINTERFACE_H

#include <QSqlDatabase>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include "task.h"

class BaseInterface: public QObject{
    Q_OBJECT
public:
    explicit BaseInterface(QObject *parent = nullptr);
    ~BaseInterface();
    bool createConection();
    bool createTable();
    bool insertRecord(Task task);
    void print();
protected:
    QSqlDatabase data_base;
    QString base_name;
};

#endif // BASEINTERFACE_H
