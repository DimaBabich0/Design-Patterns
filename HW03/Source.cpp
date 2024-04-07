#include <iostream>
#include <string>
using namespace std;

class Car
{
	string frame;
	int engine;
	int wheels;
	string gearBox;
public:
	void SetFrame(string frame)
	{
		this->frame = frame;
	}
	string GetFrame()
	{
		return this->frame;
	}
	void SetEngine(int engine)
	{
		this->engine = engine;
	}
	int GetEngine()
	{
		return this->engine;
	}
	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	int SetWheels()
	{
		return this->wheels;
	}
	void SetGearBox(string gearBox)
	{
		this->gearBox = gearBox;
	}
	string GetGearBox()
	{
		return this->gearBox;
	}
	void ShowCar()
	{
		cout << "\tCar info:" << endl;
		cout << "Frame: " << frame << endl;
		cout << "Engine: " << engine << endl;
		cout << "Wheels: " << wheels << endl;
		cout << "Gear box: " << gearBox << endl;
	}
};

class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildFrame() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildGearBox() abstract;
};

class DaewooLanosBuilder : public CarBuilder
{
public:
	void BuildFrame() override
	{
		car.SetFrame("Sedan");
	}
	void BuildEngine() override
	{
		car.SetEngine(98);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildGearBox() override
	{
		car.SetGearBox("5 Manual");
	}
};
class FordProbeBuilder : public CarBuilder
{
public:
	void BuildFrame() override
	{
		car.SetFrame("Coupe");
	}
	void BuildEngine() override
	{
		car.SetEngine(160);
	}
	void BuildWheels() override
	{
		car.SetWheels(14);
	}
	void BuildGearBox() override
	{
		car.SetGearBox("4 Auto");
	}
};
class UAZPatriotBuilder : public CarBuilder
{
public:
	void BuildFrame() override
	{
		car.SetFrame("Universal");
	}
	void BuildEngine() override
	{
		car.SetEngine(120);
	}
	void BuildWheels() override
	{
		car.SetWheels(16);
	}
	void BuildGearBox() override
	{
		car.SetGearBox("4 Manual");
	}
};
class HyundaiGetzBuilder : public CarBuilder
{
public:
	void BuildFrame() override
	{
		car.SetFrame("Hatchback");
	}
	void BuildEngine() override
	{
		car.SetEngine(66);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildGearBox() override
	{
		car.SetGearBox("4 Auto");
	}
};

class Shop
{
	CarBuilder* carBuilder;
public:
	void SetCarBuilder(CarBuilder* pb)
	{
		carBuilder = pb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildFrame();
		carBuilder->BuildEngine();
		carBuilder->BuildWheels();
		carBuilder->BuildGearBox();
	}
};

void client(CarBuilder* builder)
{
	Shop manager;
	manager.SetCarBuilder(builder);
	manager.ConstructCar();
	Car car = manager.GetCar();
	car.ShowCar();
	cout << "---------------------" << endl << endl;
}

void main()
{
	setlocale(LC_ALL, "russian");
	CarBuilder* builder = new DaewooLanosBuilder();
	client(builder);
	delete builder;

	builder = new FordProbeBuilder();
	client(builder);
	delete builder;

	builder = new UAZPatriotBuilder();
	client(builder);
	delete builder;

	builder = new HyundaiGetzBuilder();
	client(builder);
	delete builder;
}