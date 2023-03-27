#pragma once
#include "removeStudentFromClass.h"

void removeStudentFromClass (Class* c, string idSearch)
{
    // Find the student in the students list
    Student* cur = c->students;
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
    if (cur == c->students) {
        // The student is the first element in the list
        c->students = cur->pNext;
    } else {
        cur->pPrev->pNext = cur->pNext;
    }

    // Free the memory allocated for the removed student
    delete cur;
}
