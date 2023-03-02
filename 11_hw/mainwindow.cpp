#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskadderdialog.h"
#include <QSqlRecord>
// окно с задачами
// добавление задача
// жобавить валидацию
// подсчет всех задач

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    base_interface = new BaseInterface(this);
    base_interface->createTable();

    model = new QSqlTableModel(this);
    model->setTable("TaskBook");
    model->select();

    task_contoler = new TaskControler(this);
    task_contoler->setBase(base_interface);
    task_contoler->setModel(model);

    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTaskButton_clicked()
{}

void MainWindow::on_pushButton_clicked()
{
    task_add_diolog = new TaskAdderDialog(this);
    task_add_diolog->show();
    connect(task_add_diolog, &TaskAdderDialog::taskadded, task_contoler, &TaskControler::addTask);
}
