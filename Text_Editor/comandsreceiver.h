#ifndef COMANDSRECEIVER_H
#define COMANDSRECEIVER_H

#include <QObject>
#include "QPlainTextEdit"

class ComandsReceiver
{
public:
    ComandsReceiver(){};
    ComandsReceiver(QPlainTextEdit * ptr):plainEdit(ptr){};
    void set_editor(QPlainTextEdit* ptr){ plainEdit = ptr;};

    void save_file_as(QString & path);
    void open_file(QString& path);
    void create_new_file();
private:
    QPlainTextEdit * plainEdit;
};

#endif // COMANDSRECEIVER_H
