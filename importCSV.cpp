#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "struct.h"
using namespace std;

void importData()
{
    ifstream in("scoreData.csv");
    string line;
    const int maxCol = 7;
    const int maxRow = 200;
    string studentData[200][7];
    if (in.is_open())
    {
    int row = 0;
    while (getline(in, line) && (row <= maxRow)) 
    {
        stringstream ss(line);
        string info;
        int temp = 0;
        while (getline(ss, info, ',')) 
        {
            studentData[row][temp++] = info ;
        }
        row++;
    }
    in.close();
}