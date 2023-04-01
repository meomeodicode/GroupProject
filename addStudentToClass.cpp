#include "addStudentToClass.h"

void addStudentToClass (Class* &classHead, string id, string firstName, string lastName, string gender, Date dob, string socialID)
{
    // Create a new Student instance
    Student *newStudent = new Student;

    // Assign values to its properties
    newStudent->id = id;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->className = classHead->className;
    newStudent->gender = gender;
    newStudent->dateOfBirth = dob;
    newStudent->socialID = socialID;

    // Add the new student to the beginning of the students list
    if (classHead->studentHead == nullptr) {
        classHead->studentHead = newStudent;
        classHead->studentHead->pNext = nullptr;
        classHead->studentHead->pPrev = nullptr;
    }
    else {
        classHead->studentHead->pPrev = newStudent;
        newStudent->pNext = classHead->studentHead;
        newStudent->pPrev = nullptr;
        classHead->studentHead = newStudent;
    }
}
