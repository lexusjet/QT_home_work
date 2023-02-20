#include "comandsreceiver.h"
#include <QFileDialog>
#include <QTextStream>

void ComandsReceiver::save_file_as(QString & path)
{
    QString path_to_save = QFileDialog::getSaveFileName(text_editor,  "", path, "Text(*.txt);");
    if(path_to_save.size() == 0) return ;
    QFile text_file(path_to_save);
    if(text_file.open(QIODevice::WriteOnly)){
        QTextStream stream(&text_file);
        stream<< text_editor->toPlainText();
    }
    text_file.close();
}

void ComandsReceiver::open_file(QString &path)
{
    QString path_to = QFileDialog::getOpenFileName(text_editor, "Пример фильтра", path, "Text(*.txt);");
    if(path_to.size() == 0) return;
    QFile text_file(path_to);
    if(!text_file.open(QIODevice::ReadOnly)) return;

    QTextStream stream(&text_file);
    QString text = stream.read(text_file.size());
    text_editor->setPlainText(text);

    path = path_to;
    text_file.close();
}

void ComandsReceiver::create_new_file()
{
    text_editor->setPlainText("");
}

