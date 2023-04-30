#include "MainScreen.h"
#include "AddStudentScreen.h"
#include "StudentListInClassScreen.h"

bool checkExistAddStudent (string classInput, string id)
{
    // Check existed ID
    ifstream fin ("Src/FileCSV/" + classInput + ".csv");
    if (fin.is_open()) {
        string info, tmp;
        while (getline (fin, info)) {
            stringstream ss (info);
            while (getline (ss, tmp, ',')) {
                if (tmp == id) {
                    return false;
                }
            }
        }
        fin.close();
    }
    return true;
}

bool checkValidAddStudent (string id, string firstname, string lastname, string gender, string dob, string socialID)
{
    // Regular expressions to check format
    regex idRegex("\\d{8}");
    regex genderRegex("(Male|Female)");
    regex dobRegex("\\d{2}/\\d{2}/\\d{4}");
    regex socialIdRegex("\\d{12}");

    // Check if input strings match format
    if (!regex_match(id, idRegex)) {
        return false;
    }
    if (!regex_match(gender, genderRegex)) {
        return false;
    }
    if (!regex_match(dob, dobRegex)) {
        return false;
    }
    if (!regex_match(socialID, socialIdRegex)) {
        return false;
    }

    return true;
}

void addStudentCSV (string classInput, string id, string firstname, string lastname, string gender, string dob, string socialID)
{
    ofstream fout ("Src/FileCSV/" + classInput + ".csv", ios_base::app);

    if (fout.is_open()) {
       fout << '\n' << id << ',' << firstname << ',' << lastname << ',' << gender << ',' << classInput << ',' << dob << ',' << socialID << '\n' << '\n';
       fout.close();
    }
}

