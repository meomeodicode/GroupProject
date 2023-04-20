#include <iostream>
#include <SFML/Graphics.hpp>
#include "struct.h"
#include "viewClass.h"
using namespace std;
using namespace sf;

void viewClass(Class* classhead)
{
    RenderWindow window(VideoMode(800, 600), "View Classes");
    Font font;
    font.loadFromFile("arial.ttf");
    Text titleText("Class List", font, 36);
    titleText.setPosition(200, 20);
    Text classText("", font, 24);
    classText.setPosition(100, 100);

    Class* cur = classhead;
    bool isEmpty = true;
    while (cur)
    {
        classText.setString(classText.getString() + cur->className + "\n");
        cur = cur->pNext;
        isEmpty = false;
    }
    if (isEmpty)
    {
        classText.setString("Empty List!");
    }
    while (window.isOpen())
    {
        // handle SFML events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // clear the SFML window
        window.clear(Color::White);

        // draw the title and class names on the SFML window
        window.draw(titleText);
        window.draw(classText);

        // display the SFML window
        window.display();
    }
}
