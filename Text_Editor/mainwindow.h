#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    QString get_html(const QString& url);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_infoButton_clicked();

    void on_second_tsuck_clicked();

private:
    QString filename;
    QString filepath;
//    QString text;
    QString info_file_path =":/res/ress/info.txt";

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
