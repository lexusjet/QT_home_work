#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include <QShortcut>
#include "Comands.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QPushButton * ptr_button;
    //QString get_html(const QString& url);
    //QStringList find_wether(QString & text);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_infoButton_clicked();

    void on_second_tsuck_clicked(){};

    void on_ReadOnlybutton_clicked();



protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    QString filename;
    QString filepath;
    InvokerConad invocker;
    QString info_file_path =":/res/ress/info.txt";
    bool read_only;
    ComandsReceiver reciver;

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
