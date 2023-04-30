#include <iostream>
#include <cstring>
using namespace std;

// Date structure
struct Date {
    int year;
    int month;
    int day;
};

// Student structure
struct Student {
    int id;
    string firstName;
    string lastName;
    string gender;
    Date dateOfBirth;
    int socialID;
    Student *pNext;
};

// Course structure
struct Course {
    int id;
    string name;
    string className;
    string teacherName;
    int credits;
    int maxStudents;
    string dayOfWeek;
    string session;
    Student *students;
    Course *pNext;
};

// Semester structure
struct Semester {
    int id;
    string schoolYear;
    Date startDate;
    Date endDate;
    Course *courses;
    Semester *pNext;
};

// Class structure
struct Class {
    string name;
    Student *students;
    Class *pNext;
};

// Functions for linked list operations
void addStudent(Student *&head);
void addCourse(Course *&head, int id, string name, string className, string teacherName, int credits, int maxStudents, string dayOfWeek, string session);
void inputdate(Date &a)
{
    cout<<"day: ";
    cin>>a.day;
    cout<<"month: ";
    cin>>a.month;
    cout<<"year: ";
    cin>>a.year;
}


void addStudent(Student *&head)
{
    Student* laststudent;
    Student* new_student;
    new_student=new Student;



    cout<<"enter the id of the student: ";
    cin>>new_student->id;

    cout<<"enter student's fistname: ";
    cin.get();
    getline(cin,new_student->firstName);

    cout<<"enter student's lastname: ";
    getline(cin,new_student->lastName);
    cout<<"gender (male or female): ";
    getline(cin,new_student->gender);
    cout<<"date of birth: "<<endl;
    inputdate(new_student->dateOfBirth);
    cout<<"social ID: ";
    cin>>new_student->socialID;
    new_student->pNext=nullptr;
    if(!head)
    {
        head=new Student;
        head=new_student;
        laststudent=head;
    }
    else
    {
        laststudent->pNext=new Student;
        laststudent=laststudent->pNext;
        laststudent=new_student;
    }


}
void addCourse(Course* head)
{
    Course *lastcourse;
    Course *new_course=new Course;
    cout<<"input course id: ";
    cin>>new_course->id;
    cout<<"input class name: ";
    cin.get();
    getline(cin,new_course->className);
    cout<<"input teacher name: ";
    cin.get();
    getline(cin,new_course->teacherName);
    cout<<"input credit: ";
    cin>>new_course->credits;
    cout<<"input max student: ";
    cin>>new_course->maxStudents;
    cout<<"input the day of the week: ";
    cin.get();
    getline(cin,new_course->dayOfWeek);
    cout<<"input session: ";
    cin.get();
    getline(cin,new_course->session);
    new_course->pNext=nullptr;



     if(!head)
    {
        head=new Course;
        head=new_course;
        lastcourse=head;
    }
    else
    {
        lastcourse->pNext=new Course;
        lastcourse=lastcourse->pNext;
        lastcourse=new_course;
    }

}
int main()
{
    /*Student* head=nullptr;
    addStudent(head);*/

    Course* course=nullptr;
    addCourse(course);
    return 0;
}
