#include "removeStudentfromCourse.h"
void removeStudentFromCourse(Course* &course, int id)
{
    Student* cur=course->students;

    while(cur)
    {
        if (cur->id==id)
        {
            break;
        }
        cur=cur->pNext;

    }
    if (!cur) return;
    if (cur==course->students)
    {
        course->students=cur->pNext;
    }
    else
    {
        cur->pPrev->pNext=cur->pNext;

    }
    delete cur;

}
