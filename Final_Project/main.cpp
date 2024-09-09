// Date: 2024-08-31
// Author: Kevin Repking

#include "include/Roster.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;



int main() {

  // Array of comma separated strings of student data
  const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Kevin,Repking,krepki1@wgu.edu,44,15,25,35,SOFTWARE" 
  };

  // Print WGU course and student info to stdout
  cout << "Course: Scripting & Programming - Applications - C867\n"
       << "Language: C++\n"
       << "WGU Student ID: 012271818\n"
       << "Name: Kevin Repking" << endl << endl;

  // Initialize the Roster object
  Roster classRoster(studentData);

  // Call Roster function to print the student information
  // in tabulated format to stdout
  classRoster.printAll();

  // Call Roster function to identify incorrect
  // email addresses from studentData and print to stdout
  cout << "Invalid Emails:" << endl;
  classRoster.printInvalidEmails();
  cout << endl;

  // Call Roster function to calculate the average of days
  // from each student and print to stdout
  cout << "Average days in Course:" << endl;
  for (int i = 0; i < classRoster.rosterSize; i++) {
    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].GetStudentID());
  }
  cout << endl;


  // Call Roster function to identify each student in
  // Software and print to stdout
  cout << "Students in Software" << endl;
  classRoster.printByDegreeProgram(SOFTWARE);
  cout << endl;

  // Call Roster function to remove student by ID and
  // print remaining students to stdout
  cout << "Remove student with ID \"A3\"" << endl;
  classRoster.remove("A3");
  classRoster.printAll();

  // Call Roster function to remove same student and
  // get expected error
  cout << "Remove student with ID \"A3\"" << endl;
  classRoster.remove("A3");



  cout << endl;

  return 0;
}