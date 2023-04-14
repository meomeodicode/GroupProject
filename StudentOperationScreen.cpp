#include "StudentOperationScreen.h"
#include "StudentScoreBoardScreen.h"
#include "StudentCourseListScreen.h"
void StudentListinCourseScreen(Course c)
{
    Student student;

    RenderWindow app (VideoMode (1920, 1080), "Course's Students", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Button Shape
    RectangleShape buttonBack (Vector2f (200, 50));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (850, 800);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonScoreBoard (Vector2f (200, 50));
    buttonScoreBoard.setFillColor (Color::White);
    buttonScoreBoard.setPosition (850, 900);
    buttonScoreBoard.setOutlineThickness(2);
    buttonScoreBoard.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseList (Vector2f (200, 50));
    buttonCourseList.setFillColor (Color::White);
    buttonCourseList.setPosition (850, 1000);
    buttonCourseList.setOutlineThickness(2);
    buttonCourseList.setOutlineColor(Color (157, 209, 255));
    // Button Text
    Text buttonTextBack ("Back", font, 25);
    buttonTextBack.setPosition (935, 805);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    Text buttonTextScoreBoard ("Scores", font, 25);
    buttonTextScoreBoard.setPosition (935, 905);
    buttonTextScoreBoard.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseList ("Scores", font, 25);
    buttonTextCourseList.setPosition (935, 1005);
    buttonTextCourseList.setFillColor (Color (52, 142, 254));
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
                    StudentOperationScreen(student);
                }
                if (buttonScoreBoard.getGlobalBounds ().contains (mousePos))
                {
                    buttonScoreBoard.setFillColor (Color (202, 216, 229));
                    StudentScoreBoardScreen("student", "s");
                }
                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (202, 216, 229));
                    StudentCourseListScreen(student);
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

                if (buttonScoreBoard.getGlobalBounds ().contains (mousePos))
                {
                    buttonScoreBoard.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonScoreBoard.setFillColor (Color::White);
                }

                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonCourseList.setFillColor (Color::White);
                }
            }
        }

        app.clear (Color (96, 169, 255));
        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.draw (buttonScoreBoard);
        app.draw (buttonTextScoreBoard);

        app.draw (buttonCourseList);
        app.draw (buttonTextCourseList);
        app.display ();
    }
}
