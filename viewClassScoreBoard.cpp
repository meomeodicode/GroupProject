#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <string>
#include "struct.h"
using namespace sf;
using namespace std;

void showClassScoreboard(Class* classHead, string name, Semester* curr)
{
    // create the SFML window
    RenderWindow window(VideoMode(1920, 1080), "Class Scoreboard");
    // create the SFML font object
    Font font;
    font.loadFromFile("arial.ttf");

    // create the SFML text object for displaying the class name
    Text classNameText("Class: " + name, font, 24);
    classNameText.setPosition(20, 20);

    while (window.isOpen())
    {
        // handle SFML events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // clear the SFML window
        window.clear(Color::White);

        // draw the class name text
        window.draw(classNameText);

        // iterate over the students in the class and display their information
        Class* cur = classHead;
        int studentIndex = 0;
        while (cur != nullptr)
        {
            if (cur->className == name)
            {
                Student* studentInfo = cur->studentHead;
                Semester* tracking = curr;
                while (studentInfo != nullptr)
                {
                    // create the SFML text object for displaying the student information
                    Text studentText("", font, 16);
                    studentText.setPosition(20, 60 + (studentIndex * 120));

                    // set the student information text
                    studentText.setString("Student ID: " + studentInfo->id +
                        "\nName: " + studentInfo->firstName + " " + studentInfo->lastName +
                        "\nGender: " + studentInfo->gender + ", Class: " + studentInfo->className +
                        "\nDate of Birth: " + to_string(studentInfo->dateOfBirth.day) + "/" + to_string(studentInfo->dateOfBirth.month) + "/" + to_string(studentInfo->dateOfBirth.year) +
                        "\nSocial ID: " + studentInfo->socialID +
                        "\nOverall GPA: " + to_string(studentInfo->overallGPA));

                    // iterate over the courses enrolled by the student and display their final marks
                    Course* enrolled = studentInfo->courseEnrolHead;
                    double semGPA = 0;
                    int courseCount = 0;
                    while (enrolled)
                    {
                        if (enrolled->courseName == (*tracking).courseHead->courseName)
                        {
                            semGPA += enrolled->finalMark;
                            courseCount++;

                            // add the course information to the student information text
                            studentText.setString(studentText.getString() + "\nFinal Mark of " + enrolled->courseName + ": " + to_string(enrolled->finalMark));
                        }
                        enrolled = enrolled->pNext;
                    }

                    // add the semester GPA to the student information text
                    if (courseCount > 0)
                    {
                        semGPA = semGPA / courseCount * 4;
                    }
                    studentText.setString(studentText.getString() + "\nSemester GPA: " + to_string(semGPA));
                    window.draw(studentText);
                    studentInfo = studentInfo->pNext;
                    studentIndex++;
                }
                break;
            }
            cur = cur->pNext;
        }

        // display the SFML window
        window.display();
    }
}




/*#include "viewClassScoreBoard.h"
#include <iostream>
#include <iomanip>
using namespace std;

void showClassScoreboard(Class* classHead, string name, Semester curr)
{
    if (classHead == nullptr) 
    {
        cout << "Empty!"<<endl;
        return;
    }
    Class* cur = classHead;
    while (cur != nullptr) {
        if (cur->className == name) 
        {
            Student* studentInfo = cur->studentHead;
            Semester tracking = curr ;
            while (studentInfo != nullptr) 
            {
                cout << "Student ID: " << studentInfo->id << "\n";
                cout << "Name: " << studentInfo->firstName << " " << studentInfo->lastName << "\n";
                cout << "Gender: " << studentInfo->gender << ", Class: " << studentInfo->className << "\n";
                cout << "Date of Birth: " << studentInfo->dateOfBirth.day << "/" << studentInfo->dateOfBirth.month << "/" << studentInfo->dateOfBirth.year << "\n";
                cout << "Social ID: " << studentInfo->socialID << "\n";
                cout << "Overall GPA: " << studentInfo->overallGPA << "\n";
                Course* enrolled = studentInfo->courseEnrolHead;
                double semGPA = 0;
                while (enrolled)
                {
                    //studentInfo->courseEnrolHead->courseName
                    if (enrolled->courseName == tracking.courseHead->courseName)
                    {
                        semGPA += enrolled->finalMark;
                        cout << "Final Mark of" << enrolled->courseName << ":" << enrolled->finalMark << "\n";
                    }
                    enrolled = enrolled->pNext;
                }
                cout << "Semester GPA:" << semGPA * 4 << endl;
                studentInfo = studentInfo->pNext;
            }
            return;
        }
        cur = cur->pNext;
    }

    cout << "Class " << name << " not found!";
}*/
