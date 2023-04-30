#include "StaffScreen.h"
#include "CourseListScreen.h"
#include "ClassListScreen.h"
#include "StaffSearchClass.h"
#include "StaffSearchClassScore.h"
#include "StaffSearchCourse.h"
#include "StaffSearchCourseScore.h"
//#include "ClassScoreScreen.h"
#include "ChangeStaffPasswordScreen.h"
#include "StaffOperationScreen.h"


void StaffOperationScreen (RenderWindow &app, string idInput, string passwordInput)
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

    RectangleShape buttonClassList (Vector2f (200, 30));
    buttonClassList.setFillColor (Color::White);
    buttonClassList.setPosition (400, 450);
    buttonClassList.setOutlineThickness(2);
    buttonClassList.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseList (Vector2f (200, 30));
    buttonCourseList.setFillColor (Color::White);
    buttonCourseList.setPosition (900, 450);
    buttonCourseList.setOutlineThickness(2);
    buttonCourseList.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStudentinClass (Vector2f (200, 30));
    buttonStudentinClass.setFillColor (Color::White);
    buttonStudentinClass.setPosition (400, 550);
    buttonStudentinClass.setOutlineThickness(2);
    buttonStudentinClass.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonStudentListinCourse (Vector2f (200, 30));
    buttonStudentListinCourse.setFillColor (Color::White);
    buttonStudentListinCourse.setPosition (900, 550);
    buttonStudentListinCourse.setOutlineThickness(2);
    buttonStudentListinCourse.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonClassScore (Vector2f (200, 30));
    buttonClassScore.setFillColor (Color::White);
    buttonClassScore.setPosition (400, 650);
    buttonClassScore.setOutlineThickness(2);
    buttonClassScore.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonCourseScore (Vector2f (200, 30));
    buttonCourseScore.setFillColor (Color::White);
    buttonCourseScore.setPosition (900, 650);
    buttonCourseScore.setOutlineThickness(2);
    buttonCourseScore.setOutlineColor(Color (157, 209, 255));

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

    Text requireToEnterText ("Staff", font, 50);
    requireToEnterText.setPosition (410, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text buttonTextClassList ("List of Classes", font, 25);
    buttonTextClassList.setPosition (410, 450);
    buttonTextClassList.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseList ("List of Courses", font, 25);
    buttonTextCourseList.setPosition (910, 450);
    buttonTextCourseList.setFillColor (Color (52, 142, 254));

    Text buttonTextStudentinClass ("Student in Class", font, 25);
    buttonTextStudentinClass.setPosition (410, 550);
    buttonTextStudentinClass.setFillColor (Color (52, 142, 254));

    Text buttonTextStudentListinCourse ("Student in Course", font, 25);
    buttonTextStudentListinCourse.setPosition (910, 550);
    buttonTextStudentListinCourse.setFillColor (Color (52, 142, 254));

    Text buttonTextClassScore ("Class's scores", font, 25);
    buttonTextClassScore.setPosition (410, 650);
    buttonTextClassScore.setFillColor (Color (52, 142, 254));

    Text buttonTextCourseScore ("Course's scores", font, 25);
    buttonTextCourseScore.setPosition (910, 650);
    buttonTextCourseScore.setFillColor (Color (52, 142, 254));

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
                buttonBack.setFillColor (Color(202, 216, 229));
                StaffScreen (app);
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StaffScreen (app);
                }
                if (changePassword.getGlobalBounds ().contains (mousePos))
                {
                    changePassword.setFillColor (Color (202, 216, 229));
                    ChangeStaffPasswordScreen (app, idInput, passwordInput);
                }
                if (buttonClassList.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassList.setFillColor (Color (202, 216, 229));
                    ClassListScreen(app, idInput, passwordInput);
                }
                if (buttonCourseList.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseList.setFillColor (Color (202, 216, 229));
                    CourseListScreen(app, idInput, passwordInput);
                }
                if (buttonStudentinClass.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentinClass.setFillColor (Color (202, 216, 229));
                    StaffSearchClassScreen (app, idInput, passwordInput);
                }
                if (buttonStudentListinCourse.getGlobalBounds ().contains (mousePos))
                {
                    buttonStudentListinCourse.setFillColor (Color (202, 216, 229));
                    StaffSearchCourseScreen (app, idInput, passwordInput);
                }
                if (buttonClassScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonClassScore.setFillColor (Color (202, 216, 229));
                    StaffSearchClassScoreScreen (app, idInput, passwordInput);
                }
                if (buttonCourseScore.getGlobalBounds ().contains (mousePos))
                {
                    buttonCourseScore.setFillColor (Color (202, 216, 229));
                    StaffSearchCourseScoreScreen (app, idInput, passwordInput);
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

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (changePassword);
        app.draw (changePasswordText);

        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.draw (buttonClassList);
        app.draw (buttonTextClassList);

        app.draw (buttonStudentinClass);
        app.draw (buttonTextStudentinClass);

        app.draw (buttonStudentListinCourse);
        app.draw (buttonTextStudentListinCourse);

        app.draw (buttonCourseList);
        app.draw (buttonTextCourseList);

        app.draw (buttonCourseScore);
        app.draw (buttonTextCourseScore);

        app.draw (buttonClassScore);
        app.draw (buttonTextClassScore);

        app.display ();
    }
}

