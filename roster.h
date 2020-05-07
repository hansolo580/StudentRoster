#ifndef ROSTER_H_
#define ROSTER_H

using namespace std;
#include "student.h"


class Roster{
public:
    Student** classRosterArray[5];

    Roster();
    void append(string entry);
};

#endif