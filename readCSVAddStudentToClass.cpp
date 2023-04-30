#include "readCSVAddStudentToClass.h"
#include "addStudentToClass.h"

Student* bubbleSort(Student* head) {
    if (!head || !head->pNext) return head;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Student* prev = nullptr;
        Student* cur = head;

        while (cur && cur->pNext) {
            if (cur->id > cur->pNext->id) {
                Student* next = cur->pNext;
                cur->pNext = next->pNext;
                next->pPrev = cur->pPrev;

                if (cur->pPrev)
                {
                    cur->pPrev->pNext = next;
                }
                else
                {
                    head = next;
                }

                if (next->pNext)
                {
                    next->pNext->pPrev = cur;
                }
                next->pPrev = cur->pPrev;
                cur->pPrev = next;
                next->pNext = cur;

                prev = next;
                swapped = true;
            }
            else {
                prev = cur;
                cur = cur->pNext;
            }
        }
    }

    return head;
}

void readCSVAddStudentToClass (Class* &classHead, string &classInput)
{
    string searchClass = "Src/FileCSV/" + classInput + ".csv";
    ifstream fin (searchClass);

    if (fin.is_open ()) {
        string info, tmp;
        int cntLine = 0;

        while (getline (fin, info)) {
            if (cntLine % 3 == 0) {
                cntLine = 1;

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
                        ++cnt;
                    }
                    else if (cnt == 6) {
                        char dash;
                        stringstream cur (tmp);
                        cur >> dob.day >> dash >> dob.month >> dash >> dob.year;
                        ++cnt;
                    }
                    else if (cnt == 7) {
                        socialID = tmp;
                        addStudentToClass (classHead, id, firstName, lastName, gender, dob, socialID);
                    }
                }
            }
            else {
                ++cntLine;
            }
        }
    }

    classHead->studentHead = bubbleSort(classHead->studentHead);
}
