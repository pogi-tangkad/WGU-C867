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
    classRosterArray[rosterSize] = Student(studentID,
                                             firstName,
                                             lastName,
                                             emailAddress,
                                             age,
                                             daysInCourse1,
                                             daysInCourse2,
                                             daysInCourse3,
                                             degreeProgram);
    rosterSize++;    
  }

  void Roster::printAll() {
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetStudentID() != "") {
        classRosterArray[i].Print();
      }
    }
    cout << endl;
  }

  void Roster::printInvalidEmails() {
    string email;
    for (int i = 0; i < rosterSize; i++) {
      bool atSymbol = false;
      bool singlePeriod = false;
      bool badEmail = false;
      email = classRosterArray[i].GetEmailAddress();
      for (int j = 0; j < email.length(); j++) {
        if (email[j] == '@' && !atSymbol) {
          atSymbol = true;
        }
        else if (email[j] == '@' && atSymbol) {
          badEmail = true;
          break;
        }
        if (email[j] == '.' && atSymbol && !singlePeriod) {
          singlePeriod = true;
        }
        else if (email[j] == '.' && atSymbol && singlePeriod) {
          badEmail = true;
          break;
        }
        if (email[j] == ' ') {
          badEmail = true;
          break;
        }
      }
      if (badEmail || !atSymbol || !singlePeriod) {
        cout << email << endl;
      }
    }
  }

  void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetStudentID() == studentID) {
        Student student = classRosterArray[i];
        int averageDays = 0;
        for (int j = 0; j < 3; j++) {
          averageDays += student.GetNumDays()[j];
        }
        cout << student.GetFirstName() << " "
             << student.GetLastName() << ": "
             << averageDays / 3 << endl;
      }
    }
  }

  void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetDegreeProgram() == degreeProgram) {
        classRosterArray[i].Print();
      }
    }
  }

  void Roster::remove(string studentID) {
    bool swap = false;
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetStudentID() == studentID) {
        swap = true;
      }
      if (swap && i < (rosterSize - 1)) {
        classRosterArray[i] = classRosterArray[i + 1];
      }
      if (swap && i == (rosterSize - 1)) {
        classRosterArray[i] = Student();
      }
    }
    if (!swap) {
      cout << "Student with ID " << studentID << " not found" << endl;
    }
  }
