#pragma once
#include <iostream>
#include <map>

using namespace std;
/*
IExperisson ::= NumberExpression | Constant | AddExpression | SubstraxtExpression
AddExpression ::= IExpression + IExpressian
SubstraxtExpression ::= IExpression - IExpressian
NumberExpression ::= [A-Z,a-z]+
Constant ::= [0-9]+
*/

class Context
{
	map<string, int> vars;
public:
	int GetVar(string key)
	{
		return vars[key];
	}
	void SetVar(string key, int value)
	{
		if (vars.contains(key))
			vars[key] = value;
		else
			vars.insert({ key, value });
	}
};

class IExpression
{
public:
	virtual int Interpret(Context* context) = 0;
};

class NumberExpression : public IExpression
{
	string name;
public:
	NumberExpression(string name) : name{ name } {}
	int Interpret(Context* context) override
	{
		return context->GetVar(name);
	}
};

class AddExpression : public IExpression
{
	IExpression* exprLeft;
	IExpression* exprRight;
public:
	AddExpression(IExpression* exprLeft, IExpression* exprRight) 
		: exprLeft{ exprLeft }, exprRight{ exprRight } {}
	int Interpret(Context* context) override
	{
		return exprLeft->Interpret(context) + exprRight->Interpret(context);
	}
};
class SubstructExpression : public IExpression
{
	IExpression* exprLeft;
	IExpression* exprRight;
public:
	SubstructExpression(IExpression* exprLeft, IExpression* exprRight)
		: exprLeft{ exprLeft }, exprRight{ exprRight } {}
	int Interpret(Context* context) override
	{
		return exprLeft->Interpret(context) - exprRight->Interpret(context);
	}
};
