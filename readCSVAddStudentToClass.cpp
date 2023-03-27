#include "readCSVAddStudentToClass.h"
#include "addStudentToClass.h"

void readCSVAddStudentToClass (Class* &c)
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
                    id = tmp;
                    ++cnt;
                }
                else if (cnt == 2) {
                    firstName = tmp;
                    ++cnt;
                }
                else if (cnt == 3) {
                    lastName = tmp;
                    ++cnt;
                }
                else if (cnt == 4) {
                    gender = tmp;
                    ++cnt;
                }
                else if (cnt == 5) {
                    char dash;
                    stringstream cur (tmp);
                    cur >> dob.year >> dash >> dob.month >> dash >> dob.day;
                    ++cnt;
                }
                else if (cnt == 6) {
                    socialID = tmp;
                    addStudentToClass (c, id, firstName, lastName, gender, dob, socialID);
                }
            }
        }
    }
}
