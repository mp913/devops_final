#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

Deanery::Deanery()
{
	this->freeID = std::queue<int>();
	this->biggestID = 0;
	this->groups = std::vector<Group*>();
}

Deanery::~Deanery()
{
	for (int i = 0; i < groups.size(); i++)
	{
		delete groups[i];
	}
}

void Deanery::liberateID(int id)
{
	this->freeID.push(id);
}

int Deanery::getNewID()
{
	if (!freeID.empty())
	{
		int ans = freeID.front();
		freeID.pop();
		return ans;
	}
	biggestID++;
	return biggestID;
}

void Deanery::AddStudentsFromFile(const char* filename)
{
	FILE* fp;
	//std::ifstream input(filename);
	fp = freopen(filename, "r", stdin);
	std::string s;
	while (std::getline(std::cin, s))
	{
		std::string fio, groupName;
		fio = groupName = "";
		int i = 0;
		for (; s[i] != ':'; i++)
		{
			fio += s[i];
		}
		i++;
		for (; i < s.size(); i++)
		{
			groupName += s[i];
		}

		Student* target = new Student(fio, this);

		bool flag = false;
		for (int i = 0; i < groups.size(); i++)
		{
			if (groups[i]->getTitle() == groupName)
			{
				target->AddToAgroup(groups[i]);
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			Group* gr = AddGroup(groupName);
			target->AddToAgroup(gr);
		}
	}
	//input.close();
	fclose(fp);
}

Group* Deanery::AddGroup(std::string title)
{
	Group* gr = new Group(title, this);
	groups.push_back(gr);
	return gr;
}

void Deanery::AddGroupsFromFile(const char* filename)
{
	FILE* fp;
	fp = freopen(filename, "r", stdin);
	//std::ifstream input(filename);
	std::string s;
	while (std::getline(std::cin, s))
	{
		Group* gr = AddGroup(s);
	}
	//input.close();
	fclose(fp);
}

void Deanery::AddRandomMarks(int amount)
{
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->AddRandomMarks(amount);
	}
}

std::string Deanery::GetStatistics()
{
	std::string ans = "";
	for (int i = 0; i < groups.size(); i++)
	{
		ans += groups[i]->getTitle() + ":\n" + groups[i]->GetStatistics() + '\n';
	}
	return ans;
}

void Deanery::StudentsTransfer(Student* student, Group* source, Group* target)
{
	source->softTermination(student);
	target->AddStudent(student);
}

void Deanery::KickStudents(double level)
{
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->KickStudents(level);
	}
}

void Deanery::StartHeadmenElections()
{
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->HeadmanElection();
	}
}

void Deanery::printConsole()
{
	std::cout << this->GetStatistics() << '\n';
}

void Deanery::saveFile(const char* filename)
{
	FILE* fp;
	fp = freopen(filename, "w", stdout);
	std::cout << this->GetStatistics() << '\n';
	fclose(fp);
}