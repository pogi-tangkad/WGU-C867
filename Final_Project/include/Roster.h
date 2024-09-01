// Date: 2024-09-01
// Author: Kevin Repking

#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"


class Roster {


  public:
  // Constructor
    Roster() {};
    Roster(const string studentArr[5]);

  // Destructor
    ~Roster();

    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);

    void remove(string studentID);

    void printAll();

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

    void printAverageDaysInCourse(string studentID);

    int rosterSize = 0;

    Student* classRosterArray = new Student[5];

  private:

};

#endif
