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
Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram program) {
    this->studentID;
    this->firstName;
    this->lastName;
    this->email;
    this->age;
    for (int i = 0; i<countDays; i++) this->days[i] = days[i];
    this->program;
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
    cout << "Student ID: " + studentID << endl;
    cout << "First Name: " + firstName << endl;
    cout << "Last Name: " + lastName << endl;
    cout << "Email: " + email << endl;
    cout << "Age: " + to_string(age) << endl;
    cout << "Degree Program: " + program << endl;
    cout << "Days in Courses: " + to_string(days[0]) + ", " + to_string(days[1]) + ", " + to_string(days[2]);
}

Student::~Student()
{

}

#endif