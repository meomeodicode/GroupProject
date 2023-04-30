#include "MainScreen.h"
#include "RemoveStudentScreen.h"
#include "StudentListInClassScreen.h"

bool checkExistRemoveStudent (string classInput, string id)
{
    // Check existed ID
    ifstream fin ("Src/FileCSV/" + classInput + ".csv");
    if (fin.is_open()) {
        string info, tmp;

        while (getline (fin, info)) {
            stringstream ss (info);
            while (getline (ss, tmp, ',')) {
                if (tmp == id) {
                    return true;
                }
            }
        }
        fin.close();
    }
    return false;
}

bool checkValidRemoveStudent (string id)
{
    // Regular expressions to check format
    regex idRegex("\\d{8}");

    // Check if input strings match format
    if (!regex_match(id, idRegex)) {
        return false;
    }

    return true;
}

void removeStudentCSV (string classInput, string id)
{
    ifstream fin ("Src/FileCSV/" + classInput + ".csv");
    ofstream fout ("Src/FileCSV/" + classInput + "_temp.csv");
    string fileString = "";

    if (fin.is_open() && fout.is_open()) {
        string info, tmp;
        while (getline (fin, info)) {
            stringstream ss (info);
            getline (ss, tmp, ',');
            if (tmp != id) {
                fileString = fileString + info + '\n';
                getline (fin, info);
                fileString = fileString + info + '\n';
                getline (fin, info);
                fileString = fileString + info + '\n';
            }
            else {
                getline (fin, info);
                getline (fin, info);
            }
        }
        fileString.pop_back();
        fin.close();

        fout << fileString;
        fout.close();

        // delete the original file
        if (remove(("Src/FileCSV/" + classInput + ".csv").c_str()) != 0) {
            perror("Error deleting file");
        }

        // rename the temp file to the original file name
        if (rename(("Src/FileCSV/" + classInput + "_temp.csv").c_str(), ("Src/FileCSV/" + classInput + ".csv").c_str()) != 0) {
            perror("Error renaming file");
        }
    }
}

void RemoveStudentScreen (RenderWindow &app, string classInput, string idInput, string passwordInput)
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

    RectangleShape submitStudent (Vector2f (200, 30));
    submitStudent.setFillColor (Color::White);
    submitStudent.setPosition (400, 550);
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

    Text submitStudentText ("Submit!", font, 25);
    submitStudentText.setPosition (410, 550);
    submitStudentText.setFillColor (Color (52, 142, 254));

    Text buttonTextBack ("Return", font, 25);
    buttonTextBack.setPosition (410, 1000);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 585);
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
                if (!checkValidRemoveStudent (idStudentText.getString())) {
                    invalidWarning.setString("Wrong format of input!");
                }
                else if (!checkExistRemoveStudent(classInput, idStudentText.getString())) {
                    invalidWarning.setString("Can't find student!");
                }
                else {
                    invalidWarning.setString("Remove student successfully!");
                    removeStudentCSV (classInput, idStudentText.getString());
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
                    if (!checkValidRemoveStudent (idStudentText.getString())) {
                        invalidWarning.setString("Wrong format of input!");
                    }
                    else if (!checkExistRemoveStudent(classInput, idStudentText.getString())) {
                        invalidWarning.setString("Can't find student!");
                    }
                    else {
                        invalidWarning.setString("Remove student successfully!");
                        removeStudentCSV (classInput, idStudentText.getString());
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
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (requireToEnter);
        app.draw (requireToEnterText);

        app.draw (idStudent);
        app.draw (idStudentText);

        app.draw (submitStudent);
        app.draw (submitStudentText);

        app.draw (buttonBack);
        app.draw (buttonTextBack);

        app.draw (invalidWarning);

        app.display ();
    }
}
