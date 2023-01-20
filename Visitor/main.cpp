#include <iostream>
#include <string>
using namespace std;

class Element
{
public:
	virtual void accept(class Visitor& v) = 0;
};


class ElementA : public Element
{
public:
	/*virtual*/void accept(Visitor& v);
	string aDo()
	{
		return "element A";
	}
};


class ElementB : public Element
{
public:
	/*virtual*/void accept(Visitor& v);
	string bDo()
	{
		return "element B";
	}
};


class Visitor
{
public:
	virtual void visit(ElementA* e) = 0;
	virtual void visit(ElementB* e) = 0;
};

/*virtual*/void ElementA::accept(Visitor& v)
{
	v.visit(this);
}

/*virtual*/void ElementB::accept(Visitor& v)
{
	v.visit(this);
}

class FunnyVisitor : public Visitor
{
	/*virtual*/void visit(ElementA* e)
	{
		cout << "do funny stuff with" + e->aDo() << '\n';
	}
	/*virtual*/void visit(ElementB* e)
	{
		cout << "do funny stuff with " + e->bDo() << '\n';
	}
};

class SadVisitor : public Visitor
{
	/*virtual*/void visit(ElementA* e)
	{
		cout << "do sad stuff with " + e->aDo() << '\n';
	}
	/*virtual*/void visit(ElementB* e)
	{
		cout << "do sad stuff with" + e->bDo() << '\n';
	}
};

int main()
{
	Element* list[] =
	{
	  new ElementA(), new ElementB(), new ElementA()
	};

	FunnyVisitor funnyV;  //    Клиент создает 
	SadVisitor sadV;  //    объекты Visitor
	for (int i = 0; i < 3; i++)
		// и передает каждый 
		list[i]->accept(funnyV);
	for (int i = 0; i < 3; i++)
		// в вызываемый метод accept()
		list[i]->accept(sadV);
}
