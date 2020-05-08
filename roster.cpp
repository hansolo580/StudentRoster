#include "roster.h"
using std::cout;
using std::cerr;

Roster::Roster()
{
    this->maxSize = 0;
    this->finalIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
    this->maxSize = maxSize;
    this->finalIndex = -1;
    this->classRosterArray = new Student*[maxSize];
}

Student * Roster::getStudent(int index)
{
    return classRosterArray[index];
}

void Roster::parseEntries(string row)
{
    if (finalIndex < maxSize) {
        finalIndex++;

        //delimit strings on comma
        //studentID
        int rightside = row.find(",");
        string addStudentID = row.substr(0, rightside);

        //firstName
        int leftside = rightside + 1;
        rightside = row.find(",",leftside);
        string addFirstName = row.substr(leftside, rightside - leftside);

        //lastName
        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        string addLastName = row.substr(leftside, rightside - leftside);

        //email
        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        string addEmail = row.substr(leftside, rightside - leftside);

        //age
        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        int addAge = stoi(row.substr(leftside, rightside - leftside));

        //days
        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        int addDaysInCourse1 = stoi(row.substr(leftside, rightside - leftside));

        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        int addDaysInCourse2 = stoi(row.substr(leftside, rightside - leftside));

        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        int addDaysInCourse3 = stoi(row.substr(leftside, rightside - leftside));

        //program
        leftside = rightside + 1;
        rightside = row.find(",",leftside);
        string tmp;
        tmp = row.substr(leftside, rightside - leftside);
        DegreeProgram addDegreeProgram;
        if (tmp == "SECURITY"){addDegreeProgram = SECURITY;}
        else if (tmp == "NETWORK"){addDegreeProgram = NETWORK;}
        else if (tmp == "SOFTWARE"){addDegreeProgram = SOFTWARE;}
        else
        {
            cerr << "Invalid degree program. Please confirm data entry. The software will now exit.\n";
            exit(-1);
        }
        //add to repository
        add(addStudentID, addFirstName, addLastName, addEmail, addAge, addDaysInCourse1, addDaysInCourse2,
                addDaysInCourse3, addDegreeProgram);
    }
    else
    {
        cerr << "The entry has too many datapoints. Please confirm data entry.";
        exit(-1);
    }
}

//Adds parsed data to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int Days[Student::countDays];
    Days[0] = daysInCourse1;
    Days[1] = daysInCourse2;
    Days[2] = daysInCourse3;
    classRosterArray[finalIndex] = new Student(studentID, firstName, lastName, emailAddress, age, Days, degreeprogram);
    //cout << classRosterArray[0];
    //cout << classRosterArray[4];
}

void Roster::printAll()//calls the print method for each entry
{
    this->classRosterArray[1]->print();
    //for (int i = 0; i <= this->finalIndex; i++) (this->classRosterArray)[i]->print();
}


