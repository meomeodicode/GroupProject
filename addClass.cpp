#include "addClass.h"

void addClass (Class* &c)
{
    c = new Class;
    c->pNext = nullptr;
    c->pPrev = nullptr;
}
