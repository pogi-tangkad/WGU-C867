// Date: 2024-08-30
// Author: Kevin Repking

#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include <iostream>
#include <string>
using namespace std;


class Student {
  public:
    // Constructor
    Student() {};
    Student(string newStudentID,
            string newFirstName,
            string newLastName,
            string newEmailAddress,
            int newAge,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram newDegreeProgram);

    // Setters
    void SetStudentID(string newStudentID);
    void SetFirstName(string newFirstName);
    void SetLastName(string newLastName);
    void SetEmailAddress(string newEmailAddress);
    void SetAge(int newAge);
    void SetNumDays(int *newNumDays);
    void SetDegreeProgram(DegreeProgram newDegreeProgram);

    // Getters
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    const int* GetNumDays() const;
    DegreeProgram GetDegreeProgram() const;

    // Printer
    void Print() const;

  private:
    // Variable for Student Data
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    int age = 0;
    int numDays[3] = {0, 0, 0};
    DegreeProgram degreeProgram;
};

#endif