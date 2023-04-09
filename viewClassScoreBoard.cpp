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
                Course* enrolled = studentInfo->courseEnrolHead;
                double semGPA = 0;
                while (enrolled)
                {
                    //studentInfo->courseEnrolHead->courseName
                    if (enrolled->courseName == tracking.courseHead->courseName)
                    {
                        semGPA += enrolled->finalMark;
                        cout << "Final Mark of" << enrolled->courseName << ":" << enrolled->finalMark << "\n";
                    }
                    enrolled = enrolled->pNext;
                }
                cout << "Semester GPA:" << semGPA * 4 << endl;
                studentInfo = studentInfo->pNext;
            }
            return;
        }
        cur = cur->pNext;
    }

    cout << "Class " << name << " not found!";
}
