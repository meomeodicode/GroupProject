#include "viewCourseScoreBoard.h"
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "struct.h"

using namespace std;
using namespace sf;

void displayCourseScoreboard(Course* courseHead, const string& courseId)
{
    // create the SFML window
    RenderWindow window(VideoMode(1920, 1080), "Course Scoreboard");
    // create the SFML font object
    Font font;
    font.loadFromFile("arial.ttf");

    // create the SFML text object for displaying the course ID
    Text courseIdText("Course ID: " + courseId, font, 24);
    courseIdText.setPosition(20, 20);

    if (courseHead == nullptr)
    {
        // create the SFML text object for displaying the error message
        Text errorText("No courses found!", font, 24);
        errorText.setPosition(20, 60);

        // draw the SFML text object on the window
        window.draw(errorText);
        window.display();
        return;
    }
    Course* curCourse = courseHead;
    bool found = false;
    while (curCourse != nullptr)
    {
        if (curCourse->id == courseId)
        {
            // set the found flag to true
            found = true;

            // create the SFML text object for displaying the "Displaying score" message
            Text displayText("Displaying scores", font, 24);
            displayText.setPosition(20, 60);

            // draw the SFML text object on the window
            window.draw(courseIdText);
            window.draw(displayText);

            Student* curStudent = curCourse->studentHead;
            int studentIndex = 0;
            while (curStudent != nullptr)
            {
                Course* tracking = curStudent->courseEnrolHead;
                while (tracking)
                {
                    if (tracking->id == courseId)
                    {
                        // create the SFML text object for displaying the student information and marks
                        Text studentText("", font, 16);
                        studentText.setPosition(20, 120 + (studentIndex * 120));

                        studentText.setString("Student ID: " + curStudent->id +
                            "\nName: " + curStudent->firstName + " " + curStudent->lastName +
                            "\nMidterm Mark: " + to_string(tracking->midtermMark) +
                            "\nFinal Mark: " + to_string(tracking->finalMark) +
                            "\nTotal Mark: " + to_string(tracking->totalMark));

                        // draw the SFML text object on the window
                        window.draw(studentText);

                        studentIndex++;
                    }
                    tracking = tracking->pNext;
                }
                curStudent = curStudent->pNext;
            }
            break;
        }
        curCourse = curCourse->pNext;
    }

    // check if the course is not found
    if (!found)
    {
        // create the SFML text object for displaying the error message
        Text errorText("Course " + courseId + " not found!", font, 24);
        errorText.setPosition(20, 60);

        // draw the SFML text object on the window
        window.draw(courseIdText);
        window.draw(errorText);
    }

    // display the SFML window
    window.display();
    // handle SFML events
    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }
}