void AddStudentScreen (RenderWindow &app, string classInput, string idInput, string passwordInput)
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

    // Button Shape
    RectangleShape timeBox (Vector2f (220, 50));
    timeBox.setFillColor (Color::White);
    timeBox.setPosition (1500, 220);
    timeBox.setOutlineThickness (2);
    timeBox.setOutlineColor (Color (204, 204, 204));

    RectangleShape requireToEnter (Vector2f (700, 75));
    requireToEnter.setFillColor (Color::White);
    requireToEnter.setPosition (400, 300);
    requireToEnter.setOutlineThickness (2);
    requireToEnter.setOutlineColor (Color (204, 204, 204));

    RectangleShape idStudent (Vector2f (500, 30));
    idStudent.setFillColor (Color::White);
    idStudent.setPosition (400, 450);
    idStudent.setOutlineThickness (2);
    idStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape firstnameStudent (Vector2f (500, 30));
    firstnameStudent.setFillColor (Color::White);
    firstnameStudent.setPosition (400, 550);
    firstnameStudent.setOutlineThickness (2);
    firstnameStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape lastnameStudent (Vector2f (500, 30));
    lastnameStudent.setFillColor (Color::White);
    lastnameStudent.setPosition (1100, 550);
    lastnameStudent.setOutlineThickness (2);
    lastnameStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape genderStudent (Vector2f (500, 30));
    genderStudent.setFillColor (Color::White);
    genderStudent.setPosition (400, 650);
    genderStudent.setOutlineThickness (2);
    genderStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape dateofbirthStudent (Vector2f (500, 30));
    dateofbirthStudent.setFillColor (Color::White);
    dateofbirthStudent.setPosition (1100, 650);
    dateofbirthStudent.setOutlineThickness (2);
    dateofbirthStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape socialIDStudent (Vector2f (500, 30));
    socialIDStudent.setFillColor (Color::White);
    socialIDStudent.setPosition (400, 750);
    socialIDStudent.setOutlineThickness (2);
    socialIDStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitStudent (Vector2f (200, 30));
    submitStudent.setFillColor (Color::White);
    submitStudent.setPosition (400, 850);
    submitStudent.setOutlineThickness (2);
    submitStudent.setOutlineColor (Color (157, 209, 255));

    RectangleShape buttonBack (Vector2f (200, 30));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (400, 1000);
    buttonBack.setOutlineThickness (2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text requireToEnterText ("Please enter your information!", font, 50);
    requireToEnterText.setPosition (410, 305);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text idStudentText ("Student's ID", font, 25);
    idStudentText.setPosition (410, 450);
    idStudentText.setFillColor (Color (52, 142, 254));

    Text firstnameStudentText ("Student's first name", font, 25);
    firstnameStudentText.setPosition (410, 550);
    firstnameStudentText.setFillColor (Color (52, 142, 254));

    Text lastnameStudentText ("Student's last name", font, 25);
    lastnameStudentText.setPosition (1110, 550);
    lastnameStudentText.setFillColor (Color (52, 142, 254));

    Text genderStudentText ("Student's gender", font, 25);
    genderStudentText.setPosition (410, 650);
    genderStudentText.setFillColor (Color (52, 142, 254));

    Text dateofbirthStudentText ("Student's date of birth", font, 25);
    dateofbirthStudentText.setPosition (1110, 650);
    dateofbirthStudentText.setFillColor (Color (52, 142, 254));

    Text socialIDStudentText ("Student's social ID", font, 25);
    socialIDStudentText.setPosition (410, 750);
    socialIDStudentText.setFillColor (Color (52, 142, 254));

    Text submitStudentText ("Submit!", font, 25);
    submitStudentText.setPosition (410, 850);
    submitStudentText.setFillColor (Color (52, 142, 254));

    Text buttonTextBack ("Return", font, 25);
    buttonTextBack.setPosition (410, 1000);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 885);
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
                StudentListInClassScreen (app, classInput, idInput, passwordInput);
            }
            else if (e.type == Event::KeyPressed && e.key.code == Keyboard::Enter)
            {
                submitStudent.setFillColor (Color(202, 216, 229));
                check = 0;
                // Condition
                if (!checkExistAddStudent (classInput, idStudentText.getString())) {
                    invalidWarning.setString("Student exists!");
                }
                else if (!checkValidAddStudent(idStudentText.getString(), firstnameStudentText.getString(), lastnameStudentText.getString(), genderStudentText.getString(), dateofbirthStudentText.getString(), socialIDStudentText.getString())) {
                    invalidWarning.setString("Wrong format of input!");
                }
                else {
                    invalidWarning.setString("Add student successfully!");
                    addStudentCSV (classInput, idStudentText.getString(), firstnameStudentText.getString(), lastnameStudentText.getString(), genderStudentText.getString(), dateofbirthStudentText.getString(), socialIDStudentText.getString());
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    check = 0;
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StudentListInClassScreen (app, classInput, idInput, passwordInput);
                }
                else if (submitStudent.getGlobalBounds ().contains (mousePos))
                {
                    submitStudent.setFillColor (Color(202, 216, 229));
                    check = 0;
                    // Condition
                    if (!checkExistAddStudent (classInput, idStudentText.getString())) {
                        invalidWarning.setString("Student exists!");
                    }
                    else if (!checkValidAddStudent(idStudentText.getString(), firstnameStudentText.getString(), lastnameStudentText.getString(), genderStudentText.getString(), dateofbirthStudentText.getString(), socialIDStudentText.getString())) {
                        invalidWarning.setString("Wrong format of input!");
                    }
                    else {
                        invalidWarning.setString("Add student successfully!");
                        addStudentCSV (classInput, idStudentText.getString(), firstnameStudentText.getString(), lastnameStudentText.getString(), genderStudentText.getString(), dateofbirthStudentText.getString(), socialIDStudentText.getString());
                    }
                }
                else if (idStudent.getGlobalBounds ().contains (mousePos))
                {
                    idStudent.setFillColor (Color (202, 216, 229));
                    if (check != 1) {
                        check = 1;
                        inputTmp = "";
                        idStudentText.setString (inputTmp);
                    }
                }
                else if (firstnameStudent.getGlobalBounds ().contains (mousePos))
                {
                    firstnameStudent.setFillColor (Color (202, 216, 229));
                    if (check != 2) {
                        check = 2;
                        inputTmp = "";
                        firstnameStudentText.setString (inputTmp);
                    }
                }
                else if (lastnameStudent.getGlobalBounds ().contains (mousePos))
                {
                    lastnameStudent.setFillColor (Color (202, 216, 229));
                    if (check != 3) {
                        check = 3;
                        inputTmp = "";
                        lastnameStudentText.setString (inputTmp);
                    }
                }
                else if (genderStudent.getGlobalBounds ().contains (mousePos))
                {
                    genderStudent.setFillColor (Color (202, 216, 229));
                    if (check != 4) {
                        check = 4;
                        inputTmp = "";
                        genderStudentText.setString (inputTmp);
                    }
                }
                else if (dateofbirthStudent.getGlobalBounds ().contains (mousePos))
                {
                    dateofbirthStudent.setFillColor (Color (202, 216, 229));
                    if (check != 5) {
                        check = 5;
                        inputTmp = "";
                        dateofbirthStudentText.setString (inputTmp);
                    }
                }
                else if (socialIDStudent.getGlobalBounds ().contains (mousePos))
                {
                    socialIDStudent.setFillColor (Color (202, 216, 229));
                    if (check != 6) {
                        check = 6;
                        inputTmp = "";
                        socialIDStudentText.setString (inputTmp);
                    }
                }
                else {
                    check = 0;
                    inputTmp = "";
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
                if (submitStudent.getGlobalBounds ().contains (mousePos))
                {
                    submitStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    submitStudent.setFillColor (Color::White);
                }
                if (idStudent.getGlobalBounds ().contains (mousePos))
                {
                    idStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    idStudent.setFillColor (Color::White);
                }
                if (firstnameStudent.getGlobalBounds ().contains (mousePos))
                {
                    firstnameStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    firstnameStudent.setFillColor (Color::White);
                }
                if (lastnameStudent.getGlobalBounds ().contains (mousePos))
                {
                    lastnameStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    lastnameStudent.setFillColor (Color::White);
                }
                if (genderStudent.getGlobalBounds ().contains (mousePos))
                {
                    genderStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    genderStudent.setFillColor (Color::White);
                }
                if (dateofbirthStudent.getGlobalBounds ().contains (mousePos))
                {
                    dateofbirthStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    dateofbirthStudent.setFillColor (Color::White);
                }
                if (socialIDStudent.getGlobalBounds ().contains (mousePos))
                {
                    socialIDStudent.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    socialIDStudent.setFillColor (Color::White);
                }
            }
            else if (e.type == Event::TextEntered && check == 1)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    idStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !idStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        idStudentText.setString (inputTmp);
                    }
                    else {
                        idStudentText.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 2)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    firstnameStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !firstnameStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        firstnameStudentText.setString (inputTmp);
                    }
                    else {
                        firstnameStudentText.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 3)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    lastnameStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !lastnameStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        lastnameStudentText.setString (inputTmp);
                    }
                    else {
                        lastnameStudentText.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 4)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    genderStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !genderStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        genderStudentText.setString (inputTmp);
                    }
                    else {
                        genderStudentText.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 5)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    dateofbirthStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !dateofbirthStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        dateofbirthStudentText.setString (inputTmp);
                    }
                    else {
                        dateofbirthStudentText.setString ("");
                    }
                }
            }
            else if (e.type == Event::TextEntered && check == 6)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    socialIDStudentText.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !socialIDStudentText.getString().isEmpty()) {
                    if (inputTmp.size() > 0) {
                        inputTmp.pop_back ();
                        socialIDStudentText.setString (inputTmp);
                    }
                    else {
                        socialIDStudentText.setString ("");
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

        app.draw (idStudent);
        app.draw (idStudentText);

        app.draw (firstnameStudent);
        app.draw (firstnameStudentText);

        app.draw (lastnameStudent);
        app.draw (lastnameStudentText);

        app.draw (genderStudent);
        app.draw (genderStudentText);

        app.draw (dateofbirthStudent);
        app.draw (dateofbirthStudentText);

        app.draw (socialIDStudent);
        app.draw (socialIDStudentText);

        app.draw (submitStudent);
        app.draw (submitStudentText);

        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.draw (invalidWarning);

        app.display ();
    }
}
