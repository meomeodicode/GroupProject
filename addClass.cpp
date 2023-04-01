#include "addClass.h"

void addClass (Class* &classHead, string className)
{
    Class* newClass = new Class;
    newClass->className = className;
    newClass->studentHead = nullptr;
    newClass->pNext = nullptr;
    newClass->pPrev = nullptr;

    if (classHead == nullptr) {
        classHead = newClass;
    }
    else {
        newClass->pNext = classHead;
        newClass->pPrev = nullptr;
        classHead->pPrev = newClass;
        classHead = newClass;
    }
}
