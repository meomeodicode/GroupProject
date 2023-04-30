#include "StudentScreen.h"
#include "StudentOperationScreen.h"
#include "StudentScoreBoardScreen.h"
#include "StudentCourseListScreen.h"

void StudentOperationScreen (RenderWindow &app, string idInput, string passwordInput)
{
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
    requireToEnter.setPosition (400, 300);
    requireToEnter.setOutlineThickness (2);
    requireToEnter.setOutlineColor (Color (204, 204, 204));

    RectangleShape buttonScoreBoard (Vector2f (200, 30));
    buttonScoreBoard.setFillColor (Color::White);
    buttonScoreBoard.setPosition (400, 450);
    buttonScoreBoard.setOutlineThickness(2);
    buttonScoreBoard.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseList (Vector2f (200, 30));
    buttonCourseList.setFillColor (Color::White);
    buttonCourseList.setPosition (400, 550);
    buttonCourseList.setOutlineThickness(2);
    buttonCourseList.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonTotalCourseList (Vector2f (200, 30));
    buttonTotalCourseList.setFillColor (Color::White);
    buttonTotalCourseList.setPosition (400, 650);
    buttonTotalCourseList.setOutlineThickness(2);
    buttonTotalCourseList.setOutlineColor(Color (157, 209, 255));

    RectangleShape changePassword (Vector2f (200, 30));
    changePassword.setFillColor (Color::White);
    changePassword.setPosition (400, 900);
    changePassword.setOutlineThickness (2);
    changePassword.setOutlineColor (Color (157, 209, 255));

    RectangleShape buttonBack (Vector2f (200, 30));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (400, 1000);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Student", font, 50);
    requireToEnterText.setPosition (410, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text buttonTextScoreBoard ("Scores", font, 25);
    buttonTextScoreBoard.setPosition (410, 450);
    buttonTextScoreBoard.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseList ("Course Enrol", font, 25);
    buttonTextCourseList.setPosition (410, 550);
    buttonTextCourseList.setFillColor (Color (52, 142, 254));

    Text buttonTextTotalCourseList ("Course Total", font, 25);
    buttonTextTotalCourseList.setPosition (410, 650);
    buttonTextTotalCourseList.setFillColor (Color (52, 142, 254));

    Text changePasswordText ("Change password", font, 25);
    changePasswordText.setPosition (410, 900);
    changePasswordText.setFillColor (Color (52, 142, 254));

    Text buttonTextBack ("Logout", font, 25);
    buttonTextBack.setPosition (410, 1000);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    // Screen
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
                StudentScreen (app);
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StudentScreen (app);
                }
                if (changePassword.getGlobalBounds ().contains (mousePos))
                {
                    changePassword.setFillColor (Color (202, 216, 229));

                }
                if (buttonScoreBoard.getGlobalBounds ().contains (mousePos))
                {
                    buttonScoreBoard.setFillColor (Color (202, 216, 229));
                    StudentScoreBoardScreen (app, idInput, passwordInput);
                }
                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (202, 216, 229));
                    StudentCourseListScreen(app, idInput, passwordInput);
                }
                if (buttonTotalCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonTotalCourseList.setFillColor (Color (202, 216, 229));
                    //StudentTotalCourseListScreen(student);
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
                if (changePassword.getGlobalBounds ().contains (mousePos))
                {
                    changePassword.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    changePassword.setFillColor (Color::White);
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
                if (buttonTotalCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonTotalCourseList.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    buttonTotalCourseList.setFillColor (Color::White);
                }
            }
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (changePassword);
        app.draw (changePasswordText);

        app.draw (buttonScoreBoard);
        app.draw (buttonTextScoreBoard);

        app.draw (buttonCourseList);
        app.draw (buttonTextCourseList);

        app.draw (buttonTotalCourseList);
        app.draw (buttonTextTotalCourseList);

        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.display ();
    }
}
