#pragma once
#include "addCourse.h"

void addCourse(Course* &c)
{
    c=new Course;
    c->pNext=nullptr;
    c->pPrev=nullptr;

}
