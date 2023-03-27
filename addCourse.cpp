#pragma once
#include "addCourse.h"

void addCourse(Course* &c, string id, string courseName, string teacherName, string dayOfWeek, string Session)
{
    Course* newCourse = new Course;
    newCourse->id = id;
    newCourse->courseName = courseName;
    newCourse->teacherName = teacherName;
    newCourse->dayOfWeek = dayOfWeek;
    newCourse->session = Session;
    newCourse->pNext=nullptr;
    newCourse->pPrev=nullptr;
    newCourse->c = nullptr;
    newCourse->students = nullptr;

    if (c == nullptr) {
        c = newCourse;
    }
    else {
        newCourse->pNext = c;
        newCourse->pPrev = nullptr;
        c->pPrev = newCourse;
        c = newCourse;
    }
}
