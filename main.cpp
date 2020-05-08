#include <iostream>
#include "roster.cpp"
#include "student.cpp"
using namespace std;



int main()
{
    cout << "Course: C867 - Scripting and Programming - Applications \n";
    cout << "Language: C++ \n";
    cout << "Student ID: 001213417 \n";
    cout << "Name: Luke Willey \n \n";

    int numStudents = 5;
    //data input as const string
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Luke,Willey,lwi1021@wgu.edu,27,15,15,15,SOFTWARE"
    };

    Roster * classRoster = new Roster(numStudents);//Creates the Roster
    cout <<"Reading student data and generating roster:\t";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->parseEntries(studentData[i]);
    }
    cout << "Parsing complete.\n";
    cout << "Displaying full roster:\n";
    classRoster->printAll();

    classRoster->printInvalidEmails();

    cout << "Printing average course lengths: \n";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
    }

    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");

    classRoster->printAll();

    classRoster->remove("A3");

}
