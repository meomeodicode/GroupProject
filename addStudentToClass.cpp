#pragma once
#include "addStudentToClass.h"

void addStudentToClass(Class *c, int id, string firstName, string lastName, string gender, string dateOfBirth, int socialID)
{
    // Create a new Student instance
    Student *newStudent = new Student;

    // Assign values to its properties
    newStudent->id = id;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->gender = gender;
    newStudent->socialID = socialID;

    // Parse the dateOfBirth string to a Date instance and assign it to the newStudent's dateOfBirth property
    Date dob;
    istringstream iss(dateOfBirth);
    char dash;
    iss >> dob.year >> dash >> dob.month >> dash >> dob.day;
    newStudent->dateOfBirth = dob;

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
