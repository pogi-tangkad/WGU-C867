// Date: 2024-08-31
// Author: Kevin Repking

#include "include/Roster.h"
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

  cout << "Course: Scripting & Programming - Applications - C867\n"
       << "Language: C++\n"
       << "WGU Student ID: 012271818\n"
       << "Name: Kevin Repking" << endl << endl;

  Roster classRoster(studentData);


  classRoster.printAll();

  cout << endl;

  return 0;
}