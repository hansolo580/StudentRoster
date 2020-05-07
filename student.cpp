#ifndef STUDENT_CPP_
#define STUDENT_CPP_

#include "student.h"
#include <string>
using namespace std;

string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmail()
{
    return email;
}

int Student::getAge()
{
    return age;
}

int Student::getDays()
{
    return days[0, 1, 2];
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

string Student::setStudentID(string newID)
{
    studentID = newID;
    return studentID;
}

string Student::setFirstName(string newFirst)
{
    firstName = newFirst;
    return firstName;
}

string Student::setLastName(string newLast)
{
    lastName = newLast;
    return lastName;
}

string Student::setEmail(string newEmail)
{
    email = newEmail;
    return email;
}

int Student::setAge(int newAge)
{
    age = newAge;
    return age;
}

int Student::setDays(int position, int newDay)
{
    days[position] = newDay;
    return days[position];
}

DegreeProgram Student::setDegreeProgram(DegreeProgram programInput)
{
    degreeProgram = programInput;
    return degreeProgram;
}

Student::Student(string setStudentID, string setFirstName, string setLastName, string setEmail, int setAge, int day1, int day2, int day3, DegreeProgram setDegreeProgram) {
    studentID = setStudentID;
    firstName = setFirstName;
    lastName = setLastName;
    email = setEmail;
    age = setAge;
    days[0] = day1;
    days[1] = day2;
    days[2] = day3;
    degreeProgram = setDegreeProgram;
    }

void Student::print(Student)
{
    cout << "Student ID: " + studentID << endl;
    cout << "First Name: " + firstName << endl;
    cout << "Last Name: " + lastName << endl;
    cout << "Email: " + email << endl;
    cout << "Age: " + to_string(age) << endl;
    cout << "Degree Program: " + degreeProgram << endl;
    cout << "Days in Courses: " + to_string(days[0]) + ", " + to_string(days[1]) + ", " + to_string(days[2]);
}

#endif