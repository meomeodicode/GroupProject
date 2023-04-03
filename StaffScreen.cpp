#include "MainScreen.h"
#include "StudentListInClassScreen.h"

void StaffScreen()
{
    RenderWindow app (VideoMode (1920, 1080), "Student Screen", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    string inputTmp;
    int check = 0;

    // Text Shape
    RectangleShape requireToEnter (Vector2f (600, 50));
    requireToEnter.setFillColor (Color::White);
    requireToEnter.setPosition (400, 300);
    requireToEnter.setOutlineThickness (2);
    requireToEnter.setOutlineColor (Color (157, 209, 255));

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

    // Screen
    while (app.isOpen ()){
        Event e;
        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
            else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
            {
                check = 0;
                exitStaffScreen.setFillColor (Color(202, 216, 229));
                app.close ();
            }
            else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter)
            {
                submitViewClass.setFillColor (Color(202, 216, 229));
                check = 0;
                if (inputTextClass.getString() != "Please enter your class") {
                    StudentListInClassScreen (inputTextClass.getString());
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
                    if (inputTextClass.getString() != "Please enter your class") {
                        StudentListInClassScreen (inputTextClass.getString());
                    }
                }
                else if (exitStaffScreen.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    exitStaffScreen.setFillColor (Color(202, 216, 229));
                    app.close ();
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
        app.draw (requireToEnter);
        app.draw (requireToEnterText);
        app.draw (inputBoxClass);
        app.draw (inputTextClass);
        app.draw (submitViewClass);
        app.draw (submitViewClassText);
        app.draw (exitStaffScreen);
        app.draw (exitStaffScreenText);
        app.display ();
    }
}
