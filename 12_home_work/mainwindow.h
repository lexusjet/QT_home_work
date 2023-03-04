#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>

#include "downloader.h"
#include "picsfindeer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Downloader* downloader;
    QProgressBar * progress_bar;
    QLineEdit * line_edit;
    QPushButton * button;
    PicsFindeer* finder;

    void showPic(const QString&);

private slots:
    void slotGo();
    void slotError();
    void slotDownlouadProgress(qint64, qint64);
    void sloteDone(const QUrl&, const QByteArray&);


//=========================================================================================

};

#endif // MAINWINDOW_H
