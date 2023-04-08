#include "importCSV.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void importData()
{
    ifstream in("scoreData.csv");
    string line;
    const int maxCol = 7;
    int row;
    cout << "Enter the number of rows to read from the CSV file: ";
    cin >> row;
    //Tao mang 2 chieu de luu thông tin = pointer to pointer
    string** studentData = new string * [row];
    for (int i = 0; i < row; i++)
    {
        //moi pointer to row se tao mot pointer to column  
        studentData[i] = new string[maxCol];
    }
    if (in.is_open())
    {
        int temp_row = 0;
        while (getline(in, line) && (temp_row < row))
        {
            stringstream ss(line);
            string info;
            int temp = 0;
            while (getline(ss, info, ','))
            {
                studentData[temp_row][temp++] = info;
            }
            temp_row++;
        }
        in.close();
    }
    for (int i = 0; i < row; i++)
    {
        delete[] studentData[i];
    }
    delete[] studentData;
}
