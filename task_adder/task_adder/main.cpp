#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "basereader.h"
#include "taskcontroler.h"
#include <QResource>

int main(int argc, char *argv[])
{
    BaseReader basereader;
    basereader.loadBase(":/base/task_base/tasks.txt");

    TaskControler taskcontroler;

    taskcontroler.setBase(&basereader);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
        QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;
    engine.rootContext()->setContextProperty("taskcontroler", &taskcontroler);

    engine.load(url);

    return app.exec();
}
