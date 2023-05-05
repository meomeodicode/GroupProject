#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "struct.h"

using namespace std;
using namespace sf;

void showClassScoreboard(Class* classHead, string semName, string className)
{
    RenderWindow& app;
    Font& font;
    int page = 1;
    if (classHead == nullptr)
    {
        Text noClassText("Empty!", font, 30);
        noClassText.setFillColor(Color::White);
        noClassText.setPosition(100, 200);
        app.draw(noClassText);
        return;
    }
    Class* cur = classHead;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                app.close();
            }
        }
    }
    while (cur != nullptr)
    {
        if (cur->className == className)
        {
            // Image
            Texture SchoolMoodle;
            SchoolMoodle.loadFromFile("Src/Image/SchoolMoodle.png");
            Sprite Background(SchoolMoodle);
            Background.setPosition(0, 0);

            // Text Shape
            RectangleShape timeBox(Vector2f(220, 50));
            timeBox.setFillColor(Color::White);
            timeBox.setPosition(1500, 220);
            timeBox.setOutlineThickness(2);
            timeBox.setOutlineColor(Color(204, 204, 204));

            Text timeText("", font, 20);
            timeText.setFillColor(Color::Black);
            timeText.setPosition(1520, 225);

            Text titleText("Class Scoreboard", font, 40);
            titleText.setFillColor(Color::White);
            titleText.setPosition(100, 100);

            app.draw(Background);
            app.draw(timeBox);
            app.draw(timeText);
            app.draw(titleText);

            Student* studentInfo = cur->studentHead;
            int count = 0; // student index
            while (studentInfo != nullptr)
            {
                Text studentID(to_string(studentInfo->id), font, 20);
                studentID.setPosition(100, 200 + 50 * count);
                app.draw(studentID);

                Text studentName(studentInfo->firstName + " " + studentInfo->lastName, font, 20);
                studentName.setPosition(250, 200 + 50 * count);
                app.draw(studentName);

                Text studentGender(studentInfo->gender, font, 20);
                studentGender.setPosition(600, 200 + 50 * count);
                app.draw(studentGender);

                Text studentDOB(to_string(studentInfo->dateOfBirth.day) + "/" + to_string(studentInfo->dateOfBirth.month) + "/" + to_string(studentInfo->dateOfBirth.year), font, 20);
                studentDOB.setPosition(700, 200 + 50 * count);
                app.draw(studentDOB);

                Text studentSocialID(studentInfo->socialID, font, 20);
                studentSocialID.setPosition(900, 200 + 50 * count);
                app.draw(studentSocialID);
                Course* course = studentInfo->courseEnrolHead;
                double overallGPA = 0;
                int courseCount = 0;
                while (course)
                {
                    string name = course->sem->name;
                    if (name == semName)
                    {
                        Text TotalMark(course->totalMark, font, 20);
                        TotalMark.setPosition(1100, 200 + 50 * count);
                        app.draw(TotalMark);
                        overallGPA += course->totalMark * 4;
                        courseCount++;
                    }
                    course = course->pNext;
                }
                overallGPA /= courseCount;
                Text OverallGPA(overallGPA, font, 20);
                OverallGPA.setposition(1300, 200 + 50 * count);
                app.draw(OverallGPA);
                count++;
                studentInfo = studentInfo->pNext;
            }
            break;
        }
        cur = cur->pNext;
    }
}
