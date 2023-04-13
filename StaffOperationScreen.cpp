#include "StaffScreen.h"
#include "CourseListScreen.h"
#include "ClassListScreen.h"
#include "StudentListInClassScreen.h"
#include "StudentListInCourseScreen.h"
#include "CourseScoreScreen.h"
#include "ClassScoreScreen.h"
#include "StaffOperationScreen.h"


void StaffOperationScreen()
{
    RenderWindow app (VideoMode (1920, 1080), "Operations:", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    Course course;                                                                                     //can edit
    Class clasS;                                                                                       //can edit
    // Button Shape
    RectangleShape buttonBack (Vector2f (200, 50));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (850, 800);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonClassList (Vector2f (200, 50));
    buttonClassList.setFillColor (Color::White);
    buttonClassList.setPosition (850, 900);
    buttonClassList.setOutlineThickness(2);
    buttonClassList.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStudentinClass (Vector2f (200, 50));
    buttonStudentinClass.setFillColor (Color::White);
    buttonStudentinClass.setPosition (850, 1000);
    buttonStudentinClass.setOutlineThickness(2);
    buttonStudentinClass.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStudentListinCourse (Vector2f (200, 50));
    buttonStudentListinCourse.setFillColor (Color::White);
    buttonStudentListinCourse.setPosition (850, 1100);
    buttonStudentListinCourse.setOutlineThickness(2);
    buttonStudentListinCourse.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseList (Vector2f (200, 50));
    buttonCourseList.setFillColor (Color::White);
    buttonCourseList.setPosition (850, 1200);
    buttonCourseList.setOutlineThickness(2);
    buttonCourseList.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseScore (Vector2f (200, 50));
    buttonCourseScore.setFillColor (Color::White);
    buttonCourseScore.setPosition (850, 1300);
    buttonCourseScore.setOutlineThickness(2);
    buttonCourseScore.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonClassScore (Vector2f (200, 50));
    buttonClassScore.setFillColor (Color::White);
    buttonClassScore.setPosition (850, 1400);
    buttonClassScore.setOutlineThickness(2);
    buttonClassScore.setOutlineColor(Color (157, 209, 255));
    // Button Text
    Text buttonTextBack ("Back", font, 25);
    buttonTextBack.setPosition (935, 805);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    Text buttonTextClassList ("List of Classes", font, 25);
    buttonTextClassList.setPosition (935, 905);
    buttonTextClassList.setFillColor (Color (52, 142, 254));

    Text buttonTextStudentinClass ("Student in Class", font, 25);
    buttonTextStudentinClass.setPosition (935, 1005);
    buttonTextStudentinClass.setFillColor (Color (52, 142, 254));

    Text buttonTextStudentListinCourse ("Course's Students", font, 25);
    buttonTextStudentListinCourse.setPosition (935, 1105);
    buttonTextStudentListinCourse.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseList ("List of courses", font, 25);
    buttonTextCourseList.setPosition (935, 1205);
    buttonTextCourseList.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseScore ("Course's scores", font, 25);
    buttonTextCourseScore.setPosition (935, 1305);
    buttonTextCourseScore.setFillColor (Color (52, 142, 254));

    Text buttonTextClassScore ("Class's scores", font, 25);
    buttonTextClassScore.setPosition (935, 1405);
    buttonTextClassScore.setFillColor (Color (52, 142, 254));
    while (app.isOpen ()){
        Event e;
        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StaffScreen();
                }
                if (buttonClassList.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassList.setFillColor (Color (202, 216, 229));
                    ClassListScreen(clasS);                                                         //can edit
                }
                if (buttonClassScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassScore.setFillColor (Color (202, 216, 229));
                    ClassScoreScreen(clasS);                                                        //can edit
                }
                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (202, 216, 229));
                    CourseListScreen(course);                                                       //can edit
                }
                if (buttonCourseScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseScore.setFillColor (Color (202, 216, 229));
                    CourseScoreScreen(course);                                                      //can edit
                }
                if (buttonStudentinClass.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentinClass.setFillColor (Color (202, 216, 229));
                    StudentListInClassScreen("abcd");                                                 //can edit
                }
                if (buttonStudentListinCourse.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentListinCourse.setFillColor (Color (202, 216, 229));
                    StudentListinCourseScreen(course);                                              //can edit
                }
            }
            else if (e.type == Event::MouseMoved)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    buttonBack.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonBack.setFillColor (Color::White);
                }

                if (buttonClassList.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassList.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonClassList.setFillColor (Color::White);
                }

                if (buttonClassScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassScore.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonClassScore.setFillColor (Color::White);
                }

                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonCourseList.setFillColor (Color::White);
                }

                if (buttonCourseScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseScore.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonCourseScore.setFillColor (Color::White);
                }

                if (buttonStudentinClass.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentinClass.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonStudentinClass.setFillColor (Color::White);
                }

                if (buttonStudentListinCourse.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentListinCourse.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonStudentListinCourse.setFillColor (Color::White);
                }
            }
        }

        app.clear (Color (96, 169, 255));
        app.draw (buttonBack);
        app.draw (buttonTextBack);
        app.display ();
    }
}

