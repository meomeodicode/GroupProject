#include "viewCourseScoreBoard.h"
#include <iostream>
#include <iomanip>
using namespace std;

void displayCourseScoreboard(Course* courseHead, const string& courseId) 
{
    if (courseHead == nullptr) {
        cout << "No courses found!" << endl;
        return;
    }
    Course* curCourse = courseHead;
    while (curCourse != nullptr) {
        if (curCourse->id == courseId) 
        {
            cout << "Displaying score" << endl;
            Student* curStudent = curCourse->studentHead;
            while (curStudent != nullptr) 
            {
                Course* tracking = curStudent->courseEnrolHead;
                while (tracking)
                {
                    if (tracking->id == courseId)
                    {
                        cout << "Student ID: " << curStudent->id << endl;
                        cout << "Name: " << curStudent->firstName << " " << curStudent->lastName << endl;
                        cout << "Midterm Mark: " << tracking->midtermMark << endl;
                        cout << "Final Mark: " << tracking->finalMark << endl;
                        cout << "Total Mark: " << tracking->totalMark << endl;
                        cout << "-----------------------------------" << endl;
                    }
                    tracking = tracking->pNext;
                }
                curStudent = curStudent->pNext;
            }
            return;
            break;
        }
        curCourse = curCourse->pNext;
    }

    cout << "Course " << courseId << " not found!";
}

