#include "addCourseToSemester.h"
#include "addCourse.h"
void addCourseToSemester(Semester *&Sem, Course *&cou,string id,string courseName,string teacherName,string dayOfWeek,string Session)
{
    addCourse(cou, id, courseName, teacherName, dayOfWeek, Session);
    if(Sem->courses==nullptr)
    {
        Sem->courses=new Course;
        Course* tmp=Sem->courses;
        tmp->pNext=nullptr;
        tmp->pPrev=nullptr;
        tmp=cou;
    }
    else
    {
        Course* tmp0=Sem->courses;
        while(tmp0->pNext!=nullptr) tmp0=tmp0->pNext;
        tmp0->pNext=new Course;
        Course* tmp=tmp0->pNext;
        tmp=cou;
        tmp->pNext=nullptr;
        tmp->pPrev=tmp0;
    }
}
