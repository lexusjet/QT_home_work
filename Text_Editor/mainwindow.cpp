#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>


#include <QtNetwork>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reciver.set_editor(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    invocker.set_comand(new ComandOpenFile(&reciver, filepath));
    invocker.exec_comand();
}


void MainWindow::on_pushButton_clicked()
{
    invocker.set_comand(new ComandSave(&reciver, filepath));
    invocker.exec_comand();
}

void MainWindow::on_infoButton_clicked()
{
    QFile info_file(info_file_path);
    info_file.open(QIODevice::ReadOnly);
    QTextStream stream(&info_file);
    ui->plainTextEdit->setPlainText(QString(stream.read(info_file.size())));
    info_file.close();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() != Qt::ControlModifier) return;
    switch(event->key()){
    case Qt::Key_S:invocker.set_comand(new ComandSave(&reciver, filepath));
        break;
    case Qt::Key_O: invocker.set_comand(new ComandOpenFile(&reciver, filepath));
            break;
    case Qt::Key_N: invocker.set_comand(new ComandNewFile(&reciver, filepath));
        break;
    case Qt::Key_Q: exit(0);
    default:
        return;
    }
    invocker.exec_comand();
}














//void MainWindow::on_second_tsuck_clicked()
//{
//    QString url = "https://mail.ru/";
//    url = "https://dzen.ru/";
//    url = "https://yandex.ru";
//    QString  html = get_html(url);
//    QFile t(":/res/ress/mail_ru.html");

//    if(!t.open(QIODevice::ReadOnly)) return;
//    QTextStream stream(&t);
//    html = stream.read(t.size());

//    if(html.isEmpty()){
//        ui->plainTextEdit->setPlainText("Ошибка");
//        return;
//    }
////    QStringList data = getData(html);
//    QStringList weathe(find_wether(html));
//    ui->plainTextEdit->setPlainText(html);
//}



//QStringList MainWindow::find_wether(QString & text)
//{
//    QStringList wether;
//    QRegExp all_days ("\"(now|near|near\\d)\":\\{"); //("\"(now|near|near\\d)\":{(.*?)}");
//    int pos = 0;
//    pos = all_days.indexIn(text, pos);
//    wether.append(all_days.cap(0));
//    return wether;

//}


//QString MainWindow::get_html(const QString &url)
//{
//    ui->second_tsuck;
//    QNetworkAccessManager manager;
//    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
//    QEventLoop event;
//    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
//    event.exec();
//    response->deleteLater();
//    return response->readAll();
//}


void MainWindow::on_ReadOnlybutton_clicked()
{
    bool mode = true;
    if(ui->plainTextEdit->isReadOnly()) mode = false;
    ui->plainTextEdit->setReadOnly(mode);
}

