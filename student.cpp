#include "student.h"
#include <string>
using namespace std;



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

string Student::setStudentID(string newID)
{
    studentID = newID;
    return 0;
}

string Student::setFirstName(string newFirst)
{
    firstName = newFirst;
    return 0;
}

string Student::setLastName(string newLast)
{
    lastName = newLast;
    return 0;
}

string Student::setEmail(string newEmail)
{
    email = newEmail;
    return 0;
}

int Student::setAge(int newAge)
{
    age = newAge;
    return 0;
}

int Student::setDays(int position, int newDay)
{
    days[position] = newDay;
    return 0;
}

Student::Student(string setStudentID, string setFirstName, string setLastName, string setEmail, int setAge, int day1, int day2, int day3, string setDegreeProgram) {
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
