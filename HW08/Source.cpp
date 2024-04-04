#include <iostream>
#include <string>
using namespace std;

class I�omponent abstract
{
public:
	virtual void PrintInfo() abstract;
};

class RAM: public I�omponent
{
protected:
	int capacity;
	float price;
	string manufacturer;
	string type;
public:
	RAM(int capacity, float price, string manufacturer, string type)
	{
		this->capacity = capacity;
		this->price = price;
		this->manufacturer = manufacturer;
		this->type = type;
	}
	void PrintInfo() override
	{
		cout << "\tRAM:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Price: " << this->price << endl;
		cout << "Manufacturer: " << this->manufacturer << endl;
		cout << "Type: " << this->type << endl;
	}
};

class HDD : public I�omponent
{
protected:
	int capacity;
	float price;
	string manufacturer;
	string type;
public:
	HDD(int capacity, float price, string manufacturer, string type)
	{
		this->capacity = capacity;
		this->price = price;
		this->manufacturer = manufacturer;
		this->type = type;
	}
	void PrintInfo() override
	{
		cout << "\tHDD:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Price: " << this->price << endl;
		cout << "Manufacturer: " << this->manufacturer << endl;
		cout << "Type: " << this->type << endl;
	}
};

class PC abstract
{
protected:
	I�omponent* component;
public:
	I�omponent* GetComponent() { return this->component; }
	void SetComponent(I�omponent* component) { this->component = component; }
	virtual void PrintInfo()
	{
		component->PrintInfo();
	}
};

class PCHome : public PC
{};

void client(I�omponent* component, PC* pc)
{
	pc->SetComponent(component);
	pc->PrintInfo();
}

int main()
{
	I�omponent* component = new RAM(8192, 1699, "Kingston", "DDR4");
	PC* pc = new PCHome();
	client(component, pc);
	delete component;

	component = new HDD(1000000, 2329, "Toshiba", "SATA 3");
	client(component, pc);
	delete component;
	delete pc;

	system("pause");
	return 0;
}
