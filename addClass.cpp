#include "addClass.h"

void addClass (Class* &c, string name)
{
    Class* newClass = new Class;
    newClass->className = name;
    newClass->students = nullptr;
    newClass->pNext = nullptr;
    newClass->pPrev = nullptr;

    if (c == nullptr) {
        c = newClass;
    }
    else {
        newClass->pNext = c;
        c->pPrev = newClass;
        c = newClass;
    }
}
