#include <iostream>
#include "AbstractFactory.h"

int main()
{
    FurnitureFactory* factory = new VictorianFurnitureFactory();

    Chair* chair = factory->createChair();
    chair->whatIsThis();

    Sofa* sofa = factory->createSofa();
    sofa->whatIsThis();

    CoffeeTable* coffeeTable = factory->createCoffeeTable();
    coffeeTable->whatIsThis();

    delete factory, chair, sofa, coffeeTable;

	factory = new ModernFurnitureFactory();

	chair = factory->createChair();
	chair->whatIsThis();

	sofa = factory->createSofa();
	sofa->whatIsThis();

	coffeeTable = factory->createCoffeeTable();
	coffeeTable->whatIsThis();

	delete factory, chair, sofa, coffeeTable;
}