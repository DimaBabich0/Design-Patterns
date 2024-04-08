#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MoveStrategy abstract
{
public:
	virtual void Move() abstract;
};

class BikeStrategy : public MoveStrategy
{
public:
	void Move() override
	{
		cout << "You got to the airport by bike." << endl;
	}
};

class BusStrategy : public MoveStrategy
{
public:
	void Move() override
	{
		cout << "You got to the airport by bus." << endl;
	}
};

class TaxiMove : public MoveStrategy
{
public:
	void Move() override
	{
		cout << "You got to the airport by taxi." << endl;
	}
};

class Client
{
private:
	MoveStrategy* moveStrategy;
public:
	void SetStrategy(MoveStrategy* moveStrategy)
	{
		this->moveStrategy = moveStrategy;
	}
	void Move()
	{
		moveStrategy->Move();
		cout << endl;
	}
};

int main()
{
	Client client;
	MoveStrategy* strategy;

	strategy = new BikeStrategy();
	client.SetStrategy(strategy);
	client.Move();
	delete strategy;

	strategy = new BusStrategy();
	client.SetStrategy(strategy);
	client.Move();
	delete strategy;

	strategy = new TaxiMove();
	client.SetStrategy(strategy);
	client.Move();
	delete strategy;

	system("pause");
	return 0;
}
