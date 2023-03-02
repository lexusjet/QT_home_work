#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "taskcontroler.h"
#include "baseinterface.h"
#include "taskadderdialog.h"
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskButton_clicked();

    void on_pushButton_clicked();

private:

    TaskAdderDialog* task_add_diolog;
    BaseInterface * base_interface;
    TaskControler * task_contoler;
    QSqlTableModel * model;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
