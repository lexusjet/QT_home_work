#ifndef TASKCONTROLER_H
#define TASKCONTROLER_H

#include <QObject>
#include <QString>
#include "basereader.h"

class TaskControler : public QObject
{
    Q_OBJECT
public:
    explicit TaskControler(QObject *parent = nullptr);
    Q_INVOKABLE void addTask(QString task);

    BaseReader *getBase() const;
    void setBase(BaseReader *value);

signals:

private:
    BaseReader* basereader;
public slots:
};

#endif // TASKCONTROLER_H
