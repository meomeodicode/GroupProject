#include <iostream>
#include "updateResult.h"
#include <fstream>
#include <string>

using namespace std;

void updateResult(Course* &courseHead, string id, string studentID)
{
    Course* cur = courseHead;
    double input;
    int count = 1;
     if (cur->id == id)
     {
        if (cur->studentHead->id == studentID)
        {
            while ((cin >> input) && (count <= 3))
            {
                if (count == 1)
                {
                    cur->otherMark = input;
                    ++count;
                }
                else if (count == 2)
                {
                    cur->midtermMark = input;
                    ++count;
                }
                else if (count == 3)
                {
                    cur->finalMark = input;
                    ++count;
                }
            }
        }
    }
}
