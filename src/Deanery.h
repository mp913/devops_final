#include <vector>
#include <string>
#include <queue>
#include "Student.h"
#include "Group.h"

#ifndef DEANERY_H
#define DEANERY_H

class Deanery 
{
	std::queue<int> freeID; 
	int biggestID = 0; 
    std::vector<Group*> groups; 
public:
    Deanery(); 
	~Deanery();
	void liberateID(int id); 
	int getNewID(); 
    void AddStudentsFromFile(const char* filename); 
	Group* AddGroup(std::string); 
    void AddGroupsFromFile(const char* filename); 
    void AddRandomMarks(int amount = 5);
    std::string GetStatistics();
    void StudentsTransfer(Student* student, Group* source, Group* target);
	void KickStudents(double level = 3); 
	void StartHeadmenElections(); 
	void printConsole();
	void saveFile(const char* filename);
};

#endif
