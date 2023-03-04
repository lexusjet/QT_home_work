#include "downloader.h"
#include <QNetworkReply>
#include <QDebug>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    pnam = new QNetworkAccessManager(this);
    connect(pnam, &QNetworkAccessManager::finished, this , &Downloader::slotFinished);
//    connect(pnam, SIGNAL(finished(QNetworkReply*)), SLOT(slotFinished(QNetworkReply*)));
}

void Downloader::download(const QUrl & url)
{
    QNetworkRequest request (url);
    QNetworkReply* reply  = pnam->get(request);
    connect(reply, &QNetworkReply::downloadProgress ,this , &Downloader::downloadProgress);
}

void Downloader::slotFinished(QNetworkReply* reply)
{
    if(reply->error() != QNetworkReply::NetworkError::NoError){
        emit error();
        qDebug()<<"NetworkError";
    }
    else {
        emit done(reply->url(), reply->readAll());
    }
    reply->deleteLater();
}
