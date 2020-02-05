#include "Student.h"
#include "Deanery.h"
#include <string>
#include <vector>

Student::Student(std::string fio, Deanery* deanery)
{
	this->group = nullptr;
	this->marks = std::vector<int>();
	this->fio = fio;
	this->id = (*deanery).getNewID();
}

int Student::getID() // получить ID студента
{
	return this->id;
}

std::string Student::getFio() // получить ФИО студента
{
	return this->fio;
}

void Student::AddToAgroup(Group* target) // зачисление в группу
{
	target->AddStudent(this);
	this->group = target;
}

void Student::AddMark(int mark) // добавление оценок
{
	marks.push_back(mark);
}

double Student::GetAverageMark() //вычисление средней оценки
{
	if (marks.size() == 0)
	{
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
	}
	return sum /= marks.size();
}

std::string Student::getMarks() // получение списка оценок
{
	std::string s = "";
	for (int i = 0; i < marks.size(); i++)
	{
		s += marks[i] + ' ';
	}
	return s;
}