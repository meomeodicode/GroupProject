#include <iostream>
#include "deleteCourse.h"

using namespace std;

void deleteCourse(Course* &head, string courseId)
{
    if (head == nullptr)
        return;
    else
    {
        Course* cur = head;
        while (cur)
        {
            if (cur->id == courseId)
            {
                if (cur == head)
                {
                    head = cur->pNext;
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
