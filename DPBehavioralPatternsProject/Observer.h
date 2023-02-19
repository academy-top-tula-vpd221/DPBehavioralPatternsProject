#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MarketInfo;

class IObserver
{
public:
	virtual void Update(MarketInfo* value) = 0;
};


class IObservable
{
public:
	virtual void AddObserver(IObserver* observer) = 0;
	virtual void RemoveObserver(IObserver* observer) = 0;
	virtual void NotifyObserver() = 0;
};

class MarketInfo
{
	int usd;
	int euro;
public:
	int& Usd() { return usd; }
	int& Euro() { return euro; }
};

class Market : public IObservable
{
	MarketInfo* info;
	vector<IObserver*> observers;
public:
	Market() : info{ new MarketInfo() } {}

	void AddObserver(IObserver* observer) override
	{
		observers.push_back(observer);
	}
	void RemoveObserver(IObserver* observer) override
	{
		auto it = find(observers.begin(), observers.end(), observer);
		if (it != observers.end())
			observers.erase(it);
	}
	void NotifyObserver() override
	{
		for (auto item : observers)
			item->Update(info);
	}

	void Bidding()
	{
		srand(time(nullptr));

		info->Usd() = 30 + rand() % 40;
		info->Euro() = 30 + rand() % 50;

		NotifyObserver();
	}
};

class Broker : public IObserver
{
	string name;
	IObservable* market;
public:
	Broker(string name, IObservable* market)
		: name{ name }, market{ market }
	{
		market->AddObserver(this);
	}
	string& Name() { return name; }
	void Update(MarketInfo* info) override
	{
		if (info->Usd() > 50)
			cout << "Broker " << name << " saled usd at " << info->Usd() << "\n";
		else
			cout << "Broker " << name << " byed usd at " << info->Usd() << "\n";
	}
	void StopMarket()
	{
		market->RemoveObserver(this);
	}
};

class Bank : public IObserver
{
	string name;
	IObservable* market;
public:
	Bank(string name, IObservable* market)
		: name{ name }, market{ market }
	{
		market->AddObserver(this);
	}
	string& Name() { return name; }
	void Update(MarketInfo* info) override
	{
		if (info->Euro() > 50)
			cout << "Bank " << name << " saled euro at " << info->Euro() << "\n";
		else
			cout << "Bank " << name << " byed euro at " << info->Euro() << "\n";
	}
	void StopMarket()
	{
		market->RemoveObserver(this);
	}
};