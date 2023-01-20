#pragma once

#include <iostream>

class Chair
{
public:
	virtual void whatIsThis() = 0;
};

class VictorianChair : public Chair
{
public:
	void whatIsThis() 
	{
		std::cout << "Victorian Chair\n";
	};
};

class ModernChair : public Chair
{
public:
	void whatIsThis() 
	{
		std::cout << "Modern Chair\n";
	};
};