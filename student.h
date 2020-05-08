#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "degree.h"

using namespace std;

class Student{
public:

    //constant values
    const static int countDays = 3;

    //Student values
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    DegreeProgram program;
    int days[countDays];

    //Student gets
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    //Student sets
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram program);

    //Constructors
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days[],
            DegreeProgram program);

    //Other Student Functions
    void print();

    //Destructors
    ~Student();
};

#endif