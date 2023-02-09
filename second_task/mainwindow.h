#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "programlanguage.h"
#include "qlistmodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QList<ProgramLanguage>* values;
    QListModel* model;
};
#endif // MAINWINDOW_H
