#include <iostream>
#include "viewScoreBoard.h"
using namespace std;

ViewStudentScoreboard(Student S)
{
    cout << S.id << endl;
    cout << S.firstName << endl;
    cout << S.lastName << endl;
    cout << S.gender << endl;
    cout << “Overall GPA : “ << S.overallGPA << endl;
    cout << cur->firstName << endl;
    Course* curcourse = S.courseTotalHead;
    while (curcourse)
    {
        coursenumber += 1;
        totalpoint += curcourse->courseGPA;
        cout << curcourse->courseName << “ “ << curcourse->credits << “ “ << curcourse->midtermMark << “ “ << curcourse->otherMark << “ “ << curcourse->finalMark << “ “ << curcourse->totalMark << “ “ << curcourse->courseGPA << endl;
        curcouse = curcourse->pNext;
    }
}