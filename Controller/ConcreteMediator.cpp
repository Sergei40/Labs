#include "ConcreteMediator.h"
#include "Component.h"

ConcreteMediator::ConcreteMediator(ComponentA* comA, ComponentB* comB, ComponentC* comC, ComponentD* comD)
{
	componentA = comA;
	componentB = comB;
	componentC = comC;
	componentD = comD;
	componentA->update(this);
	componentB->update(this);
	componentC->update(this);
	componentD->update(this);
};

void ConcreteMediator::notify(Component* sender, std::string event)
{
	if (event == "A") {
		std::cout << "Mediator reacts on A\n";
	}										 
	else if (event == "B") {				 
		std::cout << "Mediator reacts on B\n";
	}										 
	else if (event == "C") {				 
		std::cout << "Mediator reacts on C\n";
	}										 
	else if (event == "D") {				 
		std::cout << "Mediator reacts on D\n";
	}
}