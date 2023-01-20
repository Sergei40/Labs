#include <iostream>
#include "string"

class ExistingClass
{
public:
	virtual void method(std::string data) {
		std::cout << "do stuff with data: " + data << std::endl;
	}
};

class Service
{
public:
	void serviceMethod(int specialData) {
		std::cout << "do stuff with special data: " + std::to_string(specialData) << std::endl;
	};
};

class Adapter : private Service, public ExistingClass
{
public:
	void method(std::string data) {
		int specialData = convertToServiceFormat(data);
		serviceMethod(specialData);
	}

private:
	int convertToServiceFormat(std::string data) { return data.length(); };
};

int main()
{
	ExistingClass* p = new ExistingClass();
	p->method("hello");
	//std::cout << "Celsius temperature = " << p->getTemperature() << endl;
	delete p;

	p = new Adapter();
	p->method("hello");
	delete p;
	return 0;
}