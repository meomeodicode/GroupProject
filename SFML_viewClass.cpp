#include <iostream>
#include <SFML/Graphics.hpp>
#include "struct.h"
using namespace std;
using namespace sf;

void viewClass(Class* classhead)
{
    // create the SFML window
    RenderWindow window(VideoMode(1920, 1080), "View Classes");
    // create the SFML font object
    Font font;
    font.loadFromFile("arial.ttf");

    // create the SFML text object for displaying the title
    Text titleText("Class List", font, 36);
    titleText.setPosition(500, 20);

    // create the SFML text object for displaying the class names and stats
    Text classText("", font, 24);
    classText.setPosition(300, 100);

    Class* cur = classhead;
    bool isEmpty = true;
    while (cur)
    {
        // set the class name to the text object
        classText.setString(classText.getString() + cur->className + "\n");

        // iterate over the semesters in the class and calculate the stats
        Semester* sem = cur->semesterHead;
        double totalGPA = 0;
        int studentCount = 0;
        while (sem)
        {
            Student* student = sem->studentHead;
            while (student)
            {
                totalGPA += student->overallGPA;
                studentCount++;
                student = student->pNext;
            }
            sem = sem->pNext;
        }

        // calculate the class GPA and add it to the text object
        double classGPA = totalGPA / studentCount;
        classText.setString(classText.getString() + "Class GPA: " + to_string(classGPA) + "\n");

        // move to the next class
        cur = cur->pNext;

        isEmpty = false;
    }

    // check if the linked list is empty
    if (isEmpty)
    {
        // set the error message to the text object
        classText.setString("Empty List!");
    }

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

        // draw the title and class names with stats on the SFML window
        window.draw(titleText);
        window.draw(classText);

        // display the SFML window
        window.display();
    }
}
