#include "taskadderdialog.h"
#include "taskadderdialog.h"
#include "ui_taskadderdialog.h"
#include <QMessageBox>

TaskAdderDialog::TaskAdderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskAdderDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

TaskAdderDialog::~TaskAdderDialog()
{
    delete ui;
}

void TaskAdderDialog::on_pushButton_2_clicked()
{

}

void TaskAdderDialog::on_addTuskButton_clicked()
{
    Task a;
    a.setName(ui->lineEditName->text());
    a.setDeadline(QDate::fromString(ui->lineEditDate->text(), "dd.MM.yyyy"));
    a.setProgres((ui->lineEditProgress->text().toInt()));
    if(validate(a)){
        emit taskadded(a);
        this->close();
    }
    else{
        QMessageBox::information(this, "","Incoret input");
    }
}

bool TaskAdderDialog::validate(Task task)
{
    if(!task.getName().size()) return false;
    if(!task.getDeadline().isValid()) return false;
    if(task.getProgres() > 9) return false;
    return true;
}
