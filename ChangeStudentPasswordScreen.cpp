#include "ChangeStudentPasswordScreen.h"
#include "StudentOperationScreen.h"

void changeStudentPasswordCSV (string idInput, string newPassword)
{
    ifstream fin ("Src/FileCSV/AccountStudent.csv");
    ofstream fout ("Src/FileCSV/AccountStudent_temp.csv");
    string fileString = "";

    if (fin.is_open() && fout.is_open()) {
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
                    if (id == idInput) {
                        fileString = fileString + id + ',' + newPassword + '\n';
                    }
                    else {
                        fileString = fileString + id + ',' + password + '\n';
                    }
                }
            }
        }
        fin.close();

        fout << fileString;
        fout.close();

        // delete the original file
        if (remove("Src/FileCSV/AccountStudent.csv") != 0) {
            perror("Error deleting file");
        }

        // rename the temp file to the original file name
        if (rename("Src/FileCSV/AccountStudent_temp.csv", "Src/FileCSV/AccountStudent.csv") != 0) {
            perror("Error renaming file");
        }
    }
}

void ChangeStudentPasswordScreen (RenderWindow &app, string idInput, string passwordInput)
{
    string inputTmp = "";
    int check = 0;

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

    RectangleShape inputBoxOldPassword (Vector2f (500, 30));
    inputBoxOldPassword.setFillColor (Color::White);
    inputBoxOldPassword.setPosition (400, 450);
    inputBoxOldPassword.setOutlineThickness (2);
    inputBoxOldPassword.setOutlineColor (Color (157, 209, 255));

    RectangleShape inputBoxNewPassword1 (Vector2f (470, 30));
    inputBoxNewPassword1.setFillColor (Color::White);
    inputBoxNewPassword1.setPosition (400, 550);
    inputBoxNewPassword1.setOutlineThickness (2);
    inputBoxNewPassword1.setOutlineColor (Color (157, 209, 255));

    RectangleShape inputBoxNewPassword2 (Vector2f (470, 30));
    inputBoxNewPassword2.setFillColor (Color::White);
    inputBoxNewPassword2.setPosition (400, 650);
    inputBoxNewPassword2.setOutlineThickness (2);
    inputBoxNewPassword2.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitButton (Vector2f (200, 30));
    submitButton.setFillColor (Color::White);
    submitButton.setPosition (400, 750);
    submitButton.setOutlineThickness(2);
    submitButton.setOutlineColor(Color (157, 209, 255));

    RectangleShape buttonBack (Vector2f (200, 30));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (400, 1000);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Change your password!", font, 50);
    requireToEnterText.setPosition (410, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text inputTextOldPassword ("Please enter your old password", font, 25);
    inputTextOldPassword.setPosition (410, 450);
    inputTextOldPassword.setFillColor (Color (52, 142, 254));

    Text inputTextNewPassword1 ("Please enter your new password", font, 25);
    inputTextNewPassword1.setPosition (410, 550);
    inputTextNewPassword1.setFillColor (Color (52, 142, 254));

    Text inputTextNewPassword2 ("Please reenter your new password", font, 25);
    inputTextNewPassword2.setPosition (410, 650);
    inputTextNewPassword2.setFillColor (Color (52, 142, 254));

    Text submitText ("Submit!", font, 25);
    submitText.setPosition (410, 750);
    submitText.setFillColor (Color (52, 142, 254));

    Text buttonTextBack ("Return", font, 25);
    buttonTextBack.setPosition (410, 1000);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 785);
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
                buttonBack.setFillColor (Color(202, 216, 229));
                StudentOperationScreen (app, idInput, passwordInput);
            }
            else if (e.type == Event::KeyPressed && e.key.code == Keyboard::Enter)
            {
                submitButton.setFillColor (Color(202, 216, 229));
                check = 0;
                // Condition
                if (inputTextOldPassword.getString() != passwordInput) {
                    invalidWarning.setString ("Wrong password!");
                }
                else {
                    if (inputTextNewPassword1.getString() != inputTextNewPassword2.getString() || inputTextNewPassword1.getString() == inputTextOldPassword.getString() || inputTextNewPassword2.getString() == inputTextOldPassword.getString()) {
                        invalidWarning.setString ("Please check your new password again!");
                    }
                    else {
                        invalidWarning.setString ("Change password successfully!");
                        changeStudentPasswordCSV (idInput, inputTextNewPassword1.getString());
                        passwordInput = inputTextNewPassword1.getString();
                    }
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    check = 0;
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StudentOperationScreen(app, idInput, passwordInput);
                }
                else if (inputBoxOldPassword.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxOldPassword.setFillColor (Color (202, 216, 229));
                    if (check != 1) {
                        check = 1;
                        inputTmp = "";
                        inputTextOldPassword.setString (inputTmp);
                    }
                }
                else if (inputBoxNewPassword1.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxNewPassword1.setFillColor (Color (202, 216, 229));
                    if (check != 2) {
                        check = 2;
                        inputTmp = "";
                        inputTextNewPassword1.setString (inputTmp);
                    }
                }
                else if (inputBoxNewPassword2.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxNewPassword2.setFillColor (Color (202, 216, 229));
                    if (check != 3) {
                        check = 3;
                        inputTmp = "";
                        inputTextNewPassword2.setString (inputTmp);
                    }
                }
                else if (submitButton.getGlobalBounds ().contains (mousePos))
                {
                    check = 0;
                    submitButton.setFillColor (Color (202, 216, 229));
                    // Condition
                    if (inputTextOldPassword.getString() != passwordInput) {
                        invalidWarning.setString ("Wrong password!");
                    }
                    else {
                        if (inputTextNewPassword1.getString() != inputTextNewPassword2.getString()) {
                            invalidWarning.setString ("Please check your new password again!");
                        }
                        else {
                            invalidWarning.setString ("Change password successfully!");
                            changeStudentPasswordCSV (idInput, inputTextNewPassword1.getString());
                            passwordInput = inputTextNewPassword1.getString();
                        }
                    }
                }
                else {
                    check = 0;
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
                if (submitButton.getGlobalBounds ().contains (mousePos))
                {
                    submitButton.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    submitButton.setFillColor (Color::White);
                }
                if (inputBoxOldPassword.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxOldPassword.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    inputBoxOldPassword.setFillColor (Color::White);
                }
                if (inputBoxNewPassword1.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxNewPassword1.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    inputBoxNewPassword1.setFillColor (Color::White);
                }
                if (inputBoxNewPassword2.getGlobalBounds ().contains (mousePos))
                {
                    inputBoxNewPassword2.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    inputBoxNewPassword2.setFillColor (Color::White);
                }
            }
            else if (e.type == Event::TextEntered && check == 1)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    inputTextOldPassword.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextOldPassword.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        inputTextOldPassword.setString (inputTmp);
                    }
                    else {
                        inputTextOldPassword.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 2)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    inputTextNewPassword1.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextNewPassword1.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        inputTextNewPassword1.setString (inputTmp);
                    }
                    else {
                        inputTextNewPassword1.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 3)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    inputTextNewPassword2.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextNewPassword2.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        inputTextNewPassword2.setString (inputTmp);
                    }
                    else {
                        inputTextNewPassword2.setString ("");
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

        app.draw (inputBoxOldPassword);
        app.draw (inputTextOldPassword);

        app.draw (inputBoxNewPassword1);
        app.draw (inputTextNewPassword1);

        app.draw (inputBoxNewPassword2);
        app.draw (inputTextNewPassword2);

        app.draw (submitButton);
        app.draw (submitText);

        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.draw (invalidWarning);

        app.display ();
    }
}
