#include "viewClassScoreBoard.h"
#include <iostream>
#include <iomanip>
using namespace std;

void showClassScoreboard(Class* classHead, string name, Semester curr)
{
    if (classHead == nullptr) 
    {
        cout << "Empty!"<<endl;
        return;
    }
    Class* cur = classHead;
    while (cur != nullptr) {
        if (cur->className == name) 
        {
            Student* studentInfo = cur->studentHead;
            Semester tracking = curr ;
            while (studentInfo != nullptr) 
            {
                cout << "Student ID: " << studentInfo->id << "\n";
                cout << "Name: " << studentInfo->firstName << " " << studentInfo->lastName << "\n";
                cout << "Gender: " << studentInfo->gender << ", Class: " << studentInfo->className << "\n";
                cout << "Date of Birth: " << studentInfo->dateOfBirth.day << "/" << studentInfo->dateOfBirth.month << "/" << studentInfo->dateOfBirth.year << "\n";
                cout << "Social ID: " << studentInfo->socialID << "\n";
                cout << "Overall GPA: " << studentInfo->overallGPA << "\n";
                cout << "Semester GPA:" << studentInfo->semGPA << "\n";
                Course* enrolled = studentInfo->courseEnrolHead;
                while (enrolled)
                {
                    //studentInfo->courseEnrolHead->courseName
                    if (enrolled->courseName == tracking.courseHead->courseName)
                        cout << enrolled->finalMark << "\n";
                    enrolled = enrolled->pNext;

                }
                studentInfo = studentInfo->pNext;
            }
            return;
        }
        cur = cur->pNext;
    }

    cout << "Class " << name << " not found!";
}
