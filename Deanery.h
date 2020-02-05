#include <vector>
#include <string>
#include <queue>
#include "Student.h"
#include "Group.h"

#ifndef DEANERY_H
#define DEANERY_H

class Deanery 
{
	std::queue<int> freeID; // список свободных ID
	int biggestID = 0; // самый большой занятый ID
    std::vector<Group*> groups; // массив групп
public:
    Deanery(); // конструктор
	~Deanery(); // деструктор
	void liberateID(int id); // освободить id
	int getNewID(); // конструктор новых ID
    void AddStudentsFromFile(const char* filename); // создание студентов на основе данных из файла
	Group* AddGroup(std::string); // Добавить группу
    void AddGroupsFromFile(const char* filename); // создание групп на основе данных из файла
    void AddRandomMarks(int amount = 5); // добавление случайных оценок студентам
    void GetStatistics(const char* filename = "console"); // получение статистики по успеваемости студентов и групп
    void StudentsTransfer(Student* student, Group* source, Group* target); // перевод студентов из группы в группу
	void KickStudents(double level); // отчисление студентов за неуспеваемость ???
    //сохранение обновленных данных в файлах (осуществляется через GetStatistics)
	void StartHeadmenElections(); // инициация выборов старост в группах ???
    // вывод данных на консоль (осуществляется через GetStatistics)
};

#endif
