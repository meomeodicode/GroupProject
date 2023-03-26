#include "addClassToSchoolYear.h"
void addClassToSchoolYear(SchoolYear* &s,Class* newclass)
{

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
