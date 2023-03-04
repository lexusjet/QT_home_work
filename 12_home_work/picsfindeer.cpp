#include "picsfindeer.h"
#include <QRegExp>
#include <QDebug>
#include <QFile>

PicsFindeer::PicsFindeer(QObject *parent) : QObject(parent)
{

}

void PicsFindeer::douwnloadHtml(QString)
{
    QFile file("D:/studies/courses(c++)/qt_creator/text_editor/QT_home_work/12_home_work/test.html");

    if(!file.open(QIODevice::ReadOnly| QIODevice::Text)){
        qDebug()<<"Open problem";
        return;
    }
    QByteArray data = file.readAll();
    html = QString::fromLocal8Bit(data);
    if(!html.size()) qDebug()<<"no text";
}

void PicsFindeer::findeReferense()
{
    QRegExp img("<img class=\"serp-item__thumb justifier__thumb\" src=\"([^>\"]*)");

    QStringList list;
    int pos = 0;
    for(size_t i = 0; i < 3; i++){
        pos = img.indexIn(html, pos);
        pos++;
        if(pos > -1){
            qDebug()<<img.cap(1);
            emit  referenceFound(QUrl(img.cap()));
        }
        else{
            qDebug()<<"Break";
            break;
        }
    }
}

void PicsFindeer::find(QString word)
{
    QString url = "https://yandex.ru/images/search?text=" + word;
    douwnloadHtml(url);
    findeReferense();

}
