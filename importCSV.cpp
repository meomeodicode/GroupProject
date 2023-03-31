#include "struct.h"
#include "importCSV.h"
using namespace std;

void importData()
{
    ifstream in("scoreData.csv");
    string line;
    const int maxCol = 7;
    int row;
    cin >> row;
    string** studentData = new string*[row];
    for (int i = 0; i < row; i++) {
        studentData[i] = new string[maxCol];
    }
    if (in.is_open())
    {
        int temp_row = 0;
        while (getline(in, line) && (temp_row < row)) 
        {
            stringstream ss(line);
            string info;
            int column = 0;
            while (getline(ss, info, ',')) 
            {
                studentData[temp_row][column++] = info;
            }
            temp_row++;
        }
        in.close();
    }
    for (int i = 0; i < row; i++) {
        delete[] studentData[i];
    }
    delete[] studentData;
}
