#include "MainScreen.h"
#include "addClass.h"
#include "readCSVAddStudentToClass.h"

void StudentListInClassScreen (string classInput)
{
    RenderWindow app (VideoMode (1920, 1080), "Student Screen", Style::Default);
    Font font;
    font.loadFromFile("Src/Font/arial_narrow_7.ttf");

    Class* pHead22 = nullptr;
    addClass (pHead22, classInput);
    readCSVAddStudentToClass (pHead22);

    Text listOfStudent ("", font, 25);
    listOfStudent.setPosition (300, 100);
    listOfStudent.setFillColor (Color (136, 136, 136));

    string allStudentsInfo;
    for (Student* student = pHead22->studentHead; student != nullptr; student = student->pNext) {
        string studentInfo = "ID: " + student->id + "\n";
        studentInfo += "Name: " + student->firstName + " " + student->lastName + "\n";
        studentInfo += "Gender: " + student->gender + "\n";
        studentInfo += "Date of Birth: " + to_string (student->dateOfBirth.year) + "-" + to_string (student->dateOfBirth.month) + "-" + to_string (student->dateOfBirth.day) + "\n";
        studentInfo += "Social ID: " + student->socialID + "\n";
        studentInfo += "Overall GPA: " + to_string(student->overallGPA) + "\n" + "\n";
        allStudentsInfo += studentInfo;
    }
    listOfStudent.setString(allStudentsInfo);
    listOfStudent.move(0, 120);

    while (app.isOpen ()){
        Event e;
        while (app.pollEvent (e)){
            if (e.type == Event::Closed)
            {
                app.close ();
            }
        }

        app.clear (Color (96, 169, 255));
        app.draw(listOfStudent);
        app.display ();
    }
}
