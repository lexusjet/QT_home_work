#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>

#include "task.h"
// load base
// add new task
// get new task
// remove task()

class BaseReader : public QObject
{
    Q_OBJECT
public:
    explicit BaseReader(QObject *parent = nullptr);
    ~BaseReader();
    void loadBase(QString path= ":/ress/tasks.txt");
    QList<Task> getData();
    void writeNewTask(Task task);
//    void getNextRecord();
//    void writeNewInformation(QString, QString);
private:
    QFile *file;
signals:
    void initEnd(bool succed);
    void loadTask(QString town, QString info);
public slots:
};

#endif // BASEREADER_H
