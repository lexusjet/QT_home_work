#include "picsfindeer.h"
#include <QRegExp>
#include <QDebug>
#include <QFile>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>

PicsFindeer::PicsFindeer(QObject *parent) : QObject(parent)
{

}

void PicsFindeer::douwnloadHtml(QUrl url)
{

    qDebug()<< "Addres: " << url.toString();
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(url));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    html = response->readAll();
}

void PicsFindeer::findeReferense()
{
//    QRegExp img("<img class=\"serp-item__thumb justifier__thumb\" src=\"([^>\"]*)");
    QRegExp img ("\"url\":\"(https:[^>\"]*)\"");
    QStringList list;
    int pos = 0;
    for(size_t i = 0; i < 3; i++){
        pos = img.indexIn(html, pos);
        pos++;
        if(pos > -1){
            emit referenceFound(QUrl(img.cap(1)));
//            emit  referenceFound(QUrl("https:" + img.cap(1)));
        }
        else{
            qDebug()<<"Break";
            break;
        }
    }
}

void PicsFindeer::find(QString word)
{
    QUrl url("https://yandex.ru/images/search?text=" + word);
    douwnloadHtml(url);
    findeReferense();

}
