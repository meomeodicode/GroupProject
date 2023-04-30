#include "StaffSearchCourseScore.h"
#include "CourseScoreScreen.h"
#include "StaffOperationScreen.h"

void StaffSearchCourseScoreScreen (RenderWindow &app, string idInput, string passwordInput)
{
    string inputTmp;
    int check = 0;

    // Font
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Image
    Texture SchoolMoodle;
    SchoolMoodle.loadFromFile("Src/Image/SchoolMoodle.png");
    Sprite Background(SchoolMoodle);
    Background.setPosition(0, 0);

    // Text Shape
    RectangleShape timeBox (Vector2f (220, 50));
    timeBox.setFillColor (Color::White);
    timeBox.setPosition (1500, 220);
    timeBox.setOutlineThickness (2);
    timeBox.setOutlineColor (Color (204, 204, 204));

    RectangleShape requireToEnter (Vector2f (600, 50));
    requireToEnter.setFillColor (Color::White);
    requireToEnter.setPosition (400, 300);
    requireToEnter.setOutlineThickness (2);
    requireToEnter.setOutlineColor (Color (204, 204, 204));

    RectangleShape inputBoxCourse (Vector2f (500, 30));
    inputBoxCourse.setFillColor (Color::White);
    inputBoxCourse.setPosition (400, 600);
    inputBoxCourse.setOutlineThickness (2);
    inputBoxCourse.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitViewCourse (Vector2f (200, 30));
    submitViewCourse.setFillColor (Color::White);
    submitViewCourse.setPosition (400, 700);
    submitViewCourse.setOutlineThickness (2);
    submitViewCourse.setOutlineColor (Color (157, 209, 255));

    RectangleShape exitStaffScreen (Vector2f (200, 30));
    exitStaffScreen.setFillColor (Color::White);
    exitStaffScreen.setPosition (400, 800);
    exitStaffScreen.setOutlineThickness (2);
    exitStaffScreen.setOutlineColor (Color (157, 209, 255));

    // Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Please enter your information!", font, 25);
    requireToEnterText.setPosition (410, 310);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text inputTextCourse ("Please enter your course", font, 25);
    inputTextCourse.setPosition (410, 600);
    inputTextCourse.setFillColor (Color (52, 142, 254));

    Text submitViewCourseText ("Submit!", font, 25);
    submitViewCourseText.setPosition (410, 700);
    submitViewCourseText.setFillColor (Color (52, 142, 254));

    Text exitStaffScreenText ("Exit!", font, 25);
    exitStaffScreenText.setPosition (410, 800);
    exitStaffScreenText.setFillColor (Color (52, 142, 254));

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
                check = 0;
                exitStaffScreen.setFillColor (Color(202, 216, 229));
                StaffOperationScreen (app, idInput, passwordInput);
            }
            else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter)
            {
                submitViewCourse.setFillColor (Color(202, 216, 229));
                check = 0;
                if (inputTextCourse.getString() != "Please enter your course") {
                    CourseScoreScreen (app, inputTextCourse.getString(), idInput, passwordInput);
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxCourse.getGlobalBounds().contains (mousePos) && check != 1)
                {
                    inputBoxCourse.setFillColor (Color (202, 216, 229));
                    check = 1;
                    inputTmp = "";
                }
                else if (submitViewCourse.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    submitViewCourse.setFillColor (Color(202, 216, 229));
                    if (inputTextCourse.getString() != "Please enter your class") {
                        CourseScoreScreen (app, inputTextCourse.getString(), idInput, passwordInput);
                    }
                }
                else if (exitStaffScreen.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    exitStaffScreen.setFillColor (Color(202, 216, 229));
                    StaffOperationScreen (app, idInput, passwordInput);
                }
                else
                {
                    check = 0;
                    inputTmp = "";
                }
            }
            else if (e.type == Event::MouseMoved)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxCourse.getGlobalBounds().contains(mousePos))
                {
                    inputBoxCourse.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxCourse.setFillColor (Color::White);
                }
                if (submitViewCourse.getGlobalBounds().contains(mousePos))
                {
                    submitViewCourse.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    submitViewCourse.setFillColor (Color::White);
                }
                if (exitStaffScreen.getGlobalBounds().contains(mousePos))
                {
                    exitStaffScreen.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    exitStaffScreen.setFillColor (Color::White);
                }
            }
            else if (e.type == Event::TextEntered && check == 1)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    inputTextCourse.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextCourse.getString().isEmpty()) {
                    inputTmp.pop_back ();
                    inputTextCourse.setString (inputTmp);
                }
            }
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (inputBoxCourse);
        app.draw (inputTextCourse);

        app.draw (submitViewCourse);
        app.draw (submitViewCourseText);

        app.draw (exitStaffScreen);
        app.draw (exitStaffScreenText);

        app.display ();
    }
}
