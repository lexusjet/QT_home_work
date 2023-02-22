#ifndef FIRSTMYQTWIDGET_H
#define FIRSTMYQTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QLineEdit>
#include <QTreeWidgetItem>
#include <QTextEdit>
#include <QLabel>
#include "controller.h"


Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class FirstMyQtWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FirstMyQtWidget(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel *getCurrentModel()const{ return model;}
    void setNewModel(QStandardItemModel *newmodel);
    void rebuildModel(QString str);

private:
    QBoxLayout *box_layout;
    QGridLayout *gridLay;
    QTreeView *tree;
    QPushButton *mainPath;
    QComboBox *disckSelBox;
    QLineEdit * line;
    QComboBox *mybox;

    QLineEdit *searchEdit;
    QPushButton *startFindButton;
    Controller *controllerl;

private slots:
    void chgDisk(int index); // получаем индекс выбранного диска
    void goMainPath(); // Для UNIX-подобных ОС верхним уровнем является

    void finde_file();
    void print_anser(QString);
    void new_model();
private:
    QStandardItemModel *model;
    QString curretnPath;
    QStringList pathlist;
    Controller* controller;


public slots:
    void clicked(const QModelIndex& index);

};
#endif // FIRSTMYQTWIDGET_H
