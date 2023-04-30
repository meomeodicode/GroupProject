#include "MainScreen.h"
#include "StaffScreen.h"
#include "StaffOperationScreen.h"

bool checkValidStaffLogin (string IDStaff, string passwordStaff)
{
    ifstream fin ("Src/FileCSV/AccountStaff.csv");

    if (fin.is_open()) {
        string info, tmp;
        while (getline (fin, info)) {
            string id;
            string password;

            stringstream ss (info);
            int cnt = 1;
            while (getline (ss, tmp, ',')) {
                if (cnt == 1) {
                    id = tmp;
                    ++cnt;
                }
                else if (cnt == 2) {
                    password = tmp;
                    if (id == IDStaff && password == passwordStaff) {
                        return true;
                    }
                }
            }
        }
        fin.close();
    }

    return false;
}

void StaffScreen (RenderWindow &app)
{
    string inputTmp = "", passwordText = "", revealPasswordText = "";
    int check = 0, checkreveal = 0;

    // Font
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Image
    Texture SchoolMoodle;
    SchoolMoodle.loadFromFile("Src/Image/SchoolMoodle.png");
    Sprite Background(SchoolMoodle);
    Background.setPosition(0, 0);

    Texture noRevealPassword;
    Texture revealPassword;
    noRevealPassword.loadFromFile("Src/Image/noRevealPassword.jpg");
    revealPassword.loadFromFile("Src/Image/revealPassword.jpg");
    Sprite revealSwitch(noRevealPassword);
    revealSwitch.setPosition(870, 550);

    // Text Shape
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

    RectangleShape inputBoxStaffID (Vector2f (500, 30));
    inputBoxStaffID.setFillColor (Color::White);
    inputBoxStaffID.setPosition (400, 450);
    inputBoxStaffID.setOutlineThickness (2);
    inputBoxStaffID.setOutlineColor (Color (157, 209, 255));

    RectangleShape inputBoxPassword (Vector2f (470, 30));
    inputBoxPassword.setFillColor (Color::White);
    inputBoxPassword.setPosition (400, 550);
    inputBoxPassword.setOutlineThickness (2);
    inputBoxPassword.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitStaffLogin (Vector2f (200, 30));
    submitStaffLogin.setFillColor (Color::White);
    submitStaffLogin.setPosition (400, 650);
    submitStaffLogin.setOutlineThickness (2);
    submitStaffLogin.setOutlineColor (Color (157, 209, 255));

    RectangleShape exitStaffScreen (Vector2f (200, 30));
    exitStaffScreen.setFillColor (Color::White);
    exitStaffScreen.setPosition (400, 1000);
    exitStaffScreen.setOutlineThickness (2);
    exitStaffScreen.setOutlineColor (Color (157, 209, 255));

    RectangleShape revealButton(Vector2f (30, 30));
    revealButton.setPosition(870, 550);
    revealButton.setFillColor(Color::White);
    revealButton.setOutlineThickness(2);
    revealButton.setOutlineColor(Color (157, 209, 255));


    // Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Please login!", font, 50);
    requireToEnterText.setPosition (410, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text inputTextStaffID ("Please enter your staff ID", font, 25);
    inputTextStaffID.setPosition (410, 450);
    inputTextStaffID.setFillColor (Color (52, 142, 254));

    Text inputTextPassword ("Please enter your password", font, 25);
    inputTextPassword.setPosition (410, 550);
    inputTextPassword.setFillColor (Color (52, 142, 254));

    Text submitStaffLoginText ("Submit!", font, 25);
    submitStaffLoginText.setPosition (410, 650);
    submitStaffLoginText.setFillColor (Color (52, 142, 254));

    Text exitStaffScreenText ("Return", font, 25);
    exitStaffScreenText.setPosition (410, 1000);
    exitStaffScreenText.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 685);
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
            else if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
            {
                check = 0;
                exitStaffScreenText.setFillColor (Color(202, 216, 229));
                app.close ();
                MainScreen ();
            }
            else if (e.type == Event::KeyPressed && e.key.code == Keyboard::Enter)
            {
                check = 0;
                submitStaffLogin.setFillColor (Color(202, 216, 229));
                if (checkValidStaffLogin (inputTextStaffID.getString(), revealPasswordText)) {
                    StaffOperationScreen (app, inputTextStaffID.getString(), revealPasswordText);
                }
                else {
                    invalidWarning.setString("Wrong id or password!");
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxStaffID.getGlobalBounds().contains (mousePos))
                {
                    if (check != 1) {
                        inputBoxStaffID.setFillColor (Color (202, 216, 229));
                        check = 1;
                        inputTmp = "";
                    }
                    else {
                        inputBoxStaffID.setFillColor (Color (202, 216, 229));
                    }
                }
                else if (inputBoxPassword.getGlobalBounds().contains (mousePos))
                {
                    if (check != 2) {
                        inputBoxPassword.setFillColor (Color (202, 216, 229));
                        check = 2;
                        revealPasswordText = "";
                        passwordText = "";
                    }
                    else {
                        inputBoxPassword.setFillColor (Color (202, 216, 229));
                    }
                }
                else if (revealButton.getGlobalBounds().contains (mousePos))
                {
                    revealButton.setFillColor (Color (202, 216, 229));
                    checkreveal = 1 - checkreveal;
                    if (checkreveal == 0) {
                        inputTextPassword.setString (passwordText);
                        revealSwitch.setTexture(noRevealPassword);
                    }
                    else {
                        inputTextPassword.setString (revealPasswordText);
                        revealSwitch.setTexture(revealPassword);
                    }
                }
                else if (submitStaffLogin.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    submitStaffLogin.setFillColor (Color(202, 216, 229));
                    if (checkValidStaffLogin (inputTextStaffID.getString(), revealPasswordText)) {
                        StaffOperationScreen (app, inputTextStaffID.getString(), revealPasswordText);
                    }
                    else {
                        invalidWarning.setString("Wrong id or password!");
                    }
                }
                else if (exitStaffScreen.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    exitStaffScreen.setFillColor (Color(202, 216, 229));
                    app.close ();
                    MainScreen ();
                }
                else
                {
                    check = 0;
                }
            }
            else if (e.type == Event::MouseMoved)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxStaffID.getGlobalBounds().contains(mousePos))
                {
                    inputBoxStaffID.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxStaffID.setFillColor (Color::White);
                }
                if (inputBoxPassword.getGlobalBounds().contains(mousePos))
                {
                    inputBoxPassword.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxPassword.setFillColor (Color::White);
                }
                if (revealButton.getGlobalBounds().contains(mousePos))
                {
                    revealButton.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    revealButton.setFillColor (Color::White);
                }
                if (submitStaffLogin.getGlobalBounds().contains(mousePos))
                {
                    submitStaffLogin.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    submitStaffLogin.setFillColor (Color::White);
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
                    inputTextStaffID.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextStaffID.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        inputTextStaffID.setString (inputTmp);
                    }
                    else {
                        inputTextStaffID.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 2)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    revealPasswordText += e.text.unicode;
                    passwordText += '*';
                    if (checkreveal == 0) {
                        inputTextPassword.setString (passwordText);
                    }
                    else {
                        inputTextPassword.setString (revealPasswordText);
                    }
                }
                else if (e.text.unicode == '\b' && !inputTextPassword.getString().isEmpty()) {
                    if (revealPasswordText.size() > 0 && passwordText.size() > 0) {
                        revealPasswordText.pop_back ();
                        passwordText.pop_back ();
                        if (checkreveal == 0) {
                            inputTextPassword.setString (passwordText);
                        }
                        else {
                            inputTextPassword.setString (revealPasswordText);
                        }
                    }
                    else {
                        inputTextPassword.setString ("");
                    }
                }
            }
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (inputBoxStaffID);
        app.draw (inputTextStaffID);

        app.draw (inputBoxPassword);
        app.draw (inputTextPassword);

        app.draw (submitStaffLogin);
        app.draw (submitStaffLoginText);

        app.draw (exitStaffScreen);
        app.draw (exitStaffScreenText);

        app.draw (revealButton);
        app.draw (revealSwitch);

        app.draw (invalidWarning);

        app.display ();
    }
}
