#include <iostream>
#include "updateResult.h"
#include <fstream>
#include <string>
using namespace std;

void updateResult(Course* &head, int id, int studentID)
{
    Course* cur = head;
    double input;
    int count = 1;
     if (cur->id == id)
     {
            if (cur->students->id == studentID)
            {
                    while ((cin>>input)&&(count<=3))
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


