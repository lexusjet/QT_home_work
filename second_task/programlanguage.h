#ifndef PROGRAMLANGUAGE_H
#define PROGRAMLANGUAGE_H

#include "QtCore"

class ProgramLanguage
{
public:
    ProgramLanguage();
    ProgramLanguage(QString lname, QString icon_name):
        name(lname), icon(icon_name){};

    QString get_name() const {return name;} ;
    void set_name(QString a){name = a;};

    QString get_icon() const {return icon;} ;
    void set_icon(QString a){icon = a;};

protected:
    QString name;
    QString icon;
    int id;
};
Q_DECLARE_METATYPE(ProgramLanguage)

#endif // PROGRAMLANGUAGE_H
