#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QVariant>

class Task
{
public:
    Task();
    Task(const Task& );
    Task(QString a, QDate b, int c): name(a), deadline(b), progres(c){}
    void incrementProgres();
    QString toString() const;

    const QString &getName() const;
    void setName(const QString &newName);

    const QDate &getDeadline() const;
    void setDeadline(const QDate &newDeadline);

    int getProgres() const;
    void setProgres(int newProgres);

protected:
    QString name;
    QDate deadline;
    int progres;
};

Q_DECLARE_METATYPE(Task);

#endif // TASK_H
