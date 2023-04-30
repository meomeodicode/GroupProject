#include "StaffSearchClass.h"
#include "StudentListInClassScreen.h"
#include "StaffOperationScreen.h"

bool checkValidClass (string className)
{
    string searchClass = "Src/FileCSV/" + className + ".csv";
    ifstream fin (searchClass);

    if (fin.is_open()) {
        return true;
    }
    return false;
}

void StaffSearchClassScreen (RenderWindow &app, string idInput, string passwordInput)
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

    RectangleShape inputBoxClass (Vector2f (500, 30));
    inputBoxClass.setFillColor (Color::White);
    inputBoxClass.setPosition (400, 600);
    inputBoxClass.setOutlineThickness (2);
    inputBoxClass.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitViewClass (Vector2f (200, 30));
    submitViewClass.setFillColor (Color::White);
    submitViewClass.setPosition (400, 700);
    submitViewClass.setOutlineThickness (2);
    submitViewClass.setOutlineColor (Color (157, 209, 255));

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

    Text inputTextClass ("Please enter your class", font, 25);
    inputTextClass.setPosition (410, 600);
    inputTextClass.setFillColor (Color (52, 142, 254));

    Text submitViewClassText ("Submit!", font, 25);
    submitViewClassText.setPosition (410, 700);
    submitViewClassText.setFillColor (Color (52, 142, 254));

    Text exitStaffScreenText ("Exit!", font, 25);
    exitStaffScreenText.setPosition (410, 800);
    exitStaffScreenText.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 735);
    invalidWarning.setFillColor (Color (198, 40, 40));

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
                submitViewClass.setFillColor (Color(202, 216, 229));
                check = 0;
                if (checkValidClass(inputTextClass.getString())) {
                    StudentListInClassScreen (app, inputTextClass.getString(), idInput, passwordInput);
                }
                else {
                    invalidWarning.setString("Can't find class!");
                    inputTmp = "";
                    inputTextClass.setString("");
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxClass.getGlobalBounds().contains (mousePos) && check != 1)
                {
                    inputBoxClass.setFillColor (Color (202, 216, 229));
                    check = 1;
                    inputTmp = "";
                }
                else if (submitViewClass.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    submitViewClass.setFillColor (Color(202, 216, 229));
                    if (checkValidClass(inputTextClass.getString())) {
                        StudentListInClassScreen (app, inputTextClass.getString(), idInput, passwordInput);
                    }
                    else {
                        invalidWarning.setString("Wrong id or password!");
                        inputTmp = "";
                        inputTextClass.setString("");
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
                if (inputBoxClass.getGlobalBounds().contains(mousePos))
                {
                    inputBoxClass.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxClass.setFillColor (Color::White);
                }
                if (submitViewClass.getGlobalBounds().contains(mousePos))
                {
                    submitViewClass.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    submitViewClass.setFillColor (Color::White);
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
                    inputTextClass.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextClass.getString().isEmpty()) {
                    inputTmp.pop_back ();
                    inputTextClass.setString (inputTmp);
                }
            }
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (inputBoxClass);
        app.draw (inputTextClass);

        app.draw (submitViewClass);
        app.draw (submitViewClassText);

        app.draw (exitStaffScreen);
        app.draw (exitStaffScreenText);

        app.draw (invalidWarning);

        app.display ();
    }
}
