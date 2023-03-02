#include "baseinterface.h"
#include <QtDebug>
#include <QSqlRecord>
BaseInterface::BaseInterface(QObject *parent): QObject(parent)
{
    createConection();
}

BaseInterface::~BaseInterface()
{

}

bool BaseInterface::createConection()
{
    data_base= QSqlDatabase::addDatabase("QSQLITE");
    data_base.setDatabaseName("TaskBook.db");
    if(!data_base.open()){
        qDebug()<< "Can't open data base";
        return false;
    }
    else {
        return true;
    }
}

bool BaseInterface::createTable()
{
    QSqlQuery query;
    QString s = "CREATE TABLE  TaskBook("
                "id INTEGER PRIMARY KEY NOT NULL,"
                "name VARCHAR(15),"
                "date VARCHAR(15),"
                "progres INTEGER );";
    if(!query.exec(s)){
        qDebug()<< "Unable to create table";
        return false;
    }
    return true;
}

bool BaseInterface::insertRecord(Task task)
{
    QSqlQuery query;
    QString s = "INSERT INTO TaskBook (name, date, progres) "
                "VALUES('%1', '%2', '%3');";
    QString q = s.arg(task.getName()).arg(task.getDeadline().toString("dd.MM.yyyy")).arg(QString::number(task.getProgres()));
    if(!query.exec(q)){
        qDebug()<<"Unable to insert";
        return false;
    }
    return true;
}

void BaseInterface::print()
{
    QSqlQuery query;
    if(!query.exec("SELECT * FROM TaskBook;")){
        qDebug()<< "unable to print"; return;
    }
    QSqlRecord rec = query.record();
    while(query.next()){
        qDebug() << query.value(rec.indexOf("id")).toInt() <<"\t" <<
                    query.value(rec.indexOf("name")).toString() <<"\t" <<
                    query.value(rec.indexOf("date")).toString() <<"\t" <<
                    query.value(rec.indexOf("progres")).toInt();
    }
}
