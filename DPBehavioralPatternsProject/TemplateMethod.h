#pragma once
#include <iostream>

using namespace std;

class Education
{
public:
	virtual void Learn() final
	{
		Enter();
		Study();
		PassExam();
		GetDocument();
	}
	virtual void Enter() = 0;
	virtual void Study() = 0;
	virtual void PassExam()
	{
		cout << "Pass Exam\n";
	}
	virtual void GetDocument() = 0;
};

class School : public Education
{
public:
	void Enter() override
	{
		cout << "enter at first class\n";
	}
	void Study() override
	{
		cout << "go to school. make homeworks.\n";
	}
	void GetDocument() override
	{
		cout << "get attestat\n";
	}
};

class Universitet : public Education
{
public:
	void Enter() override
	{
		cout << "input exam\n";
		cout << "eneter at first course\n";
	}
	void Study() override
	{
		cout << "go to universitet\n";
		cout << "parctic\n";
	}
	void PassExam() override
	{
		cout << "Pass Special Exam\n";
	}
	void GetDocument() override
	{
		cout << "get diplom\n";
	}
};
