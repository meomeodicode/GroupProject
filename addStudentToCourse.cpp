#include "addStudentToCourse.h"

void addStudentToCourse (Course* &course, string id, string firstName, string lastName, string gender, Date dob, string socialID)
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
    if (course->students == nullptr) {
        course->students = newStudent;
        course->students->pNext = nullptr;
        course->students->pPrev = nullptr;
    }
    else {
        course->students->pPrev = newStudent;
        newStudent->pNext = course->students;
        newStudent->pPrev = nullptr;
        course->students = newStudent;
    }
}
