#include "removeStudentfromCourse.h"

void removeStudentFromCourse (Course* &courseHead, string id)
{
    Student* cur = courseHead->studentHead;

    while(cur)
    {
        if (cur->id==id)
        {
            break;
        }
        cur=cur->pNext;
    }
    if (!cur) return;

    if (cur == courseHead->studentHead)
    {
        courseHead->studentHead = cur->pNext;
    }
    else
    {
        cur->pPrev->pNext = cur->pNext;

    }
    delete cur;
}
