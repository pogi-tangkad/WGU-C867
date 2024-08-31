// Date: 2024-08-30
// Author: Kevin Repking


#include "include/Student.h"

// Constructor
Student::Student(string newStudentID,
            string newFirstName,
            string newLastName,
            string newEmailAddress,
            int newAge,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram newDegreeProgram) {
    
    studentID = newStudentID;
    firstName = newFirstName;
    lastName = newLastName;
    emailAddress = newEmailAddress;
    age = newAge;
    numDays[0] = daysInCourse1;
    numDays[1] = daysInCourse2;
    numDays[2] = daysInCourse3;
    degreeProgram = newDegreeProgram;
}

// Setters
void Student::SetStudentID(int newStudentID) {
    studentID = newStudentID;
}

void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::SetLastName(string newLastName) {
    lastName = newLastName;
}

void Student::SetEmailAddress(string newEmailAddress) {
    emailAddress = newEmailAddress;
}

void Student::SetAge(int newAge) {
    age = newAge;
}

void Student::SetNumDays(int* newNumDays) {
    for (int i = 0; i < 3; i++) {
        numDays[i] = newNumDays[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram newDegreeProgram) {
    degreeProgram = newDegreeProgram;
}

// Getters
string Student::GetStudentID() const{
    return studentID;
}

string Student::GetFirstName() const{
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

const int* Student::GetNumDays() const {
    return numDays;
}

Degree::DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

// Print Student information
void Student::Print() const {
    cout << studentID << "\t"
         << "First Name: " << firstName << "\t"
         << "Last Name: " << lastName << "\t"
         << "Age: " << age << "\t"
         << "daysInCourse: {"
         << numDays[0] << ", "
         << numDays[1] << ", "
         << numDays[2] << "}" << "\t"
         << "Degree Program: ";
         if (degreeProgram == 0) {
            cout << "SECURITY";
         }
         if (degreeProgram == 1) {
            cout << "NETWORK";
         }
         if (degreeProgram == 2) {
            cout << "SOFTWARE";
         }
         cout << endl;
}