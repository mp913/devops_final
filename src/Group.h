#include <vector>
#include <string>
#include "Student.h"

#ifndef GROUP_H
#define GROUP_H

class Group 
{
    std::string title;
    std::string spec;
    std::vector<Student*> students; 
	Student* head; 
	Deanery* deanery;
public:
    Group(std::string title, Deanery* deanery);
	~Group(); 
	std::string getTitle();
    void AddStudent(Student* newbee);
	void HeadmanElection(int seed = 13);
    Student* SearchById(int id); 
    Student* SearchByFio(std::string fio);
    double GetAverageMark(); 
    void Termnination(int id);
	void AddRandomMarks(int amount = 5, int seed = 13);
	std::string GetStatistics(); 
	void softTermination(Student* student);
	void KickStudents(double level);
};

#endif