#include "viewStudentCourse.h"
#include <iostream>
using namespace std;

void viewStudentCourse(Student person)
{
	Course* head = person.courseEnrolHead;
	Course* cur = head;
	if (!cur)
		cout << "Error!";
	else
	{
		while (cur->pNext)
		{
			cout << cur->courseName;
			cur = cur->pNext;
		}
		cout << cur->courseName;
	}
}