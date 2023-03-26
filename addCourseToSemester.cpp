#include <bits/stdc++.h>
#include "struct.h"
void addCourseToSemester(Course *&cou, Semester *&Sem)
{
    if(Sem->courses==nullptr)
    {
        Course* d;
        Sem->courses=new Course;
        d=Sem->courses;
        d->c=cou->c;
        d->courseGPA=cou->courseGPA;
        d->courseName=cou->courseName;
        d->credits=cou->credits;
        d->dayOfWeek=cou->dayOfWeek;
        d->finalMark=cou->finalMark;
        d->id=cou->id;
        d->maxStudents=cou->maxStudents;
        d->otherMark=cou->otherMark;
        d->pNext=nullptr;
        d->pPrev=nullptr;
        d->session=cou->session;
        d->students=cou->students;
        d->teacherName=cou->teacherName;
        d->totalMark=cou->totalMark;
    }
    else
    {
        Course* tmp0=Sem->courses;
        while(tmp0->pNext!=nullptr) tmp0=tmp0->pNext;
        tmp0->pNext=new Course;
        Course* tmp=tmp0->pNext;
        tmp->pNext=nullptr;
        tmp->pPrev=tmp0;
        tmp->c=cou->c;
        tmp->courseGPA=cou->courseGPA;
        tmp->courseName=cou->courseName;
        tmp->credits=cou->credits;
        tmp->dayOfWeek=cou->dayOfWeek;
        tmp->finalMark=cou->finalMark;
        tmp->id=cou->id;
        tmp->maxStudents=cou->maxStudents;
        tmp->otherMark=cou->otherMark;
        tmp->session=cou->session;
        tmp->students=cou->students;
        tmp->teacherName=cou->teacherName;
        tmp->totalMark=cou->totalMark;
    }
}
