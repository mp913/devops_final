//#include "pch.h"
#include "gtest/gtest.h"
#include <string>
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

//TEST(DeaneryTest, checkingStudentsReading) {
//	Deanery* deanery = new Deanery();
//	deanery->AddStudentsFromFile("inputS.txt");
//	std::string s = deanery->GetStatistics();
//	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\n", s);
//}


//TEST(DeaneryTest, checkingGroupReading) {
//	Deanery* deanery = new Deanery();
//	deanery->AddGroupsFromFile("inputG.txt");
//	std::string s = deanery->GetStatistics();
//	EXPECT_EQ("101:\n\n103:\n\n104:\n\n", s);
//}

TEST(DeaneryTest, checkingAddingMarks) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 1 2 5 2 5 \nBalaban Vsevolod: 5 3 1 5 2 \nBozhkov Emmanuil: 2 5 3 5 2 \nKusakov Zotik: 4 3 4 4 5 \n\nC:\nLubyanovskiy Timur: 1 2 5 2 5 \nMartynov Anaklet: 5 3 1 5 2 \n\nA:\nAlmazov Evfrasiy: 1 2 5 2 5 \nMitropolskiy Gleb: 5 3 1 5 2 \nBerdyaev Yulian: 2 5 3 5 2 \n\nG:\nHanykov Ustin: 1 2 5 2 5 \n\n", s);
}

TEST(DeaneryTest, checkingAddingStudentToGroup) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	Student* student = new Student("Maxim Zarkov", deanery);
	Group* group1 = deanery->AddGroup("G_unit");
	Group* group2 = deanery->AddGroup("bad_company");
	group1->AddStudent(student);
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\nG_unit:\nMaxim Zarkov: \n\nbad_company:\n\n", s);
}

TEST(DeaneryTest, checkingStudentsTransfer) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	Student* student = new Student("Maxim Zarkov", deanery);
	Group* group1 = deanery->AddGroup("G_unit");
	Group* group2 = deanery->AddGroup("bad_company");
	group1->AddStudent(student);
	deanery->StudentsTransfer(student, group1, group2);
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\nG_unit:\n\nbad_company:\nMaxim Zarkov: \n\n", s);
}

TEST(DeaneryTest, checkingStudentsDeleting) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks(15);
	deanery->KickStudents();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nBalaban Vsevolod: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \nKusakov Zotik: 2 5 5 3 4 4 2 4 4 3 3 3 5 1 2 \n\nC:\nLubyanovskiy Timur: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nMartynov Anaklet: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \n\nA:\nAlmazov Evfrasiy: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nMitropolskiy Gleb: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \n\nG:\nHanykov Ustin: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \n\n", s);
}

TEST(DeaneryTest, checkingHeadmenElections) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks(15);
	deanery->StartHeadmenElections();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nBalaban Vsevolod: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \nBozhkov Emmanuil: 2 1 1 4 3 3 5 5 5 1 3 2 1 5 1 \nKusakov Zotik: 2 5 5 3 4 4 2 4 4 3 3 3 5 1 2 \n\nC:\nLubyanovskiy Timur: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nMartynov Anaklet: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \n\nA:\nAlmazov Evfrasiy: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \nMitropolskiy Gleb: 4 3 4 4 5 3 4 5 2 4 5 1 2 4 5 \nBerdyaev Yulian: 2 1 1 4 3 3 5 5 5 1 3 2 1 5 1 \n\nG:\nHanykov Ustin: 1 2 5 2 5 5 3 1 5 2 2 5 3 5 2 \n\n", s);
}