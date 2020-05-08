#include "roster.h"
#include "student.h"
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
    int days[Student::countDays];
    days[0] = daysInCourse1;
    days[1] = daysInCourse2;
    days[2] = daysInCourse3;
    classRosterArray[finalIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);
}

void Roster::printAll()//calls the print method for each entry
{
    for (int i = 0; i <= this->finalIndex; i++) (this->classRosterArray)[i]->print();
}


void Roster::remove(string studentID)
{
    cout << "\n";
    for (int i = 0; i <= finalIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) //Student exists
        {
            //delete the student
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[finalIndex];
            finalIndex--;
            cout << "Student " + studentID + " deleted. \n";
        }
        else
        {
            cout << "Student " + studentID + " does not exist.";
        }
    }
    cout << "\n";
}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= finalIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) //Student exists
        {
            found = true;
            int* d = classRosterArray[i]->getDays();
            cout << "Average days in course " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
        }
    }
}

void Roster::printInvalidEmails()
{
    cout << "\nPrinting invalid emails: \n";
    for (int i = 0; i <= finalIndex; i++) {
        string emailToCheck = classRosterArray[i]->getEmail();
        if (emailToCheck.find("@") == string::npos)
        {
            cout << emailToCheck << "\n";
        }
        else if (emailToCheck.find(".") == string::npos)
        {
            cout << emailToCheck << "\n";
        }
        else if (emailToCheck.find(" ") != string::npos)
        {
            cout << emailToCheck << "\n";
        }


    }
    cout << "\n";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << "\nPrinting Students in program " << degreeProgramStrings[degreeProgram] << ":\n \n";
    for (int i = 0; i <= finalIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
    }
    cout << "\n";
}
//DESTRUCTOR
Roster::~Roster()
{
    for (int i = 0; i <= finalIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
}