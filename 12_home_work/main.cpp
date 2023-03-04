#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    qputenv("ANDROID_OPENSSL_SUFFIX", "<custom_suffix>");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
