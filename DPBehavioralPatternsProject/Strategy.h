#pragma once
#include <iostream>

using namespace std;

class ICompression
{
public:
	virtual void compress(string file) = 0;
	virtual ~ICompression(){}
};

class Archiver
{
	ICompression* compression;
public:
	Archiver(ICompression* compression) : compression{ compression } {}
	ICompression*& Compression() { return compression; }

	void Archiving(string file)
	{
		compression->compress(file);
	}
};

class RarCompression : public ICompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << " compress with RAR algorithm\n";
	}
};
class ZipCompression : public ICompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << " compress with ZIP algorithm\n";
	}
};

class ArjCompression : public ICompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << " compress with ARJ algorithm\n";
	}
};



