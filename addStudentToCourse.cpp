void addStudentToCourse(Course *&course, Student student)
{
	course->students->pNext=student;
	course->students=course->students->pNext;
	course->students->pNext=nullptr;
}
