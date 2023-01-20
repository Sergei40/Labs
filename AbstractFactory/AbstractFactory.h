#pragma once

#include "Chair.h"
#include "CoffeeTable.h"
#include "Sofa.h"

class FurnitureFactory
{
public:
	virtual Chair* createChair() = 0;
	virtual CoffeeTable* createCoffeeTable() = 0;
	virtual Sofa* createSofa() = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory
{
public:
	Chair* createChair()
	{
		return new VictorianChair();
	};
	CoffeeTable* createCoffeeTable()
	{
		return new VictorianCoffeeTable();
	};
	Sofa* createSofa()
	{
		return new VictorianSofa();
	};
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
	Chair* createChair()
	{
		return new ModernChair();
	};
	CoffeeTable* createCoffeeTable()
	{
		return new ModernCoffeeTable();
	};
	Sofa* createSofa()
	{
		return new ModernSofa();
	};
};