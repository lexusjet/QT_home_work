#include "invokerconad.h"

InvokerConad::InvokerConad(){}

void InvokerConad::set_comand(Comand *c)
{
    comand = c;
}

void InvokerConad::exec_comand()
{
    comand->execute();
}
