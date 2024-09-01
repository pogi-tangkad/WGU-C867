// Date: 2024-09-01
// Author: Kevin Repking

#include "include/Roster.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Constructor
Roster::Roster(const string studentArr[5]) {

  string studendID;
  string firstName;
  string lastName;
  string emailAddress;
  string age;
  string numDays[3];
  string degree;

  for (int i = 0; i < 5; i++) {
    istringstream iss(studentArr[i]);

    getline(iss, studendID, ',');
    getline(iss, firstName, ',');
    getline(iss, lastName, ',');
    getline(iss, emailAddress, ',');
    getline(iss, age, ',');
    getline(iss, numDays[0], ',');
    getline(iss, numDays[1], ',');
    getline(iss, numDays[2], ',');
    getline(iss, degree, ',');

    
    int newAge = stoi(age);
        
    int newNumDays0 = stoi(numDays[0]);
    
    int newNumDays1 = stoi(numDays[1]);
    
    int newNumDays2 = stoi(numDays[2]);
    
    DegreeProgram newDegree;

    if (degree == "SECURITY") {
      newDegree = SECURITY;
    }
    else if (degree == "NETWORK") {
      newDegree = NETWORK;
    }
    else {
      newDegree = SOFTWARE;
    }
    this->add(studendID,
              firstName,
              lastName,
              emailAddress,
              newAge,
              newNumDays0,
              newNumDays1,
              newNumDays2,
              newDegree);
    }
  }

  Roster::~Roster() {
    delete[] classRosterArray;
  }

  void Roster::add(string studentID,
                   string firstName,
                   string lastName,
                   string emailAddress,
                   int age,
                   int daysInCourse1,
                   int daysInCourse2,
                   int daysInCourse3,
                   DegreeProgram degreeProgram) {
    classRosterArray[this->rosterPosition] = Student(studentID,
                                             firstName,
                                             lastName,
                                             emailAddress,
                                             age,
                                             daysInCourse1,
                                             daysInCourse2,
                                             daysInCourse3,
                                             degreeProgram);
    this->rosterPosition++;    
  }

  void Roster::remove(string studentID) {
    for (int i = 0; i < 5; i++) {
      if (classRosterArray[i].GetStudentID() == studentID) {
        classRosterArray[i].SetStudentID("");
      }
    }
  }

  void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
      if (classRosterArray[i].GetStudentID() != "") {
        classRosterArray[i].Print();
      }
    }
  }