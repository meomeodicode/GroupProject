#pragma once

// Date structure
struct Date {
    int year;
    int month;
    int day;
};

// School Year structure
struct SchoolYear {
    string schoolYear;
    Semester s1;
    Semester s2;
    Semester s3;
    SchoolYear* pNext;
    SchoolYear* pPrev;
    Class* c;
};

// Semester structure
struct Semester {
    string schoolYear;
    Date startDate;
    Date endDate;
    Course* courses;
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
    Class* c;
    Student* students;
    Course* pNext;
    Course* pPrev;
};

// Class structure
struct Class {
    string className;
    Student* students;
    Class* pNext;
    Class* pPrev;
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
    Course* courseTotal;
    Course* courseEnrol;
    Student* pNext;
    Student* pPrev;
};

// Function new
void createSchoolYear ();
void addClassToSchoolYear ();

// Functions for linked list operations
void addClass ();
void addStudentToClass ();
void removeStudentFromClass ();
void readCSVAddStudentToClass (); // read CSV then use addStudentToClass for each data
void addCourse ();
void deleteCourse();
void addStudentToCourse ();
void removeStudentFromCourse();
void readCSVAddStudentToCourse (); // read CSV then use addStudentToCourse for each data
void addCourseToSemester(Semester *semester, int id, string name, string className, string teacherName, int credits, int maxStudents, string dayOfWeek, string session);
void exportStudentsFromCourse(Course *course, string filename);
void importScoreboard(Course *course, string filename);
void updateStudentResult(Course *course, int studentID, float midtermMark, float finalMark, float otherMark);

// Function for representing
void viewClassList (Class *c); // 15
void viewStudentListInClass (Class *c); // 16
void viewCourseList (Course *course); // 9, 17
void viewStudentListInCourse (Course *course); // 18
void viewScoreboardInCourse (Course *course); // 21
void viewScoreboardInClass (Class *c) // 23
void viewStudentCourse (Student *student); // 14
void viewStudentScore (Student *student); // 24
