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
    int id; // идентификационный номер
    std::string fio; // фамилия и инициалы
    Group *group; // ссылка на группу (объект Group)
    std::vector<int> marks; // вектор оценок 
public:
	Student(std::string fio, Deanery* deanery); // создание студента с указанием ИД и ФИО
	int getID(); // получить ID студента
	std::string getFio(); // получить ФИО студента
    void AddToAgroup(Group* target); // зачисление в группу
    void AddMark(int mark); // добавление оценок
    double GetAverageMark(); // вычисление средней оценки
	std::string getMarks(); // получение списка оценок
};

#endif