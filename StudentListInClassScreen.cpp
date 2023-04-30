#include "MainScreen.h"
#include "addClass.h"
#include "readCSVAddStudentToClass.h"
#include "StaffSearchClass.h"
#include "StudentListInClassScreen.h"
#include "AddStudentScreen.h"
#include "RemoveStudentScreen.h"

void StudentListInClassScreen (RenderWindow &app, string classInput, string idInput, string passwordInput)
{
    transform(classInput.begin(), classInput.end(), classInput.begin(), ::toupper);
    int page = 1;
    Class* pHead = nullptr;
    addClass (pHead, classInput);
    readCSVAddStudentToClass (pHead, classInput);

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

    RectangleShape classBox (Vector2f (600, 75));
    classBox.setFillColor (Color::White);
    classBox.setPosition (675, 250);
    classBox.setOutlineThickness (2);
    classBox.setOutlineColor (Color (204, 204, 204));

    RectangleShape addStudentBox (Vector2f (200, 30));
    addStudentBox.setFillColor (Color::White);
    addStudentBox.setPosition (425, 800);
    addStudentBox.setOutlineThickness (2);
    addStudentBox.setOutlineColor (Color (157, 209, 255));

    RectangleShape removeStudentBox (Vector2f (200, 30));
    removeStudentBox.setFillColor (Color::White);
    removeStudentBox.setPosition (425, 900);
    removeStudentBox.setOutlineThickness (2);
    removeStudentBox.setOutlineColor (Color (157, 209, 255));

    RectangleShape buttonPage (Vector2f (30, 30));
    buttonPage.setFillColor (Color::White);
    buttonPage.setPosition (950, 1000);
    buttonPage.setOutlineThickness(2);
    buttonPage.setOutlineColor(Color (157, 209, 255));

    RectangleShape leftPage (Vector2f (100, 30));
    leftPage.setFillColor (Color::White);
    leftPage.setPosition (850, 1000);
    leftPage.setOutlineThickness(2);
    leftPage.setOutlineColor(Color (157, 209, 255));

    RectangleShape rightPage (Vector2f (100, 30));
    rightPage.setFillColor (Color::White);
    rightPage.setPosition (980, 1000);
    rightPage.setOutlineThickness(2);
    rightPage.setOutlineColor(Color (157, 209, 255));

    RectangleShape** buttonClassList = new RectangleShape*[6];
    for (int i = 0; i < 6; ++i) {
        buttonClassList[i] = new RectangleShape[5];
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            buttonClassList[i][j].setSize(Vector2f(200, 30));
            buttonClassList[i][j].setFillColor(Color::White);
            buttonClassList[i][j].setPosition(425 + 200 * j, 400 + 30 * i);
            buttonClassList[i][j].setOutlineThickness(2);
            buttonClassList[i][j].setOutlineColor(Color(157, 209, 255));
        }
    }

    // Button Text
    Text timeText ("", font, 25);
    timeText.setPosition (1510, 225);
    timeText.setFillColor (Color (136, 136, 136));

    Text classBoxText ("Class " + classInput, font, 50);
    classBoxText.setPosition (835, 255);
    classBoxText.setFillColor (Color (136, 136, 136));

    Text addStudentText ("Add new student", font, 25);
    addStudentText.setPosition (435, 800);
    addStudentText.setFillColor (Color (52, 142, 254));

    Text removeStudentText ("Remove student", font, 25);
    removeStudentText.setPosition (435, 900);
    removeStudentText.setFillColor (Color (52, 142, 254));

    Text buttonPageText (to_string(page), font, 25);
    buttonPageText.setPosition (960, 1000);
    buttonPageText.setFillColor (Color (52, 142, 254));

    Text leftPageText ("Previous", font, 25);
    leftPageText.setPosition (858, 1000);
    leftPageText.setFillColor (Color (52, 142, 254));

    Text rightPageText ("Next", font, 25);
    rightPageText.setPosition (1008, 1000);
    rightPageText.setFillColor (Color (52, 142, 254));

    Text invalidWarning ("", font, 15);
    invalidWarning.setPosition (410, 885);
    invalidWarning.setFillColor (Color (198, 40, 40));

    Text** buttonClassListText = new Text*[6];
    for (int i = 0; i < 6; ++i) {
        buttonClassListText[i] = new Text[5];
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            buttonClassListText[i][j].setFont (font);
            buttonClassListText[i][j].setCharacterSize (25);
            buttonClassListText[i][j].setPosition(435 + 200 * j, 400 + 30 * i);
            buttonClassListText[i][j].setFillColor (Color (52, 142, 254));
        }
    }

    // Define table
    buttonClassListText[0][0].setString ("ID");
    buttonClassListText[0][1].setString ("First name");
    buttonClassListText[0][2].setString ("Last name");
    buttonClassListText[0][3].setString ("Gender");
    buttonClassListText[0][4].setString ("Date of Birth");

    // Read file
    Student** tmpList = new Student*[50];
    int cnt = 0;
    for (Student* it = pHead->studentHead; it != nullptr; it = it->pNext) {
        ++cnt;
        tmpList[cnt] = it;
    }
    for (int i = 1; i <= 5; ++i) {
        if (i <= cnt) {
            buttonClassListText[i][0].setString(tmpList[i]->id);
            buttonClassListText[i][1].setString(tmpList[i]->firstName);
            buttonClassListText[i][2].setString(tmpList[i]->lastName);
            buttonClassListText[i][3].setString(tmpList[i]->gender);
            buttonClassListText[i][4].setString(to_string(tmpList[i]->dateOfBirth.day) + '/' + to_string(tmpList[i]->dateOfBirth.month) + '/' + to_string(tmpList[i]->dateOfBirth.year));
        }
        else {
            buttonClassListText[i][0].setString("");
            buttonClassListText[i][1].setString("");
            buttonClassListText[i][2].setString("");
            buttonClassListText[i][3].setString("");
            buttonClassListText[i][4].setString("");
        }
    }

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
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (leftPage.getGlobalBounds().contains (mousePos))
                {
                    leftPage.setFillColor (Color (202, 216, 229));
                    if (page > 1) {
                        --page;
                        buttonPageText.setString(to_string(page));
                        for (int i = 1; i <= 5; ++i) {
                            if ((page - 1) * 5 + i <= cnt) {
                                buttonClassListText[i][0].setString(tmpList[(page - 1) * 5 + i]->id);
                                buttonClassListText[i][1].setString(tmpList[(page - 1) * 5 + i]->firstName);
                                buttonClassListText[i][2].setString(tmpList[(page - 1) * 5 + i]->lastName);
                                buttonClassListText[i][3].setString(tmpList[(page - 1) * 5 + i]->gender);
                                buttonClassListText[i][4].setString(to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.day) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.month) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.year));
                            }
                            else {
                                buttonClassListText[i][0].setString("");
                                buttonClassListText[i][1].setString("");
                                buttonClassListText[i][2].setString("");
                                buttonClassListText[i][3].setString("");
                                buttonClassListText[i][4].setString("");
                            }
                        }
                    }
                }
                if (rightPage.getGlobalBounds().contains (mousePos))
                {
                    rightPage.setFillColor (Color (202, 216, 229));
                    if (page < 10) {
                        ++page;
                        buttonPageText.setString(to_string(page));
                        for (int i = 1; i <= 5; ++i) {
                            if ((page - 1) * 5 + i <= cnt) {
                                buttonClassListText[i][0].setString(tmpList[(page - 1) * 5 + i]->id);
                                buttonClassListText[i][1].setString(tmpList[(page - 1) * 5 + i]->firstName);
                                buttonClassListText[i][2].setString(tmpList[(page - 1) * 5 + i]->lastName);
                                buttonClassListText[i][3].setString(tmpList[(page - 1) * 5 + i]->gender);
                                buttonClassListText[i][4].setString(to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.day) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.month) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.year));
                            }
                            else {
                                buttonClassListText[i][0].setString("");
                                buttonClassListText[i][1].setString("");
                                buttonClassListText[i][2].setString("");
                                buttonClassListText[i][3].setString("");
                                buttonClassListText[i][4].setString("");
                            }
                        }
                    }
                }
                if (addStudentBox.getGlobalBounds().contains (mousePos))
                {
                    addStudentBox.setFillColor (Color (202, 216, 229));
                    if (cnt < 50) {
                        AddStudentScreen (app, classInput, idInput, passwordInput);
                    }
                    else {
                        invalidWarning.setString ("Class is full!");
                    }
                }
                if (removeStudentBox.getGlobalBounds().contains (mousePos))
                {
                    removeStudentBox.setFillColor (Color (202, 216, 229));
                    if (cnt > 0) {
                        RemoveStudentScreen (app, classInput, idInput, passwordInput);
                    }
                    else {
                        invalidWarning.setString ("Class is empty!");
                    }
                }
            }
            else if (e.type == Event::MouseMoved)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (leftPage.getGlobalBounds ().contains (mousePos))
                {
                    leftPage.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    leftPage.setFillColor (Color::White);
                }
                if (rightPage.getGlobalBounds ().contains (mousePos))
                {
                    rightPage.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    rightPage.setFillColor (Color::White);
                }
                if (addStudentBox.getGlobalBounds ().contains (mousePos))
                {
                    addStudentBox.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    addStudentBox.setFillColor (Color::White);
                }
                if (removeStudentBox.getGlobalBounds ().contains (mousePos))
                {
                    removeStudentBox.setFillColor (Color (225, 241, 255));
                }
                else
                {
                    removeStudentBox.setFillColor (Color::White);
                }
            }
            else if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Escape)
                {
                    StaffSearchClassScreen(app, idInput, passwordInput);
                }
                else if (e.key.code == sf::Keyboard::Left) {
                    leftPage.setFillColor (Color (202, 216, 229));
                    if (page > 1) {
                        --page;
                        buttonPageText.setString(to_string(page));
                        for (int i = 1; i <= 5; ++i) {
                            if ((page - 1) * 5 + i <= cnt) {
                                buttonClassListText[i][0].setString(tmpList[(page - 1) * 5 + i]->id);
                                buttonClassListText[i][1].setString(tmpList[(page - 1) * 5 + i]->firstName);
                                buttonClassListText[i][2].setString(tmpList[(page - 1) * 5 + i]->lastName);
                                buttonClassListText[i][3].setString(tmpList[(page - 1) * 5 + i]->gender);
                                buttonClassListText[i][4].setString(to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.day) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.month) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.year));
                            }
                            else {
                                buttonClassListText[i][0].setString("");
                                buttonClassListText[i][1].setString("");
                                buttonClassListText[i][2].setString("");
                                buttonClassListText[i][3].setString("");
                                buttonClassListText[i][4].setString("");
                            }
                        }
                    }
                }
                else if (e.key.code == sf::Keyboard::Right) {
                    rightPage.setFillColor (Color (202, 216, 229));
                    if (page < 10) {
                        ++page;
                        buttonPageText.setString(to_string(page));
                        for (int i = 1; i <= 5; ++i) {
                            if ((page - 1) * 5 + i <= cnt) {
                                buttonClassListText[i][0].setString(tmpList[(page - 1) * 5 + i]->id);
                                buttonClassListText[i][1].setString(tmpList[(page - 1) * 5 + i]->firstName);
                                buttonClassListText[i][2].setString(tmpList[(page - 1) * 5 + i]->lastName);
                                buttonClassListText[i][3].setString(tmpList[(page - 1) * 5 + i]->gender);
                                buttonClassListText[i][4].setString(to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.day) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.month) + '/' + to_string(tmpList[(page - 1) * 5 + i]->dateOfBirth.year));
                            }
                            else {
                                buttonClassListText[i][0].setString("");
                                buttonClassListText[i][1].setString("");
                                buttonClassListText[i][2].setString("");
                                buttonClassListText[i][3].setString("");
                                buttonClassListText[i][4].setString("");
                            }
                        }
                    }
                }
            }
        }

        app.clear (Color (96, 169, 255));

        app.draw (Background);

        app.draw (timeBox);
        app.draw (timeText);

        app.draw (classBox);
        app.draw (classBoxText);

        app.draw (addStudentBox);
        app.draw (addStudentText);

        app.draw (removeStudentBox);
        app.draw (removeStudentText);

        app.draw (buttonPage);
        app.draw (buttonPageText);

        app.draw (leftPage);
        app.draw (leftPageText);

        app.draw (rightPage);
        app.draw (rightPageText);

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 5; ++j) {
                app.draw (buttonClassList[i][j]);
                app.draw (buttonClassListText[i][j]);
            }
        }

        app.display ();
    }

    for (int i = 0; i < 6; ++i) {
        delete[] buttonClassList[i];
        delete[] buttonClassListText[i];
    }
    delete[] buttonClassList;
    delete[] buttonClassListText;
    delete pHead;
}
