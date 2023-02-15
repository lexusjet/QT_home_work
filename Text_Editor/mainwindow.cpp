#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

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


void MainWindow::on_pushButton_2_clicked(){}


void MainWindow::on_pushButton_clicked(){}

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

void MainWindow::on_ReadOnlybutton_clicked()
{
    bool mode = true;
    if(ui->plainTextEdit->isReadOnly()) mode = false;
    ui->plainTextEdit->setReadOnly(mode);
}


void MainWindow::on_actionDark_triggered()
{
    qApp->setStyleSheet(
        "QMainWindow{"
            "background-color:rgb(177,176,185)}"
        "QPushButton{"
            "background-color: rgb(128,128,128);"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: rgb(0,0,0);"
            "font: bold 14px;"
            "min-width: 10em;"
            "padding: 6px;}"
        "QPushButton::selected{"
            "background-color: rgb(224, 0, 0);"
            "border-style: inset;}"
        "QPushButton::pressed{"
            "background-color: rgb(224, 224, 224);"
            "border-style: inset;}");
}


void MainWindow::on_actionLight_triggered()
{
    qApp->setStyleSheet("QPushButton{"
                        "background-color: rgb(224,224,224);"
                        "border-style: outset;"
                        "border-width: 2px;"
                        "border-radius: 10px;"
                        "border-color: rgb(0,0,0);"
                        "font: bold 14px;"
                        "min-width: 10em;"
                        "padding: 6px;}");
}


void MainWindow::on_actionSave_file_as_triggered()
{
    invocker.set_comand(new ComandSave(&reciver, filepath));
    invocker.exec_comand();
}


void MainWindow::on_actionOpen_file_triggered()
{
    invocker.set_comand(new ComandOpenFile(&reciver, filepath));
    invocker.exec_comand();
}


void MainWindow::on_actionRussian_triggered()
{
    translator.load(":/rus_language/QtLanguage_ru.qm");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}


void MainWindow::on_actionEanglish_triggered()
{
    translator.load("");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

void MainWindow::on_actionPrint_file_triggered()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(tr("Print"));
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString printStr = ui->plainTextEdit->toPlainText();
    QChar *list = printStr.data();
    QStringList strlst;
    int line = 0, cursor = 0;
    for (bool getst = true;getst;){
        int index = printStr.indexOf("\n", cursor); // Ищем перевод каретки
        // на новую строку
        QString s = "";
        if (index == -1){
            getst = false;
            s.append(&list[cursor], printStr.length() - cursor);
        }
        else s.append(&list[cursor], index - cursor);
        cursor = index + 1;
        strlst << s;
    }

    QPainter painter;
    painter.begin(&printer);
    int w = painter.window().width();
    int h = painter.window().height();
    int amount = strlst.count();
    QFont font = painter.font();
    QFontMetrics fmetrics(font);
    for (int i = 0; i < amount; i++){
        QPointF pf;
        pf.setX(10);
        pf.setY(line);
        painter.drawText(pf, strlst.at(i));
        line += fmetrics.height();
        if (h - line <= fmetrics.height()){
            printer.newPage();
            line = 0;
        }
    }
    painter.end();

    ui->plainTextEdit->print(&printer);
}



