#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/rus_language/QtLanguage_ru.qm");
    qApp->installTranslator(&translator);
//    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
