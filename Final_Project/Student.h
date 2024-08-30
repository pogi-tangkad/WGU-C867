// Date: 2024-08-30
// Author: Kevin Repking

#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include <string>
using namespace std;


class Student : public Degree{
  public:

  private:
    int studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
    enum Degree::degreeProgram ;

};

#endif

