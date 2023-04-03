#include "MainScreen.h"

void StudentScoreBoardScreen(string nameInput, string classInput)
{
    RenderWindow app (VideoMode (1920, 1080), "Student Screen", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    while (app.isOpen ()){
        Event e;
        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
        }

        app.clear (Color (96, 169, 255));
        app.display ();
    }
}
