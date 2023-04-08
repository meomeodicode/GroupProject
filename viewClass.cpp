#include <iostream>
#include "viewClass.h"
using namespace std;

void viewClass(Class* classhead)
{
	Class* cur = classhead;
	if (cur)
	{
		while (cur->pNext)
		{
			cout << cur->className << endl;
			cur = cur->pNext;
		}
		cout << cur->className;
	}
	else
		cout << "Error!";
	delete cur;
}
