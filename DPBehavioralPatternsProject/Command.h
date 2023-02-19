#pragma once
#include <iostream>
#include <stack>

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
	int soundMax;
public:
	Televison() 
		: powerOn{ false }, soundVolume{ 0 }, soundMax{ 3 } {}

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
	int SoundMax() { return soundMax; }

	void SoundAdd()
	{
		if(soundVolume < 10)
			cout << "TV sound add, volume = " << ++soundVolume << "\n";
	}

	void SoundDel()
	{
		if(soundVolume > 0)
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

class TvSoundUpCommand : public ICommand
{
	Televison* television;
public:
	TvSoundUpCommand(Televison* television) 
		: television{ television } {}
	void Execute() override
	{
		television->SoundAdd();
	}
	void Undo() override
	{
		television->SoundDel();
	}
	bool CanExecute() override
	{
		return television->IsPower() && (television->SoundVolume() < television->SoundMax());
	}
};

class TvSoundDownCommand : public ICommand
{
	Televison* television;
public:
	TvSoundDownCommand(Televison* television)
		: television{ television } {}
	void Execute() override
	{
		television->SoundDel();
	}
	void Undo() override
	{
		television->SoundAdd();
	}
	bool CanExecute() override
	{
		return television->IsPower() && (television->SoundVolume() > 0);
	}
};

class Controller
{
	ICommand* power;
	ICommand* soundUp;
	ICommand* soundDown;
	bool powerAction;
	std::stack<ICommand*> history;
public:
	Controller(ICommand* power, ICommand* soundUp, ICommand* soundDown)
		: power{ power }, soundUp{ soundUp }, soundDown{ soundDown } 
	{
		powerAction = false;
	}

	void ButtomPower()
	{
		if (!powerAction)
			power->Execute();
		else
			power->Undo();
		powerAction = !powerAction;
	}

	void ButtonVolumePlus()
	{
		if (soundUp->CanExecute())
		{
			soundUp->Execute();
			history.push(soundUp);
		}
	}

	void ButtonVolumeMinus()
	{
		if (soundDown->CanExecute())
		{
			soundDown->Execute();
			history.push(soundDown);
		}
	}

	void ButtonUndo()
	{
		if (history.size() > 0)
		{
			history.top()->Undo();
			history.pop();
		}
	}

};