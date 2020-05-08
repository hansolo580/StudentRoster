#ifndef ROSTER_H_
#define ROSTER_H

#include "student.h"
#include <string>
#include <iostream>


class Roster{

private:
    int finalIndex; //essentially an int representing the array length of the roster
    int maxSize; //the total potential size of the roster
    Student** classRosterArray;

public:
    Roster();
    Roster(int maxSize);
    ~Roster();

    Student* getStudent(int index);
    void parseEntries(string row);//the parser - grabs strings, converts to Student objects, and adds to Roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
            int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); //called in parser to complete the add
    void remove(string studentID); //removes student by roster
    void printAll(); //prints every Student by iterating through Roster and using Student print()
    void printAverageDaysInCourse(string studentID);//calculates and displays average days in a course for a particular student
    void printInvalidEmails();//verifies email addresses and prints invalid emails
    void printByDegreeProgram(DegreeProgram degreeProgram);//prints students in a given program
};

#endif