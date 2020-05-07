#include <iostream>
#include "roster.cpp"
#include "student.cpp"


int main() {
    Student Luke = Student("15", "Luke", "Willey", "testemail", 27, 10, 5, 6, "SOFTWARE");
    Luke.print(Luke);
    return 0;
}
