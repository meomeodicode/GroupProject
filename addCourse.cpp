#include "addCourse.h"

void addCourse (Course* &courseHead, string id, string courseName, string teacherName, string dayOfWeek, string Session)
{
    Course* newCourse = new Course;
    newCourse->id = id;
    newCourse->courseName = courseName;
    newCourse->teacherName = teacherName;
    newCourse->dayOfWeek = dayOfWeek;
    newCourse->session = Session;
    newCourse->pNext=nullptr;
    newCourse->pPrev=nullptr;
    newCourse->classHead = nullptr;
    newCourse->studentHead = nullptr;

    if (courseHead == nullptr) {
        courseHead = newCourse;
    }
    else {
        newCourse->pNext = courseHead;
        newCourse->pPrev = nullptr;
        courseHead->pPrev = newCourse;
        courseHead = newCourse;
    }
}
