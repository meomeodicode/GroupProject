#include "MainScreen.h"
#include "StudentScreen.h"
#include "StaffScreen.h"

void MainScreen ()
{
    RenderWindow app (VideoMode (1920, 1080), "School System", Style::Default);

    // Font
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Image
    Texture SchoolMoodle;
    SchoolMoodle.loadFromFile("Src/Image/SchoolMoodle.png");
    Sprite Background(SchoolMoodle);
    Background.setPosition(0, 0);

    // Button Shape
    RectangleShape timeBox (Vector2f (220, 50));
    timeBox.setFillColor (Color::White);
    timeBox.setPosition (1500, 220);
    timeBox.setOutlineThickness (2);
    timeBox.setOutlineColor (Color (204, 204, 204));

    RectangleShape requireToEnter (Vector2f (600, 75));
    requireToEnter.setFillColor (Color::White);
    requireToEnter.setPosition (650, 300);
    requireToEnter.setOutlineThickness (2);
    requireToEnter.setOutlineColor (Color (204, 204, 204));

    RectangleShape requireToExit (Vector2f (600, 75));
    requireToExit.setFillColor (Color::White);
    requireToExit.setPosition (650, 800);
    requireToExit.setOutlineThickness (2);
    requireToExit.setOutlineColor (Color (204, 204, 204));

    RectangleShape buttonStudent (Vector2f (200, 50));
    buttonStudent.setFillColor (Color::White);
    buttonStudent.setPosition (840, 450);
    buttonStudent.setOutlineThickness(2);
    buttonStudent.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStaff (Vector2f (200, 50));
    buttonStaff.setFillColor (Color::White);
    buttonStaff.setPosition (840, 550);
    buttonStaff.setOutlineThickness(2);
    buttonStaff.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonExit (Vector2f (200, 50));
    buttonExit.setFillColor (Color::White);
    buttonExit.setPosition (840, 950);
    buttonExit.setOutlineThickness(2);
    buttonExit.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Select login option!", font, 50);
    requireToEnterText.setPosition (750, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text requireToExitText ("Exit program!", font, 50);
    requireToExitText.setPosition (820, 805);
    requireToExitText.setFillColor (Color (136, 136, 136));

    Text buttonTextStudent ("Student", font, 25);
    buttonTextStudent.setPosition (905, 455);
    buttonTextStudent.setFillColor (Color (52, 142, 254));

    Text buttonTextStaff ("Staff", font, 25);
    buttonTextStaff.setPosition (915, 555);
    buttonTextStaff.setFillColor (Color (52, 142, 254));

    Text buttonTextExit ("Exit", font, 25);
    buttonTextExit.setPosition (925, 955);
    buttonTextExit.setFillColor (Color (52, 142, 254));

    while (app.isOpen ()){
        Event e;

        chrono::system_clock::time_point now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        tm* localTime = localtime(&currentTime);
        stringstream tmpTimeString;
        tmpTimeString << put_time(localTime, "%d/%m/%Y %I:%M%p");
        string timeString = tmpTimeString.str();
        timeText.setString(timeString);

        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
            else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
            {
                app.close ();
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonStudent.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudent.setFillColor (Color (202, 216, 229));
                    StudentScreen (app);
                }
                else if (buttonStaff.getGlobalBounds ().contains (mousePos))
                {
                    buttonStaff.setFillColor (Color (202, 216, 229));
                    StaffScreen (app);
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

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (requireToExit);
        app.draw (requireToExitText);

        app.draw (buttonStudent);
        app.draw (buttonTextStudent);

        app.draw (buttonStaff);
        app.draw (buttonTextStaff);

        app.draw (buttonExit);
        app.draw (buttonTextExit);

        app.display ();
    }
}
