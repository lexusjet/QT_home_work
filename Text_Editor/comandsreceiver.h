#ifndef COMANDSRECEIVER_H
#define COMANDSRECEIVER_H

#include <QObject>
#include <QTextEdit>

class ComandsReceiver
{
public:
    ComandsReceiver(){};
    ComandsReceiver(QTextEdit * ptr):text_editor(ptr){};
    void set_editor(QTextEdit* ptr){ text_editor = ptr;};

    void save_file_as(QString & path);
    void open_file(QString& path);
    void create_new_file();
    void change_language(QString lang);
private:
    QTextEdit * text_editor;

};

#endif // COMANDSRECEIVER_H
