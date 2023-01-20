#pragma once

#include "Mediator.h"
#include <iostream>

class Component
{
public:
	Component(Mediator* mediator = nullptr) {
		this->mediator = mediator;
	};

	void update(Mediator* mediator) {
		this->mediator = mediator;
	};

	Mediator* mediator;
};

class ComponentA : public Component {
public:
	void operationA() {
		std::cout << "ComponentA does A." << std::endl;
		mediator->notify(this, "A");
	};
};


class ComponentB : public Component {
public:
	void operationB() {
		std::cout << "ComponentB does B." << std::endl;
		mediator->notify(this, "B");
	};
};


class ComponentC : public Component {
public:
	void operationC() {
		std::cout << "ComponentC does C." << std::endl;
		mediator->notify(this, "C");
	};
};


class ComponentD : public Component {
public:
	void operationD() {
		std::cout << "ComponentD does D." << std::endl;
		mediator->notify(this, "D");
	};
};