#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include <QShortcut>
#include "Comands.h"
#include  <QPrinter>
#include <QtPrintSupport>


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

private:
    QString filename;
    QString filepath;
    InvokerConad invocker;
    QString info_file_path =":/res/ress/info.txt";
    bool read_only;
    ComandsReceiver reciver;
    QTranslator translator;


private:
    QTextDocument text_document;
    QTextBlockFormat default_block_format;
    QTextCharFormat default_text_format;

    QTextCharFormat buffer_char_format;
    QTextBlockFormat buffer_block_format;

private:
    Ui::MainWindow *ui;
    QToolBar* toolbar;


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_infoButton_clicked();

    void on_second_tsuck_clicked(){};

    void on_ReadOnlybutton_clicked();



    void on_actionDark_triggered();

    void on_actionLight_triggered();

    void on_actionSave_file_as_triggered();

    void on_actionOpen_file_triggered();

    void on_actionRussian_triggered();

    void on_actionEanglish_triggered();

    void on_actionPrint_file_triggered();

    void text_format();
    void copy_format();
    void set_format();
    void set_alignment();

    void insert_date();
    void insert_time();
protected:
    void keyPressEvent(QKeyEvent* event) override;



};
#endif // MAINWINDOW_H
