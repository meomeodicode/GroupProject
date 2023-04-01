#pragma once
#include <bits/stdc++.h>

using namespace std;

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
void viewClassList (Class *c); // 15
void viewStudentListInClass (Class *c); // 16
void viewCourseList (Course *course); // 9, 17
void viewStudentListInCourse (Course *course); // 18
void viewScoreboardInCourse (Course *course); // 21
void viewScoreboardInClass (Class *c); // 23
void viewStudentCourse (Student *student); // 14
void viewStudentScore (Student *student); // 24
