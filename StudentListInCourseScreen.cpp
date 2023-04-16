#include "StudentListInCourseScreen.h"
#include "StaffOperationScreen.h"

void StudentListinCourseScreen(string coursename)
{
    RenderWindow app (VideoMode (1920, 1080), "Course's Students", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    // Button Shape
    RectangleShape buttonBack (Vector2f (200, 50));
    buttonBack.setFillColor (Color::White);
    buttonBack.setPosition (850, 800);
    buttonBack.setOutlineThickness(2);
    buttonBack.setOutlineColor(Color (157, 209, 255));

    // Button Text
    Text buttonTextBack ("Back", font, 25);
    buttonTextBack.setPosition (935, 805);
    buttonTextBack.setFillColor (Color (52, 142, 254));

    while (app.isOpen ()){
        Event e;
        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
            else if (e.type == Event::MouseButtonPressed)
            {
                Vector2f mousePos = app.mapPixelToCoords (Mouse::getPosition(app));
                if (buttonBack.getGlobalBounds ().contains (mousePos))
                {
                    buttonBack.setFillColor (Color (202, 216, 229));
                    StaffOperationScreen(app);
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
            }
        }
        Text StudentListCourse("",font,16);
        StudentListCourse.setPosition(20,20);
        StudentListCourse.setFillColor (Color (136, 136, 136));
        ifstream fin("StudentInCourse.txt");
        string line;
        string AllStudentInfo;

        while (getline(fin,line))
        {
            stringstream ss(line);
            string info;
            int cur=1;
            while (getline(ss,info,','))
            {
                if(cur==1)
                {
                    if (info!=coursename)
                        break;
                    cur++;
                }
                else
                {
                    AllStudentInfo+=(info+"\n");
                }
            }
        }
        StudentListCourse.setString(AllStudentInfo);


        app.clear (Color (96, 169, 255));
        app.draw(StudentListCourse);
        app.draw (buttonBack);
        app.draw (buttonTextBack);
        app.display ();
    }
}
