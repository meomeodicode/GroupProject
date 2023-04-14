#include "StudentCourseListScreen.h"
#include "StudentOperationScreen.h"

void StudentCourseListScreen(Student s)
{
    RenderWindow app (VideoMode (1920, 1080), "Student's courses", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Button Shape
    RectangleShape buttonBack (Vector2f (200, 50));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (850, 800);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text buttonTextBack ("Back", font, 25);
    buttonTextBack.setPosition (935, 805);
    buttonTextBack.setFillColor (Color (52, 142, 254));


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
                    StudentOperationScreen(s);
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
            }
        }

        app.clear (Color (96, 169, 255));
        app.draw (buttonBack);
        app.draw (buttonTextBack);
        app.display ();
    }
}
