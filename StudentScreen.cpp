#include "StudentScreen.h"
#include "StudentScoreBoardScreen.h"

void StudentScreen ()
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

    RectangleShape inputBoxName (Vector2f (500, 30));
    inputBoxName.setFillColor (Color::White);
    inputBoxName.setPosition (400, 600);
    inputBoxName.setOutlineThickness (2);
    inputBoxName.setOutlineColor (Color (157, 209, 255));

    RectangleShape inputBoxClass (Vector2f (500, 30));
    inputBoxClass.setFillColor (Color::White);
    inputBoxClass.setPosition (400, 700);
    inputBoxClass.setOutlineThickness (2);
    inputBoxClass.setOutlineColor (Color (157, 209, 255));

    RectangleShape submitViewScoreBoard (Vector2f (200, 30));
    submitViewScoreBoard.setFillColor (Color::White);
    submitViewScoreBoard.setPosition (400, 800);
    submitViewScoreBoard.setOutlineThickness (2);
    submitViewScoreBoard.setOutlineColor (Color (157, 209, 255));

    RectangleShape exitStudentScreen (Vector2f (200, 30));
    exitStudentScreen.setFillColor (Color::White);
    exitStudentScreen.setPosition (400, 900);
    exitStudentScreen.setOutlineThickness (2);
    exitStudentScreen.setOutlineColor (Color (157, 209, 255));

    // Text
    Text requireToEnterText ("Please enter your information!", font, 25);
    requireToEnterText.setPosition (410, 310);
    requireToEnterText.setFillColor (Color (136, 136, 136));

    Text inputTextName ("Please enter your name", font, 25);
    inputTextName.setPosition (410, 600);
    inputTextName.setFillColor (Color (52, 142, 254));

    Text inputTextClass ("Please enter your class", font, 25);
    inputTextClass.setPosition (410, 700);
    inputTextClass.setFillColor (Color (52, 142, 254));

    Text submitViewScoreBoardText ("Submit!", font, 25);
    submitViewScoreBoardText.setPosition (410, 800);
    submitViewScoreBoardText.setFillColor (Color (52, 142, 254));

    Text exitStudentScreenText ("Exit!", font, 25);
    exitStudentScreenText.setPosition (410, 900);
    exitStudentScreenText.setFillColor (Color (52, 142, 254));

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
                exitStudentScreen.setFillColor (Color(202, 216, 229));
                app.close ();
            }
            else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter)
            {
                submitViewScoreBoard.setFillColor (Color(202, 216, 229));
                check = 0;
                if (inputTextName.getString() != "Please enter your name" && inputTextClass.getString() != "Please enter your class") {
                    StudentScoreBoardScreen(inputTextName.getString(), inputTextClass.getString());
                }
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (inputBoxName.getGlobalBounds().contains (mousePos) && check != 1)
                {
                    inputBoxName.setFillColor (Color (202, 216, 229));
                    check = 1;
                    inputTmp = "";
                }
                else if (inputBoxClass.getGlobalBounds().contains (mousePos) && check != 2)
                {
                    inputBoxClass.setFillColor (Color (202, 216, 229));
                    check = 2;
                    inputTmp = "";
                }
                else if (submitViewScoreBoard.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    submitViewScoreBoard.setFillColor (Color(202, 216, 229));
                    if (inputTextName.getString() != "Please enter your name" && inputTextClass.getString() != "Please enter your class") {
                        StudentScoreBoardScreen(inputTextName.getString(), inputTextClass.getString());
                    }
                }
                else if (exitStudentScreen.getGlobalBounds().contains(mousePos))
                {
                    check = 0;
                    exitStudentScreen.setFillColor (Color(202, 216, 229));
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
                if (inputBoxName.getGlobalBounds().contains(mousePos))
                {
                    inputBoxName.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxName.setFillColor (Color::White);
                }
                if (inputBoxClass.getGlobalBounds().contains(mousePos))
                {
                    inputBoxClass.setFillColor(Color(225, 241, 255));
                }
                else
                {
                    inputBoxClass.setFillColor (Color::White);
                }
                if (submitViewScoreBoard.getGlobalBounds().contains(mousePos))
                {
                    submitViewScoreBoard.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    submitViewScoreBoard.setFillColor (Color::White);
                }
                if (exitStudentScreen.getGlobalBounds().contains(mousePos))
                {
                    exitStudentScreen.setFillColor (Color(225, 241, 255));
                }
                else
                {
                    exitStudentScreen.setFillColor (Color::White);
                }
            }
            else if (e.type == Event::TextEntered && check == 1)
            {
                if (e.text.unicode < 128 && e.text.unicode != '\b') {
                    inputTmp += e.text.unicode;
                    inputTextName.setString (inputTmp);
                }
                else if (e.text.unicode == '\b' && !inputTextName.getString().isEmpty()) {
                    inputTmp.pop_back ();
                    inputTextName.setString (inputTmp);
                }
            }
            else if (e.type == Event::TextEntered && check == 2)
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
        app.draw (inputBoxName);
        app.draw (inputTextName);
        app.draw (inputBoxClass);
        app.draw (inputTextClass);
        app.draw (submitViewScoreBoard);
        app.draw (submitViewScoreBoardText);
        app.draw (exitStudentScreen);
        app.draw (exitStudentScreenText);
        app.display ();
    }
}
