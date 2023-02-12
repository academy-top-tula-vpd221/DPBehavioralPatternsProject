#pragma once
#include <iostream>
using namespace std;

// inteface Command
class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual bool CanExecute() = 0;
};

// Receiver
class Televison
{
	bool powerOn;
	int soundVolume;
public:
	Televison() : powerOn{ false }, soundVolume{ 0 } {}

	bool IsPower() { return powerOn; }

	void PowerOn()
	{
		cout << "TV power On\n";
		powerOn = true;
	}
	void PowerOff()
	{
		cout << "TV power Off\n";
		powerOn = false;
	}

	int SoundVolume() { return soundVolume; }

	void SoundAdd()
	{
		cout << "TV sound add, volume = " << ++soundVolume << "\n";
	}

	void SoundDel()
	{
		cout << "TV sound del, volume = " << --soundVolume << "\n";
	}
};

// ConcreteCommand
class TvOnCommand : public ICommand
{
	Televison* television;
public:
	TvOnCommand(Televison* television) : television{ television } {}

	void Execute() override
	{
		television->PowerOn();
	}
	void Undo() override
	{
		television->PowerOff();
	}

	virtual bool CanExecute()
	{
		return true;
	}
};