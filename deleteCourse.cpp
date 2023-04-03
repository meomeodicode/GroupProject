#include <iostream>
#include "deleteCourse.h"

void deleteCourse(Course* &courseHead, string courseId)
{
    if (courseHead == nullptr)
        return;
    else
    {
        Course* cur = courseHead;
        while (cur)
        {
            if (cur->id == courseId)
            {
                if (cur == courseHead)
                {
                    courseHead = cur->pNext;
                }
                else
                {
                    cur->pPrev->pNext = cur->pNext;
                }
                if
                    (cur->pNext != nullptr)
                {
                    cur->pNext->pPrev = cur->pPrev;
                }
                delete cur;
            }
            cur = cur->pNext;
        }
    }
}
