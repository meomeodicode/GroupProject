#include <iostream>
#include "struct.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include <iostream>
#include "struct.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void viewClass(Class* classhead)
{
    RenderWindow app;
    Class* cur = classhead;
    int count = 1; //stt cua hoc lop 
    Font font;
    if (cur == nullptr)
    {
        Text noClassText("No classes found.", font, 30);
        noClassText.setFillColor(Color::White);
        noClassText.setPosition(100, 200);
        app.draw(noClassText);
        return;
    }

    // Image
    Texture SchoolMoodle;
    SchoolMoodle.loadFromFile("Src/Image/SchoolMoodle.png");
    Sprite Background(SchoolMoodle);
    Background.setPosition(0, 0);

    // Text Shape
    RectangleShape timeBox(Vector2f(220, 50));
    timeBox.setFillColor(Color::White);
    timeBox.setPosition(1500, 220);
    timeBox.setOutlineThickness(2);
    timeBox.setOutlineColor(Color(204, 204, 204));

    Text titleText("List of classes:", font, 40);
    titleText.setFillColor(Color::White);
    titleText.setPosition(100, 100);
    app.draw(titleText);

    // Text to display current time
    Text timeText("", font, 25);
    timeText.setPosition(1500, 220);

    while (app.isOpen())
    {
        Event e;
        chrono::system_clock::time_point now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        tm* localTime = localtime(&currentTime);
        stringstream tmpTimeString;
        tmpTimeString << put_time(localTime, "%d/%m/%Y %I:%M%p");
        string timeString = tmpTimeString.str();
        timeText.setString(timeString);

        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                app.close();
            }
        }

        // Draw class list
        while (cur != nullptr)
        {
            Text classText(cur->className, font, 25);
            classText.setPosition(100, 200 + 50 * count);
            app.draw(classText);
            cur = cur->pNext;
            count++;
        }

        // Draw current time
        app.draw(timeBox);
        app.draw(timeText);

        app.display();
        app.clear(Color::Black);
    }
    return;
}