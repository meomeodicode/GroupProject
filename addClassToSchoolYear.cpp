#include "addClassToSchoolYear.h"
void addClassToSchoolYear(SchoolYear* &s,string classname,Student* students)
{
    Class* newclass=new Class;
    newclass->className=classname;
    newclass->students=students;
    newclass->pNext=nullptr;
    newclass->pPrev=nullptr;
    if (!s->c)
    {
        s->c=newclass;


    }

    else
    {
        s->c->pPrev=newclass;
        s->c->pPrev->pNext=s->c;
        s->c=s->c->pPrev;
    }

}
