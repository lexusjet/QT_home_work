#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>


#include <QtNetwork>
#include <QDebug>


//Ваш первый проект на данном курсе - текстовый редактор.
//
//да    Добавьте на форму виджет текстового редактора.
//да    Добавьте две кнопки: сохранить и открыть.
//да    Предоставьте возможность пользователю выбрать куда сохранять файл и какой файл открывать.
//да    Добавьте в текстовый редактор справку. Текстовый файл с описанием разместить в ресурсах программы.
//нет    Для вызова справки разместить на форме соответствующую кнопку.



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Пример фильтра", QDir::currentPath(), "Text(*.txt);");
    if(path.size() == 0) return;
    QFile text_file(path);
    if(!text_file.open(QIODevice::ReadOnly)) return;

    QTextStream stream(&text_file);
    QString text = stream.read(text_file.size());
    ui->plainTextEdit->setPlaceholderText(text);

    filename = text_file.fileName();
    text_file.close();
}


void MainWindow::on_pushButton_clicked()
{
   QString path = QFileDialog::getSaveFileName(this,  "Пример фильтра", QDir::currentPath(), "Text(*.txt);");
   if(path.size() == 0) return ;
   QFile text_file(path);
   if(text_file.open(QIODevice::WriteOnly)){
       QTextStream stream(&text_file);
       stream<< ui->plainTextEdit->toPlainText();
   }


   text_file.close();
}

void MainWindow::on_infoButton_clicked()
{
    QFile info_file(info_file_path);
    info_file.open(QIODevice::ReadOnly);
    QTextStream stream(&info_file);
    ui->plainTextEdit->setPlainText(QString(stream.read(info_file.size())));
    info_file.close();
}


void MainWindow::on_second_tsuck_clicked()
{
    QString url = "https://mail.ru/";
    url = "https://dzen.ru/";
    url = "https://yandex.ru";
    QString  html = get_html(url);
    if(html.isEmpty()){
        ui->plainTextEdit->setPlainText("Ошибка");
        return;
    }
//    QStringList data = getData(html);
    ui->plainTextEdit->setPlainText(html);
}

QString MainWindow::get_html(const QString &url)
{
    QNetworkAccessManager manager;
    qDebug() << url;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    qDebug() << url;
    QEventLoop event;
    qDebug() << url;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    response->deleteLater();
    return response->readAll();
}

