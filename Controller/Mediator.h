#pragma once

#include <string>

class Component;

class Mediator
{
public:
	virtual void notify(Component* sender, std::string event) = 0;
};


