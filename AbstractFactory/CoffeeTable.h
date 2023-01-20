#pragma once

#include <iostream>

class CoffeeTable
{
public:
	virtual void whatIsThis() = 0;
};

class VictorianCoffeeTable : public CoffeeTable
{
public:
	void whatIsThis()
	{
		std::cout << "Victorian Coffee Table\n";
	};
};

class ModernCoffeeTable : public CoffeeTable
{
public:
	void whatIsThis()
	{
		std::cout << "Modern Coffee Table\n";
	};
};