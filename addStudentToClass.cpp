#include "addStudentToClass.h"

void addStudentToClass(Class* &c, string id, string firstName, string lastName, string gender, Date dob, string socialID)
{
    // Create a new Student instance
    Student *newStudent = new Student;

    // Assign values to its properties
    newStudent->id = id;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->gender = gender;
    newStudent->dateOfBirth = dob;
    newStudent->socialID = socialID;

    // Add the new student to the beginning of the students list
    if (c->students == nullptr) {
        c->students = newStudent;
        c->students->pNext = nullptr;
        c->students->pPrev = nullptr;
    }
    else {
        c->students->pPrev = newStudent;
        newStudent->pNext = c->students;
        newStudent->pPrev = nullptr;
        c->students = newStudent;
    }
}
