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
//    Task(QString& name, QString& date, QString& )
    void incrementProgres();
    QString toString() const;

    const QString &getName() const;
    void setName(const QString &newName);

    const QDate &getDeadline() const;
    void setDeadline(const QDate &newDeadline);

    uint8_t getProgres() const;
    void setProgres(uint8_t newProgres);

protected:
    QString name;
    QDate deadline;
    uint8_t progres;
};

Q_DECLARE_METATYPE(Task);

#endif // TASK_H
