#pragma once

#include "Mediator.h"

class ComponentA;
class ComponentB;
class ComponentC;
class ComponentD;

class ConcreteMediator : Mediator
{
public:
	ConcreteMediator(ComponentA* comA, ComponentB* comB, ComponentC* comC, ComponentD* comD);
	void notify(Component* sender, std::string event);

private:
	ComponentA* componentA;
	ComponentB* componentB;
	ComponentC* componentC;
	ComponentD* componentD;
};
