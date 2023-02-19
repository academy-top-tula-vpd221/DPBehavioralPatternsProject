#pragma once
#include <iostream>

using namespace std;

enum ColleagueType
{
	Customer,
	Developer,
	Tester
};

class Colleague;

class Mediator
{
public:
	virtual void Send(string message, Colleague* colleague) = 0;
};

class Colleague 
{
protected:
	Mediator* mediator;
	ColleagueType type;
public:
	Colleague(Mediator* mediator, ColleagueType type)
		: mediator{ mediator }, type{ type } {}
	virtual void Send(string message)
	{
		mediator->Send(message, this);
	}
	ColleagueType Type() { return type; }
	virtual void Notify(string message) = 0;
};

class CustomerColleague : public Colleague
{
public:
	CustomerColleague(Mediator* mediator)
		: Colleague(mediator, ColleagueType::Customer) {}
	void Notify(string message) override
	{
		cout << "Message for customer: " << message << "\n";
	}
};
class DeveloperColleague : public Colleague
{
public:
	DeveloperColleague(Mediator* mediator)
		: Colleague(mediator, ColleagueType::Developer) {}
	void Notify(string message) override
	{
		cout << "Message for developer: " << message << "\n";
	}
};

class TesterColleague : public Colleague
{
public:
	TesterColleague(Mediator* mediator)
		: Colleague(mediator, ColleagueType::Tester) {}
	void Notify(string message) override
	{
		cout << "Message for tester: " << message << "\n";
	}
};

class ManagerMediator : public Mediator
{
	Colleague* customer;
	Colleague* developer;
	Colleague* tester;
public:
	Colleague*& Customer() { return customer; }
	Colleague*& Developer() { return developer; }
	Colleague*& Tester() { return tester; }

	void Send(string message, Colleague* colleague) override
	{
		if (colleague->Type() == ColleagueType::Customer)
		{
			developer->Notify(message);
		}
		if (colleague->Type() == ColleagueType::Developer)
		{
			tester->Notify(message);
		}
		if (colleague->Type() == ColleagueType::Tester)
		{
			customer->Notify(message);
		}
	}
};
