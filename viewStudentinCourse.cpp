void viewStudentListInCourse (Course *course)
{
    Class* c=course->classHead;
    while (c)
    {
        viewStudentListInClass(c);
        c=c->pNext;
    }
    Student* s=course->studentHead;
    while(s)
    {
        cout<<s->firstName<<" "<<s->lastName<<endl;
        s=s->pNext;
    }

}
