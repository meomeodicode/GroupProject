#ifndef UPDATERESULT_H_INCLUDED
#define UPDATERESULT_H_INCLUDED
#include <iostream>
#include "struct.h"
using namespace std;

// Date structure
struct Date {
    int year;
    int month;
    int day;
};

// Course structure
struct Course {
    int id;
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
    struct Class* c = nullptr;
    struct Student* students = nullptr;
    Course* pNext;
    Course* pPrev;
};

// Student structure
struct Student {
    int id;
    string firstName;
    string lastName;
    string gender;
    double overallGPA;
    Date dateOfBirth;
    int socialID;
    Course* courseTotal = nullptr;
    Course* courseEnrol = nullptr;
    Student* pNext;
    Student* pPrev;
};

// Class structure
struct Class {
    string className;
    Student* students = nullptr;
    Class* pNext;
    Class* pPrev;
};

// Semester structure
struct Semester {
    string schoolYear;
    Date startDate;
    Date endDate;
    Course* courses = nullptr;
};

// School Year structure
struct SchoolYear {
    string schoolYear;
    Semester s1;
    Semester s2;
    Semester s3;
    SchoolYear* pNext;
    SchoolYear* pPrev;
    Class* c = nullptr;
}; 
#endif