#ifndef THREADFINDER_H
#define THREADFINDER_H

#include <QObject>
#include <QThread>

class ThreadFinder : public QThread
{
    Q_OBJECT
    public:
        explicit ThreadFinder(QString dir, QString File, QObject *parent = nullptr);
        void findStop() {toWork = false;} // Команда прекращения работы потока
    protected:
        void run();
    private:
        QString dir;
        QString file;
        bool toWork; // Завершение потока извне
    signals:
        void stopedThread(); // Сигнал завершения поиска
        void writeFoundPath(QString); // Вывод текущего каталога поиска
        void findFile(QString);
};

#endif // THREADFINDER_H
