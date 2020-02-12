#include <vector>
#include <string>
//#include "Group.h"
//#include "Deanary.h"

class Group;
class Deanery;

#ifndef STUDENT_H
#define STUDENT_H

class Student 
{
    int id; 
    std::string fio; 
    Group *group; 
    std::vector<int> marks; 
public:
	Student(std::string fio, Deanery* deanery);
	int getID(); 
	std::string getFio();
    void AddToAgroup(Group* target);
    void AddMark(int mark); 
    double GetAverageMark();
	std::string getMarks();
};

#endif