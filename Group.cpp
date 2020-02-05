#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


Group::Group(std::string title, Deanery* deanery) // создание группы с указанием названия
{
	this->deanery = deanery;
	this->title = title;
	this->spec = "";
	this->students = std::vector<Student*>();
	this->head = nullptr;
}

Group::~Group() // деструктор
{
	for (int i = 0; i < students.size(); i++)
	{
		delete students[i];
	}
}

std::string Group::getTitle() // получить название группы
{
	return this->title;
}

void Group::AddStudent(Student* newbee) // добавление студента
{
	students.push_back(newbee);
}

void Group::HeadmanElection() // избрание старосты
{
	if (students.size() == 0)
	{
		return;
	}
	srand(time(0));
	this->head = students[rand() % students.size()];
}

Student* Group::SearchById(int id) // поиск студента по ИД
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

Student* Group::SearchByFio(std::string fio) // поиск студента по ФИО
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

double Group::GetAverageMark() //вычисление соеднего балла в группе
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

void Group::Termnination(int id) //исключение студента из группы
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

void Group::AddRandomMarks(int amount) // добавление случайных оценок студентам
{
	srand(time(0));
	for (int i = 0; i < students.size(); i++)
	{
		for (int i = 0; i < amount; i++)
		{
			students[i]->AddMark(rand() % 5 + 1);
		}
	}
}

std::string Group::GetStatistics() // получение статистики по успеваемости
{
	std::string statistics = "";
	for (int i = 0; i < students.size(); i++)
	{
		statistics += students[i]->getFio() + ": " + students[i]->getMarks();
	}
	return statistics;
}

void Group::softTermination(Student* student) // удаление без уничтожения экземпляра студента
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

void Group::KickStudents(double level) // отчисление студентов за неуспеваемость
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->GetAverageMark() < level)
		{
			this->Termnination(students[i]->getID());
		}
	}
}