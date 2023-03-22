#pragma once
#include "struct.h"

void addStudentToClass(Class *c, int id, string firstName, string lastName, string gender, string dateOfBirth, string socialID)
{
    // Create a new Student instance
    Student *newStudent = new Student;

    // Assign values to its properties
    newStudent->id = id;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->gender = gender;

    // Parse the dateOfBirth string to a Date instance
    // and assign it to the newStudent's dateOfBirth property
    Date dob;
    sscanf(dateOfBirth.c_str(), "%d-%d-%d", &dob.year, &dob.month, &dob.day);
    newStudent->dateOfBirth = dob;

    newStudent->socialID = socialID;

    // Add the new student to the beginning of the students list
    newStudent->pNext = c->students;
    c->students = newStudent;
}

void removeStudentFromClass(Class *c, int id)
{
    // Find the student in the students list
    Student *prev = nullptr;
    Student *current = c->students;
    while (current != nullptr && current->id != id) {
        prev = current;
        current = current->pNext;
    }

    if (current == nullptr) {
        // Student not found
        return;
    }

    // Remove the student from the list
    if (prev == nullptr) {
        // The student is the first element in the list
        c->students = current->pNext;
    } else {
        prev->pNext = current->pNext;
    }

    // Free the memory allocated for the removed student
    delete current;
}
