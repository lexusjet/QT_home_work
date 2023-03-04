#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QLabel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    downloader = new Downloader(this);
    progress_bar = new QProgressBar(this);
    line_edit = new QLineEdit(this);
    button = new QPushButton(this);
    finder = new PicsFindeer(this);

    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();


    connect(finder, &PicsFindeer::referenceFound, downloader, &Downloader::download);
    connect(finder, SIGNAL(error()), SLOT(slotError()));
//    connect(downloader, SIGNAL(downloadProgress(qint64 ,qint64)), SLOT(slotDownlouadProgress(qint64, qint64)));
    connect(downloader, SIGNAL(done(const QUrl&, const QByteArray& )), SLOT(sloteDone(const QUrl&, const QByteArray&)));
    connect(downloader, SIGNAL(error()), SLOT(slotError()));
    connect(button ,&QPushButton::clicked, this, &MainWindow::slotGo);

    layout = new QGridLayout(this);
    layout->addWidget(line_edit, 0,0);
    layout->addWidget(button,0,1);
    layout->addWidget(progress_bar, 1,0, 1,2);

    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);
    wgt->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPic(const QString & path)
{
    QPixmap pix(path);
    pix = pix.scaled(pix.size());
//    QMessageBox* a = new QMessageBox(this);
//    a->setIconPixmap(pix);
//    a->show();

    QLabel * label = new QLabel(this);
    label->setPixmap(pix);
    label->setFixedSize(pix.size());
    layout->addWidget(label, 2,i++);
    label->show();
}

void MainWindow::slotGo()
{
    finder->find(line_edit->text());
//    downloader->download(QUrl(line_edit->text()));

}

void MainWindow::slotError()
{
    QMessageBox::critical(this, "Error", "Error!");
}

void MainWindow::slotDownlouadProgress(qint64 recived, qint64 total)
{
    if(total < 0){
        emit slotError();
        qDebug()<<"slotDownlouadProgress";
        return;
    }

    progress_bar->setValue(100*  recived / total);
}

void MainWindow::sloteDone(const QUrl & url, const QByteArray & array)
{
    QFile file(url.path().section('/', -1));
    if(file.open(QIODevice::WriteOnly)){
        file.write(array);
        file.close();
    }
    qDebug()<<"print";
    showPic(file.fileName());
}
