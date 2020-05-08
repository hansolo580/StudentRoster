#ifndef DEGREE_H_
#define DEGREE_H_

enum DegreeProgram{SECURITY, NETWORK, SOFTWARE};//Valid Degree Programs

//String array to assist in label creation
static const std::string degreeProgramStrings[] = {"SECURITY","NETWORK","SOFTWARE"};
//To refer to strings, just used intended label as the index, i.e. degreeProgramStrings[NETWORK]

#endif