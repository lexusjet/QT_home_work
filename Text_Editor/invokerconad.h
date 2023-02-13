#ifndef INVOKERCONAD_H
#define INVOKERCONAD_H
#include "comand.h"
#include <QtCore>

class InvokerConad
{
public:
    InvokerConad();
    void set_comand(Comand* c);
    void exec_comand();
protected:
    Comand* comand;
};

#endif // INVOKERCONAD_H
