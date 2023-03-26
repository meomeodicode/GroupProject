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
    int row;
    cin >> row;
    string* studentData = new string[maxCol * row];
    if (in.is_open())
    {
    int temp_row = 0;
    while (getline(in, line) && (temp_row <= row)) 
    {
        stringstream ss(line);
        string info;
        int temp = 0;
        while (getline(ss, info, ',')) 
        {
            studentData[temp_row][temp++] = info ;
        }
        temp_row++;
    }
    for (int i = 0; i < row; i++) {
        delete[] studentData[i];
    delete[] studentData;
    in.close();
}
