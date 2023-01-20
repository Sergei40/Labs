#include <iostream>
#include <string>

class Product1
{
public:
	void doStep(std::string step)
	{
		std::cout << "product 1: step " + step << std::endl;
	};
private:
	std::string product = "";
};


class Product2
{
public:
	void doStep(std::string step)
	{
		std::cout << "product 1: step " + step << std::endl;
	};
private:
	std::string product = "";
};


class Builder
{
public:
	virtual void reset() = 0;
	virtual void buildStepA() = 0;
	virtual void buildStepB() = 0;
	virtual void buildStepZ() = 0;
};


class ConcreteBuilder1 : public Builder
{
public:
	void reset() { result = new Product1(); }
	void buildStepA() { result->doStep("A"); }
	void buildStepB() { result->doStep("B"); }
	void buildStepZ() { result->doStep("Z"); }
	Product1* getResult() { return result; }
private:
	Product1* result;
};


class ConcreteBuilder2 : public Builder
{
public:
	void reset() { result = new Product2(); }
	void buildStepA() { result->doStep("A"); }
	void buildStepB() { result->doStep("B"); }
	void buildStepZ() { result->doStep("Z"); }
	Product2* getResult() { return result; }
private:
	Product2* result;
};


class Director
{
public:
	Director(Builder* b) : builder(b) {};
	void changeBuilder(Builder* b)
	{
		delete builder;
		builder = b;
	};
	void make(std::string type)
	{
		if (type == "simple")
		{
			builder->buildStepA();
		}
		else {
			builder->buildStepB();
			builder->buildStepZ();
		}
	};
private:
	Builder* builder;
};


int main()
{
	std::cout << "build simple product1:\n";
	ConcreteBuilder1* builder = new ConcreteBuilder1();
	Director* director =  new Director(builder);
	director->make("simple");
	Product1* product1 = builder->getResult();
	delete builder, director, product1;

	std::cout << "\nbuild hard product2:\n";
	ConcreteBuilder2* b = new ConcreteBuilder2();
	Director* d = new Director(b);
	d->make("hard");
	Product2* product2 = b->getResult();
	delete b, d, product2;
	return 0;
}