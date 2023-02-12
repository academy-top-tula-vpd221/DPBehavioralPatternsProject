#pragma once
#include <iostream>
using namespace std;

class Receiver 
{
public:
	bool BankTransefer;
	bool PayPalTransefer;
	bool MoneyTransefer;
	
	Receiver(bool bankTransefer, bool payPalTransefer, bool moneyTransefer)
		: BankTransefer{ bankTransefer },
		PayPalTransefer{ payPalTransefer },
		MoneyTransefer{ moneyTransefer } {}
};

class PaymentHadler
{
protected:
	PaymentHadler* nextSuccessor;
public:
	PaymentHadler(PaymentHadler* nextSuccessor = nullptr) 
		: nextSuccessor{ nextSuccessor } {}

	virtual PaymentHadler*& NextSuccessor() { return nextSuccessor; }
	virtual void Handle(Receiver* receiver) = 0;
};

class BankPankmentHandler : public PaymentHadler
{
public:
	BankPankmentHandler(PaymentHadler* nextSuccessor = nullptr)
		: PaymentHadler(nextSuccessor) {};

	void Handle(Receiver* receiver) override
	{
		if (receiver->BankTransefer)
			cout << "Bank tranfer is ok\n";
		else
			if(nextSuccessor != nullptr)
				nextSuccessor->Handle(receiver);
	}
};

class PayPalPankmentHandler : public PaymentHadler
{
public:
	PayPalPankmentHandler(PaymentHadler* nextSuccessor = nullptr)
		: PaymentHadler(nextSuccessor) {};

	void Handle(Receiver* receiver) override
	{
		if (receiver->PayPalTransefer)
			cout << "Pay Pal tranfer is ok\n";
		else
			if (nextSuccessor != nullptr)
				nextSuccessor->Handle(receiver);
	}
};

class MoneyPankmentHandler : public PaymentHadler
{
public:
	MoneyPankmentHandler(PaymentHadler* nextSuccessor = nullptr)
		: PaymentHadler(nextSuccessor) {};

	void Handle(Receiver* receiver) override
	{
		if (receiver->MoneyTransefer)
			cout << "Money tranfer is ok\n";
		else
			if (nextSuccessor != nullptr)
				nextSuccessor->Handle(receiver);
	}
};

