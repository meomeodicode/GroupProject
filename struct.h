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

// Functions for linked list operations
void createSchoolYear ();
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
