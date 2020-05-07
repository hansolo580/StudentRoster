using namespace std;

class Student {
public:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    string degreeProgram;
    int days[3];

    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int getDays();
    string setStudentID(string newID);
    string setFirstName(string newFirst);
    string setLastName(string newLast);
    string setEmail(string newEmail);
    int setAge(int newAge);
    int setDays(int position, int newDay);

    Student(string setStudentID, string setFirstName, string setLastName, string setEmail, int setAge, int day1, int day2, int day3, string setDegreeProgram);

    void print(Student);
};