#pragma once

class Builder
{
public:
	virtual void reset() = 0;
	virtual void buildStepA() = 0;
	virtual void buildStepB() = 0;
	virtual void buildStepZ() = 0;
};

class ConcreteBuilder1 : Builder
{
public:
	ConcreteBuilder1 : Builder();
	~ConcreteBuilder1 : Builder();

private:
	
};
