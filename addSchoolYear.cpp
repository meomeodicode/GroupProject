#include "addSchoolYear.h"

void addSchoolYear (SchoolYear* &SchoolYearHead, string schoolYearName)
{
    SchoolYear* newSchoolYear = new SchoolYear;
    newSchoolYear->schoolYearName = schoolYearName;
    newSchoolYear->classHead = nullptr;
    newSchoolYear->pNext = nullptr;
    newSchoolYear->pPrev = nullptr;

    if (SchoolYearHead == nullptr) {
        SchoolYearHead = newSchoolYear;
    }
    else {
        newSchoolYear->pNext = SchoolYearHead;
        newSchoolYear->pPrev = nullptr;
        SchoolYearHead->pPrev = newSchoolYear;
        SchoolYearHead = newSchoolYear;
    }
}
