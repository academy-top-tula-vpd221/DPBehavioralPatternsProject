#pragma once
#include <iostream>

using namespace std;

class Water;

class IWaterState
{
public:
	virtual void Heat(Water* water) = 0;
	virtual void Frost(Water* water) = 0;
};

class Water
{
	IWaterState* state;
public:
	Water(IWaterState* state) : state{ state } {}
	IWaterState*& State() {	return state; }

	void Heating()
	{
		state->Heat(this);
	}

	void Frosting()
	{
		state->Frost(this);
	}
};

class GasWaterState;
class SolidWaterState;
class LiquidWaterState;

class GasWaterState : public IWaterState
{
public:
	void Heat(Water* water) override;
	void Frost(Water* water) override;
};

class LiquidWaterState : public IWaterState
{
public:
	void Heat(Water* water) override;
	void Frost(Water* water) override;
};

class SolidWaterState : public IWaterState
{
public:
	void Heat(Water* water) override;
	void Frost(Water* water) override;
};

void GasWaterState::Heat(Water* water)
{
	cout << "gas to hot gas!\n";
}
void GasWaterState::Frost(Water* water)
{
	cout << "gas to liquid!\n";
	water->State() = new LiquidWaterState();
}

void LiquidWaterState::Heat(Water* water)
{
	cout << "liquid to gas!\n";
	water->State() = new GasWaterState();
}

void LiquidWaterState::Frost(Water* water)
{
	cout << "liquid to ice!\n";
	water->State() = new SolidWaterState();
}

void SolidWaterState::Heat(Water* water)
{
	cout << "ice to liquid!\n";
	water->State() = new LiquidWaterState();
}
void SolidWaterState::Frost(Water* water)
{
	cout << "ice to hard ice!\n";
}