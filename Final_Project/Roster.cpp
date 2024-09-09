// Date: 2024-09-01
// Author: Kevin Repking

#include "include/Roster.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Constructor
Roster::Roster(const string studentArr[5]) {

  // Initialize variable to be parsed from each
  // comma separated string
  string studendID;
  string firstName;
  string lastName;
  string emailAddress;
  string age;
  string numDays[3];
  string degree;

  // Iterate over the 5 strings passed by the array
  // and parse out the commas to assign the variables
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

    // Convert the age and days in course to integers
    // for the Student object created    
    int newAge = stoi(age);
    int newNumDays0 = stoi(numDays[0]);    
    int newNumDays1 = stoi(numDays[1]);    
    int newNumDays2 = stoi(numDays[2]);
    
    // Create a DegreeProgram enum variable and check
    // against the degree string
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

    // Call the Roster::add function with the new variables
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

  // Take student data, create Student, and assign to array
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

  // For each student in array, call its Print function
  void Roster::printAll() {
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetStudentID() != "") {
        classRosterArray[i].Print();
      }
    }
    cout << endl;
  }

  // Check the required parameters for a valid email against
  // each student and print the invalid emails to stdout
  void Roster::printInvalidEmails() {
    string email;

    for (int i = 0; i < rosterSize; i++) {
      // start by setting false flags
      bool atSymbol = false;
      bool singlePeriod = false;
      bool badEmail = false;
      
      // get email for student
      email = classRosterArray[i].GetEmailAddress();

      for (int j = 0; j < email.length(); j++) {
        // check for only one(1) @ symbol
        if (email[j] == '@' && !atSymbol) {
          atSymbol = true;
        }
        else if (email[j] == '@' && atSymbol) {
          badEmail = true;
          break;
        }
        // check for only one(1) period AFTER the @ symbol
        if (email[j] == '.' && atSymbol && !singlePeriod) {
          singlePeriod = true;
        }
        else if (email[j] == '.' && atSymbol && singlePeriod) {
          badEmail = true;
          break;
        }
        // check for spaces
        if (email[j] == ' ') {
          badEmail = true;
          break;
        }
      }

      // if email flagged as bad or missing @ or .
      // print email address to stdout
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
        // standard find average loop
        for (int j = 0; j < 3; j++) {
          averageDays += student.GetNumDays()[j];
        }
        cout << student.GetFirstName() << " "
             << student.GetLastName() << ": "
             << averageDays / 3 << endl;
      }
    }
  }

  // Search each student for matching degree program
  void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i].GetDegreeProgram() == degreeProgram) {
        classRosterArray[i].Print();
      }
    }
  }

  void Roster::remove(string studentID) {
    // bool to check if student was found
    bool swap = false;

    // iterate over students. if found, remove student
    // at index and shift remaining students left
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
    // no student found
    if (!swap) {
      cout << "Student with ID " << studentID << " not found" << endl;
    }
  }
