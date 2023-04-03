#include "readCSVAddStudentToClass.h"
#include "addStudentToClass.h"

void readCSVAddStudentToClass (Class* &classHead)
{
    ifstream fin ("studentInClass.txt");

    if (fin.is_open ()) {
        string info, tmp;
        while (getline (fin, info)) {
            // Modify data in CSV file
            string id;
            string firstName;
            string lastName;
            string gender;
            Date dob;
            string socialID;

            // Read data from CSV file
            stringstream ss (info);
            int cnt = 1;
            while (getline (ss, tmp, ',')) {
                if (cnt == 1) {
                    if (tmp != classHead->className) {
                        break;
                    }
                    else {
                        ++cnt;
                    }
                }
                else if (cnt == 2) {
                    id = tmp;
                    ++cnt;
                }
                else if (cnt == 3) {
                    firstName = tmp;
                    ++cnt;
                }
                else if (cnt == 4) {
                    lastName = tmp;
                    ++cnt;
                }
                else if (cnt == 5) {
                    gender = tmp;
                    ++cnt;
                }
                else if (cnt == 6) {
                    char dash;
                    stringstream cur (tmp);
                    cur >> dob.year >> dash >> dob.month >> dash >> dob.day;
                    ++cnt;
                }
                else if (cnt == 7) {
                    socialID = tmp;
                    addStudentToClass (classHead, id, firstName, lastName, gender, dob, socialID);
                }
            }
        }
    }
}
