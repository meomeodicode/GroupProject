#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct Student {
    int id;
    string firstName;
    string lastName;
    string gender;
    Date dateOfBirth;
    int socialID;
    Student* pNext;
};

struct Course {
    int id;
    string name;
    string className;
    string teacherName;
    int credits;
    int maxStudents;
    string dayOfWeek;
    string session;
    Student* students;
    Course* pNext;
};

struct Semester {
    int id;
    string schoolYear;
    Date startDate;
    Date endDate;
    Course* courses;
    Semester* pNext;
};

struct Class {
    string name;
    Student* students;
    Class* pNext;
};

void removeStudentFromCourse(Course* course, int id)
{
    Student* prev = nullptr;
    Student* cur = course->students;
    if (cur == nullptr)
        cout << "not enrrolled :<";
    else
    {
        if (cur)
        {
            while (cur->pNext)
            {
                if (cur->id == id)
                {
                    if (prev == nullptr)
                        course->students = cur->pNext;
                    else
                    {
                        prev->pNext = cur->pNext;
                        cur->pNext = nullptr;
                    }
                }
                prev = cur;
                cur = cur->pNext;
            }
        }
    }
}
void addClass(Class*& head, string name)
{
    Class* newClass = new Class;
    newClass->pNext = nullptr;
    newClass->name = name;
    if (head == nullptr)
        cout << "Added";
    else
    {
        Class* cur = head;
        while (cur->pNext)
            cur = cur -> pNext;
        cur->pNext = newClass;
    }

}