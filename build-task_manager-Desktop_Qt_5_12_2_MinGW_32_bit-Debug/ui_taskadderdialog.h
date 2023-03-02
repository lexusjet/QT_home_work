/********************************************************************************
** Form generated from reading UI file 'taskadderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKADDERDIALOG_H
#define UI_TASKADDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskAdderDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *lineEditName;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditDate;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEditProgress;
    QHBoxLayout *horizontalLayout;
    QPushButton *addTuskButton;

    void setupUi(QDialog *TaskAdderDialog)
    {
        if (TaskAdderDialog->objectName().isEmpty())
            TaskAdderDialog->setObjectName(QString::fromUtf8("TaskAdderDialog"));
        TaskAdderDialog->resize(400, 202);
        verticalLayout_6 = new QVBoxLayout(TaskAdderDialog);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(TaskAdderDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        lineEditName = new QLineEdit(TaskAdderDialog);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        verticalLayout_3->addWidget(lineEditName);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(TaskAdderDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEditDate = new QLineEdit(TaskAdderDialog);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));

        verticalLayout_2->addWidget(lineEditDate);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(TaskAdderDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEditProgress = new QLineEdit(TaskAdderDialog);
        lineEditProgress->setObjectName(QString::fromUtf8("lineEditProgress"));

        verticalLayout->addWidget(lineEditProgress);


        verticalLayout_4->addLayout(verticalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addTuskButton = new QPushButton(TaskAdderDialog);
        addTuskButton->setObjectName(QString::fromUtf8("addTuskButton"));

        horizontalLayout->addWidget(addTuskButton);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(TaskAdderDialog);

        QMetaObject::connectSlotsByName(TaskAdderDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskAdderDialog)
    {
        TaskAdderDialog->setWindowTitle(QApplication::translate("TaskAdderDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("TaskAdderDialog", "Task name", nullptr));
        label_2->setText(QApplication::translate("TaskAdderDialog", "Task finish date", nullptr));
        label_3->setText(QApplication::translate("TaskAdderDialog", "Progress", nullptr));
        addTuskButton->setText(QApplication::translate("TaskAdderDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskAdderDialog: public Ui_TaskAdderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKADDERDIALOG_H
