#pragma once

#include <iostream>

class Sofa
{
public:
	virtual void whatIsThis() = 0;
};

class VictorianSofa : public Sofa
{
public:
	void whatIsThis()
	{
		std::cout << "Victorian Sofa\n";
	};
};

class ModernSofa : public Sofa
{
public:
	void whatIsThis()
	{
		std::cout << "Modern Sofa\n";
	};
};
