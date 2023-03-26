#include "addStudentToCourse.h"
void addStudentToCourse(Student*& s, Course*& c)
{
    if(c->students==nullptr)
    {
        Student* t;
        c->students=new Student;
        t=c->students;
        t->courseEnrol=s->courseEnrol;
        t->courseTotal=s->courseTotal;
        t->dateOfBirth=s->dateOfBirth;
        t->firstName=s->firstName;
        t->gender=s->gender;
        t->id=s->id;
        t->lastName=s->lastName;
        t->overallGPA=s->overallGPA;
        t->pNext=nullptr;
        t->pPrev=nullptr;
    }
    else
    {
        Student* tmp0=c->students;
        while(tmp0->pNext!=nullptr)
        {
            tmp0=tmp0->pNext;
        }

        tmp0->pNext=new Student;
        Student* tmp=tmp0->pNext;
        tmp->pNext=nullptr;
        tmp->pPrev=tmp0;
        tmp->courseEnrol=s->courseEnrol;
        tmp->courseTotal=s->courseTotal;
        tmp->dateOfBirth=s->dateOfBirth;
        tmp->firstName=s->firstName;
        tmp->gender=s->gender;
        tmp->id=s->id;
        tmp->lastName=s->lastName;
        tmp->overallGPA=s->overallGPA;
    }
}
