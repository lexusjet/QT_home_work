#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"

#include "qlistmodel.h"
#include "listviewitemdelegate.h"
#include "listviewitemdelegateicons.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    values = new QList<ProgramLanguage>;

    values->append(ProgramLanguage("С++","c++.png"));
    values->append(ProgramLanguage("Python","python.png"));
    values->append(ProgramLanguage("Java","java.png"));
    values->append(ProgramLanguage("C#","c-sharp.png"));
    values->append(ProgramLanguage("PHP","php.png"));
    values->append(ProgramLanguage("JavaScript","js.png"));
    values->append(ProgramLanguage("",""));

    model = new QListModel();
    model->populate(values);

    this->ui->listView->setItemDelegate(new ListViewItemDelegate);
    this->ui->listView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAdd_clicked()
{
   model->append(ProgramLanguage("name", "default.png"));
}


void MainWindow::on_pushButtonDelete_clicked()
{
    model->delete_row(ui->listView->currentIndex().row());
}


void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()){
        ui->listView->setViewMode(QListView::IconMode);
        ui->listView->setItemDelegate(new ListViewItemDelegateIcons);
    }
    else{
        ui->listView->setViewMode(QListView::ListMode);
        ui->listView->setItemDelegate(new ListViewItemDelegate);
    }

}

