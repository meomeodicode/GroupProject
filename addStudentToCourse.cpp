#include "addStudentToCourse.h"

void addStudentToCourse (Course* &courseHead, Class* &classHead, string id, string firstName, string lastName, string className, string gender, Date dob, string socialID)
{
    // Create a new Student instance
    Student *newStudent = new Student;

    // Assign values to its properties
    newStudent->id = id;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->className = className;
    newStudent->gender = gender;
    newStudent->dateOfBirth = dob;
    newStudent->socialID = socialID;

    // Add the new student to the beginning of the students list
    if (courseHead->studentHead == nullptr) {
        courseHead->studentHead = newStudent;
        courseHead->studentHead->pNext = nullptr;
        courseHead->studentHead->pPrev = nullptr;
    }
    else {
        courseHead->studentHead->pPrev = newStudent;
        newStudent->pNext = courseHead->studentHead;
        newStudent->pPrev = nullptr;
        courseHead->studentHead = newStudent;
    }

    // Add the course to that student's Course List
    Class* curClass = classHead;
    while (curClass != nullptr) {
        if (curClass->className == newStudent->className) {
            break;
        }
        else {
            curClass = curClass->pNext;
        }
    }

    Student* curStudent = curClass->studentHead;
    while (curStudent != nullptr) {
        if (curStudent->id == newStudent->id) {
            break;
        }
        else {
            curStudent = curStudent->pNext;
        }
    }

    curStudent->courseEnrolHead = courseHead;
    curStudent->courseTotalHead = courseHead;
}
