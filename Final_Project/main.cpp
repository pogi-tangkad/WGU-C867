// Date: 2024-08-31
// Author: Kevin Repking

#include "Student.cpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;



int main() {

  const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Kevin,Repking,krepki1@wgu.edu,44,15,25,35,SOFTWARE" 
  };

  string studendID;
  string firstName;
  string lastName;
  string emailAddress;
  string age;
  string numDays[3];
  string degree;

  Student students[5];



  cout << "Course: Scripting & Programming - Applications - C867\n"
       << "Language: C++\n"
       << "WGU Student ID: 012271818\n"
       << "Name: Kevin Repking" << endl;

  for (int i = 0; i < 5; i++) {
    istringstream iss(studentData[i]);

    getline(iss, studendID, ',');
    getline(iss, firstName, ',');
    getline(iss, lastName, ',');
    getline(iss, emailAddress, ',');
    getline(iss, age, ',');
    getline(iss, numDays[0], ',');
    getline(iss, numDays[1], ',');
    getline(iss, numDays[2], ',');
    getline(iss, degree, ',');


    
    Degree::DegreeProgram newDegree;

    if (degree == "SECURITY") {
      newDegree = Degree::SECURITY;
    }
    else if (degree == "NETWORK") {
      newDegree = Degree::NETWORK;
    }
    else {
      newDegree = Degree::SOFTWARE;
    }
    
    int newAge = stoi(age);
        
    int newNumDays0 = stoi(numDays[0]);
    
    int newNumDays1 = stoi(numDays[1]);
    
    int newNumDays2 = stoi(numDays[2]);

    students[i] = Student(studendID,
                          firstName,
                          lastName,
                          emailAddress,
                          newAge,
                          newNumDays0,
                          newNumDays1,
                          newNumDays2,
                          newDegree);

  }

  string tester = "A3";
  for (int j = 0; j < 5; j++) {
    students[j].Print();


    if (tester == students[j].GetStudentID()) {
      cout << "FOUND JACK!" << endl;
    }

  }
  cout << endl;
  return 0;
}