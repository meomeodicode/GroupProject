#include "addCourseToSemester.h"
#include "addCourse.h"
void addCourseToSemester(Semester *&Sem, string id,string courseName,string teacherName,string dayOfWeek,string Session)
{
    addCourse(Sem->courses, id, courseName, teacherName, dayOfWeek, Session);
}
