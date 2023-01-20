#include <iostream>
#include <string>

class RouteStrategy
{
public:
	virtual ~RouteStrategy() {}
	virtual void buildRoute(const std::string A, const std::string B) = 0;
};


class RoadStrategy : public RouteStrategy
{
public:
	void buildRoute(const std::string A, const std::string B) {
		std::cout << "drive a car from " + A + " to " + B << std::endl;
	}
};


class WalkingStrategy : public RouteStrategy
{
public:
	void buildRoute(const std::string A, const std::string B) {
		std::cout << "walk from " + A + " to " + B << std::endl;
	}
};


class PublicTransport : public RouteStrategy
{
public:
	void buildRoute(const std::string A, const std::string B) {
		std::cout << "take public transport from " + A + " to " + B << std::endl;
	}
};


class Navigator
{
public:
	Navigator(RouteStrategy* strategy) : routeStrategy(strategy) {}
	~Navigator() { delete routeStrategy; }
	void buildRoute(const std::string A, const std::string B) {
		routeStrategy->buildRoute(A, B);
	}
private:
	RouteStrategy* routeStrategy;
};


int main()
{
	Navigator* navigator = new Navigator(new RoadStrategy);
	navigator->buildRoute("Home", "Work");
	delete navigator;

	navigator = new Navigator(new WalkingStrategy);
	navigator->buildRoute("Home", "Work");
	delete navigator;

	navigator = new Navigator(new PublicTransport);
	navigator->buildRoute("Home", "Work");

	delete navigator;
	return 0;
}