#ifndef VIEWSTUDENTCOURSE_H_INCLUDED
#define VIEWSTUDENTCOURSE_H_INCLUDED
#include "struct.h"

struct Date {
    int year;
    int month;
    int day;
};

// Course structure
struct Course {
    string id;
    string courseName;
    string teacherName;
    int credits;
    int maxStudents;
    string dayOfWeek;
    string session;
    double midtermMark;
    double finalMark;
    double totalMark;
    double otherMark;
    double courseGPA;
    struct Class* classHead;
    struct Student* studentHead;
    Course* pNext;
    Course* pPrev;
};
struct Student {
    string id;
    string firstName;
    string lastName;
    string gender;
    string className;
    Date dateOfBirth;
    string socialID;
    double overallGPA;
    Course* courseTotalHead;
    Course* courseEnrolHead;
    Student* pNext;
    Student* pPrev;
};
#endif