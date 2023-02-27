#include "basereader.h"
#include <QDataStream>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <QDebug>

// load base
// add new task
// get new task
// remove task()


BaseReader::BaseReader(QObject *parent) : QObject(parent)
{

}

BaseReader::~BaseReader()
{
    file->close();
}


void BaseReader::loadBase(QString path)
{
    file = new QFile(path); // Файл с данными
    // о городах
    if (!file) return;
    if(file->open(QIODevice::WriteOnly)) qDebug() << "agag";
    file->close();

}

QList<Task> BaseReader::getData()
{
    file->open(QIODevice::ReadOnly);
    if(file->isOpen()) qDebug()<<"aaaa1";
    QList<Task> list;
    Task task;
    QTextStream stream(file);
    while(!stream.atEnd())
    {
        QStringList buf = stream.readLine().split(" ");
        task.setName(buf[0]);
        task.setDeadline(QDate::fromString(buf[1], Qt::RFC2822Date));
        task.setProgres(buf[2].toInt());
        list.append(task);
    }
    file->close();
    return list;
}


void BaseReader::writeNewTask(Task task)
{
    file->open(QIODevice::WriteOnly);
    if(file->isOpen()) qDebug()<<"aaaa2";
    QTextStream stream(file);
    stream << task.toString() << endl;
    file->close();
}

//void BaseReader::getNextRecord()
//{
//    if (file->atEnd()) return;
//    QDataStream stream(file);
//    int len = 0;
//    stream.readRawData((char*)&len, sizeof len);
//    QByteArray b;
//    b.resize(len);
//    stream.readRawData(b.data(), len);
//    QString town = QString::fromUtf8(b);
//    stream.readRawData((char*)&len, sizeof len);
//    b.resize(len);
//    stream.readRawData(b.data(), len);
//    QString info = QString::fromUtf8(b);
//    emit loadTask(town, info);
//}
//void BaseReader::writeNewInformation(QString Task, QString info)
//{
//    QDataStream stream(file);
//    auto bytes = Task.toUtf8();
//    int len = bytes.length();
//    stream.writeRawData((char*)&len, sizeof len);
//    stream.writeRawData(bytes.data(), len);
//    bytes = info.toUtf8();
//    len = bytes.length();
//    stream.writeRawData((char*)&len, sizeof len);
//    stream.writeRawData(bytes.data(), len);
//}
