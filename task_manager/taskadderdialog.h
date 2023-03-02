#ifndef TASKADDERDIALOG_H
#define TASKADDERDIALOG_H

#include <QDialog>
#include "task.h"

namespace Ui {
class TaskAdderDialog;
}

class TaskAdderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskAdderDialog(QWidget *parent = nullptr);

    ~TaskAdderDialog();
    bool validate(Task task);
signals:
    void taskadded(Task task);
    void closed();

private slots:
    void on_pushButton_2_clicked();
    void on_addTuskButton_clicked();


private:
    Ui::TaskAdderDialog *ui;
};

#endif // TASKADDERDIALOG_H
