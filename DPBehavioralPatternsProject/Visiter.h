#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person;
class Company;

class IVisiter
{
public:
	virtual void VisitPerson(Person* accaunt) = 0;
	virtual void VisitCompany(Company* accaunt) = 0;
};

class IAccount
{
public:
	virtual void Accept(IVisiter* visiter) = 0;
};

class Person : public IAccount
{
public:
	string name;
	string accauntNumber;
	int amount;
	//
	void Accept(IVisiter* visiter) override
	{
		visiter->VisitPerson(this);
	}
};

class Company : public IAccount
{
public:
	string title;
	string accauntNumber;
	string license;
	int amount;

	//
	void Accept(IVisiter* visiter) override
	{
		visiter->VisitCompany(this);
	}
};

class XmlVisiter : public IVisiter
{
public:
	void VisitPerson(Person* account) override
	{
		string result = "<person>";
		result += "<name>" + account->name + "</name>";
		result += "<number>" + account->accauntNumber + "</number>";
		result += "<amount>" + to_string(account->amount) + "</amount>";
		result += "</person>";

		cout << result << "\n";
	}

	void VisitCompany(Company* account) override
	{
		string result = "<company>";
		result += "<title>" + account->title + "</title>";
		result += "<number>" + account->accauntNumber + "</number>";
		result += "<amount>" + to_string(account->amount) + "</amount>";
		result += "</company>";

		cout << result << "\n";
	}
};

class JsonVisiter : public IVisiter
{
public:
	void VisitPerson(Person* account) override
	{
		string result = "{";
		result += "name: " + account->name + ",";
		result += "number: " + account->accauntNumber + ",";
		result += "amount: " + to_string(account->amount) + ",";
		result += "}";

		cout << result << "\n";
	}

	void VisitCompany(Company* account) override
	{
		string result = "{";
		result += "title: " + account->title + ",";
		result += "number: " + account->accauntNumber + ",";
		result += "amount: " + to_string(account->amount) + ",";
		result += "}";

		cout << result << "\n";
	}
};
