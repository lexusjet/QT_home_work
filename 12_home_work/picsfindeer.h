#ifndef PICSFINDEER_H
#define PICSFINDEER_H

#include <QObject>
#include <QUrl>

class PicsFindeer : public QObject
{
    Q_OBJECT
public:
    explicit PicsFindeer(QObject *parent = nullptr);

    void find(QString);

signals:
    void referenceFound(QUrl);
    void error();

public slots:


private:
    void douwnloadHtml(QString);
    void findeReferense();

private:
    QString html;
};

#endif // PICSFINDEER_H
