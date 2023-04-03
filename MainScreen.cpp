#include "MainScreen.h"
#include "StudentScreen.h"
#include "StaffScreen.h"

void MainScreen ()
{
    RenderWindow app (VideoMode (1920, 1080), "School System", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Button Shape
    RectangleShape buttonStudent (Vector2f (200, 50));
    buttonStudent.setFillColor (Color::White);
    buttonStudent.setPosition (850, 500);
    buttonStudent.setOutlineThickness(2);
    buttonStudent.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStaff (Vector2f (200, 50));
    buttonStaff.setFillColor (Color::White);
    buttonStaff.setPosition (850, 650);
    buttonStaff.setOutlineThickness(2);
    buttonStaff.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonExit (Vector2f (200, 50));
    buttonExit.setFillColor (Color::White);
    buttonExit.setPosition (850, 800);
    buttonExit.setOutlineThickness(2);
    buttonExit.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text buttonTextStudent ("Student", font, 25);
    buttonTextStudent.setPosition (915, 505);
    buttonTextStudent.setFillColor (Color (52, 142, 254));

    Text buttonTextStaff ("Staff", font, 25);
    buttonTextStaff.setPosition (925, 655);
    buttonTextStaff.setFillColor (Color (52, 142, 254));

    Text buttonTextExit ("Exit", font, 25);
    buttonTextExit.setPosition (935, 805);
    buttonTextExit.setFillColor (Color (52, 142, 254));

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
                if (buttonStudent.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudent.setFillColor (Color (202, 216, 229));
                    StudentScreen ();
                }
                else if (buttonStaff.getGlobalBounds ().contains (mousePos))
                {
                    buttonStaff.setFillColor (Color (202, 216, 229));
                    StaffScreen ();
                }
                else if (buttonExit.getGlobalBounds ().contains (mousePos))
                {
                    buttonExit.setFillColor (Color (202, 216, 229));
                    app.close ();
                }
            }
            else if (e.type == Event::MouseMoved)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonStudent.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonStudent.setFillColor (Color::White);
                }
                if (buttonStaff.getGlobalBounds ().contains (mousePos))
                {
                    buttonStaff.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonStaff.setFillColor (Color::White);
                }
                if (buttonExit.getGlobalBounds ().contains (mousePos))
                {
                    buttonExit.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonExit.setFillColor (Color::White);
                }
            }
        }

        app.clear (Color (96, 169, 255));
        app.draw (buttonStudent);
        app.draw (buttonTextStudent);
        app.draw (buttonStaff);
        app.draw (buttonTextStaff);
        app.draw (buttonExit);
        app.draw (buttonTextExit);
        app.display ();
    }
}
