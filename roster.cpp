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
        DegreeProgram degreeProgram;
        if (std::to_string(degreeProgram) == "SECURITY"){degreeProgram = SECURITY;}
        else if (std::to_string(degreeProgram) == "NETWORK"){degreeProgram = NETWORK;}
        else if (std::to_string(degreeProgram) == "SOFTWARE"){degreeProgram = SOFTWARE;}
        else
        {
            cerr << "Invalid degree program. Please confirm data entry. The software will now exit.\n";
            exit(-1);
        }


    }
}




