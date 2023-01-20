#include <iostream>
#include "Component.h"
#include "ConcreteMediator.h"

int main()
{
	ComponentA* componentA = new ComponentA();
	ComponentB* componentB = new ComponentB();
	ComponentC* componentC = new ComponentC();
	ComponentD* componentD = new ComponentD();
	ConcreteMediator* mediator = new ConcreteMediator(componentA, componentB,
													  componentC, componentD);

	std::cout << "Client triggers operation A.\n";
	componentA->operationA();

	std::cout << "\nClient triggers operation B.\n";
	componentB->operationB();

	std::cout << "\nClient triggers operation C.\n";
	componentC->operationC();

	std::cout << "\nClient triggers operation D.\n";
	componentD->operationD();

}
