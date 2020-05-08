#ifndef STUDENT_CPP_
#define STUDENT_CPP_

#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <iomanip>

using std::cout;
using std::left;
using std::setw;

Student::Student()//Empty constructor to provide defaults
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i<countDays; i++) this->days[i] = 0;
    //for loop iterates over days array to create [0, 0, 0]
}

//Actual constructor
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmail, int newAge, int newDays[],
        DegreeProgram newProgram) {
    this->studentID = newStudentID;
    this->firstName = newFirstName;
    this->lastName = newLastName;
    this->email = newEmail;
    this->age = newAge;
    for (int i = 0; i<countDays; i++) this->days[i] = newDays[i];
    this->program = newProgram;
}


//GETS
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

int * Student::getDays()
{
    return days;
}

DegreeProgram Student::getDegreeProgram()
{
    return program;
}


//SETS
void Student::setStudentID(string newID)
{
    studentID = newID;
}

void Student::setFirstName(string newFirst)
{
    firstName = newFirst;
}

void Student::setLastName(string newLast)
{
    lastName = newLast;
}

void Student::setEmail(string newEmail)
{
    email = newEmail;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

void Student::setDays(int newDays[])
{
    for (int i = 0; i<countDays; i++)
        days[i] = newDays[i];
}

void Student::setDegreeProgram(DegreeProgram programInput)
{
    program = programInput;
}


void Student::print()
{
    cout << studentID << "\t";
    cout << "First Name: " + firstName << "\t";
    cout << "Last Name: " + lastName << "\t";
    cout << "Age: " + to_string(age) << "\t";
    cout << "daysInCourse: " + '{' + to_string(days[0]) + ", " + to_string(days[1]) + ", " + to_string(days[2]) + '}' << "\t";
    cout << degreeProgramStrings[getDegreeProgram()] << endl;
}

Student::~Student()
{

}

#endif