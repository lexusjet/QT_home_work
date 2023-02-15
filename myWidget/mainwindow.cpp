#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fmqw = new FirstMyQtWidget(this);
 //   connect(this, SIGNAL(QWidget::mouseDoubleClickEvent(QMouseEvent *event) ),fmqw, SLOT(clicked(QMouseEvent *event)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

