#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <chrono>

using namespace std;
using namespace sf;

// Date structure
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
    string midtermMark;
    string finalMark;
    string totalMark;
    string otherMark;
    string courseGPA;
    struct Class* classHead;
    struct Student* studentHead;
    Course* pNext;
    Course* pPrev;
};

// Student structure
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

// Class structure
struct Class {
    string className;
    Student* studentHead;
    Class* pNext;
    Class* pPrev;
};

// Semester structure
struct Semester {
    string schoolYearName;
    Date startDate;
    Date endDate;
    Course* courseHead;
};

// School Year structure
struct SchoolYear {
    string schoolYearName;
    Semester s1;
    Semester s2;
    Semester s3;
    SchoolYear* pNext;
    SchoolYear* pPrev;
    Class* classHead;
};

// Functions for linked list operations
void addSchoolYear ();
void addClassToSchoolYear ();
void addClass ();
void addStudentToClass ();
void removeStudentFromClass ();
void readCSVAddStudentToClass (); // read CSV then use addStudentToClass for each data
void addCourse ();
void deleteCourse();
void addStudentToCourse ();
void removeStudentFromCourse();
void readCSVAddStudentToCourse (); // read CSV then use addStudentToCourse for each data
void addCourseToSemester ();
void exportStudentsFromCourse ();
void importScoreboard ();
void updateStudentResult ();

// Function for representing
void viewClassList (Class *c); // 15 x
void viewStudentListInClass (Class *c); // 16 x
void viewCourseList (Course *course); // 9, 17 x
void viewStudentListInCourse (Course *course); // 18 x
void viewScoreboardInCourse (Course *course); // 21
void viewScoreboardInClass (Class *c); // 23 x
void viewStudentCourse (Student *student); // 14 x
void viewStudentScore (Student *student); // 24 x
