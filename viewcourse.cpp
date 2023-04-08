#include "viewcourse.h"
void viewCourseList (Course *course)
{
    Course* cur = course;
    if (!course) cout<<"empty";
    else
    {
    while (cur)
    {
        cout<<cur->courseName<<endl;
        cur=cur->pNext;
    }
        cout << cur->courseName;
    }
    delte cur;
}
