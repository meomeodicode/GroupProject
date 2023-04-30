#include "viewcourse.h"
void viewCourseList (Course *course)
{
    Course* cur=course;
    if (!course) cout<<"empty";
    while (cur)
    {
        cout<<cur->courseName<<endl;
        cur=cur->pNext;
    }
}
