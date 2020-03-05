#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


Group::Group(std::string title, Deanery* deanery)
{
	this->deanery = deanery;
	this->title = title;
	this->spec = "";
	this->students = std::vector<Student*>();
	this->head = nullptr;
}

Group::~Group()
{
	for (int i = 0; i < students.size(); i++)
	{
		delete students[i];
	}
}

std::string Group::getTitle()
{
	return this->title;
}

void Group::AddStudent(Student* newbee) 
{
	students.push_back(newbee);
}

void Group::HeadmanElection(int seed)
{
	if (students.size() == 0)
	{
		return;
	}
	srand(seed);
	this->head = students[rand() % students.size()];
}

Student* Group::SearchById(int id) 
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getID() == id)
		{
			return students[i];
		}
	}
	return nullptr;
}

Student* Group::SearchByFio(std::string fio) 
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getFio() == fio)
		{
			return students[i];
		}
	}
	return nullptr;
}

double Group::GetAverageMark() 
{
	if (students.size() == 0)
	{
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < students.size(); i++)
	{
		sum += students[i]->GetAverageMark();
	}
	return sum /= students.size();
}

void Group::Termnination(int id)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getID() == id)
		{
			Student* target = students[i];
			students.erase(students.begin() + i);
			delete target;
			deanery->liberateID(id);
			return;
		}
	}
}

void Group::AddRandomMarks(int amount, int seed)
{
	srand(seed);
	for (int i = 0; i < students.size(); i++)
	{
		for (int j = 0; j < amount; j++)
		{
			students[i]->AddMark(rand() % 5 + 1);
		}
	}
}

std::string Group::GetStatistics() 
{
	std::string statistics = "";
	for (int i = 0; i < students.size(); i++)
	{
		statistics += students[i]->getFio() + ": " + students[i]->getMarks();
	}
	return statistics;
}

void Group::softTermination(Student* student) 
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i] == student)
		{
			students.erase(students.begin() + i);
			return;
		}
	}
}

void Group::KickStudents(double level) 
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->GetAverageMark() < level)
		{
			this->Termnination(students[i]->getID());
		}
	}
}