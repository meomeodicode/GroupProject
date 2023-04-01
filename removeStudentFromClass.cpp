#include "removeStudentFromClass.h"

void removeStudentFromClass (Class* classHead, string idSearch)
{
    // Find the student in the students list
    Student* cur = classHead->studentHead;
    while (cur != nullptr) {
        if (cur->id != idSearch) {
            cur = cur->pNext;
        }
        else {
            break;
        }
    }

    // Student not found
    if (cur == nullptr) {
        return;
    }

    // Remove the student from the list
    if (cur == classHead->studentHead) {
        // The student is the first element in the list
        classHead->studentHead = cur->pNext;
    } else {
        cur->pPrev->pNext = cur->pNext;
    }

    // Free the memory allocated for the removed student
    delete cur;
}
