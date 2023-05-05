#include <iostream>
#include "viewCourseStu.h"
using namespace std;

void viewCourseStu(Student* studentHead, string id)
{
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

	Text timeText("", font, 20);
	timeText.setFillColor(Color::Black);
	timeText.setPosition(1520, 225);

	Text titleText("Your Course", font, 40);
	titleText.setFillColor(Color::White);
	titleText.setPosition(100, 100);

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

		while (app.pollEvent(e)) {
			if (e.type == Event::Closed)
			{
				app.close();
			}
		}
	}
	app.draw(Background);
	app.draw(timeBox);
	app.draw(timeText);
	app.draw(titleText);

	if (studentHead == nullptr)
		cout << "Empty List";
	exit();
	else
	{
		Student* cur = studentHead;
		while (cur != nullptr)
		{
			if (cur->id == id)
			{
				Course* courseCheck = cur->courseEnrolHead;
				Text courseId(courseCheck->id, font, 20);
				courseId.setPosition(100, 200 + 50 * count);
				app.draw(courseId);

				Text courseName(courseCheck->courseName, font, 20);
				studentName.setPosition(250, 200 + 50 * count);
				app.draw(courseName);

				Text teacher(courseCheck->teacherName, font, 20);
				studentName.setPosition(400, 200 + 50 * count);
				app.draw(teacher);
			}
			cur = cur->pNext;
		}
	}
}