#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Herbivore abstract
{
protected:
	string Name;
	bool IsLife;
	int Weight;
	Herbivore(int Weight)
	{
		IsLife = true;
		this->Weight = Weight;
	}
public:
	void EatGrass()
	{
		this->Weight += 10;
		cout << this->Name << " eats; Weight = " << this->Weight << endl;
	}

	string getName() { return this->Name; }
	int getWeight() { return this->Weight; }
	bool getIsLife() { return this->IsLife; }

	void setWeight(int Weight) { this->Weight = Weight; }
	void setIsLife(bool IsLife) { this->IsLife = IsLife; }
};
class Wildebest : public Herbivore
{
public:
	Wildebest(int Weight) : Herbivore(Weight)
	{
		string Name = "Wildebest";
		this->Name = Name;
	}
};
class Bison : public Herbivore
{
public:
	Bison(int Weight) : Herbivore(Weight)
	{
		string Name = "Bison";
		this->Name = Name;
	}
};
class Elk : public Herbivore
{
public:
	Elk(int Weight) : Herbivore(Weight)
	{
		string Name = "Elk";
		this->Name = Name;
	}
};

class Carnivore abstract
{
protected:
	string Name;
	int Power;
	Carnivore(int Power) { this->Power = Power; }
public:
	void Eat(Herbivore* animal)
	{
		if (animal->getWeight() <= this->Power)
		{
			this->Power += 10;
			animal->setIsLife(false);
			cout << Name << " eats " << animal->getName() << endl;
		}
		else
		{
			this->Power -= 10;
			cout << Name << " can't eat " << animal->getName() << endl;
		}
	}

	int getPower() { return this->Power; }
	string getName() { return this->Name; }
	void setPower(int Power) { this->Power = Power; }
};
class Lion : public Carnivore
{
public:
	Lion(int Power) : Carnivore(Power)
	{
		string Name = "Lion";
		this->Name = Name;
	}
};
class Wolf : public Carnivore
{
public:
	Wolf(int Power) : Carnivore(Power)
	{
		string Name = "Wolf";
		this->Name = Name;
	}
};
class Tiger : public Carnivore
{
public:
	Tiger(int Power) : Carnivore(Power)
	{
		string Name = "Tiger";
		this->Name = Name;
	}
};

class Continent
{
public:
	virtual Carnivore* CreateCarnivore(int min, int max) abstract;
	virtual Herbivore* CreateHerbivore(int min, int max) abstract;
};
class Africa : public Continent
{
public:
	Carnivore* CreateCarnivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Lion(num);
	}
	Herbivore* CreateHerbivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Wildebest(num);
	}
};
class NorthAmerica : public Continent
{
public:
	Carnivore* CreateCarnivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Wolf(num);
	}
	Herbivore* CreateHerbivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Bison(num);
	}
};
class Eurasia : public Continent
{
public:
	Carnivore* CreateCarnivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Tiger(num);
	}
	Herbivore* CreateHerbivore(int min, int max) override
	{
		int range = max - min + 1;
		int num = rand() % range + min;
		return new Elk(num);
	}
};

class AnimalWorld
{
public:
	vector <Carnivore*> ArrayCarnivore;
	vector <Herbivore*> ArrayHerbivores;
	void AddCarnivoreAnimal(Carnivore* animal)
	{
		ArrayCarnivore.push_back(animal);
	}
	void AddHerbivoreAnimal(Herbivore* animal)
	{
		ArrayHerbivores.push_back(animal);
	}
	vector <Carnivore*> getArrayCarnivore()
	{
		return this->ArrayCarnivore;
	}
	vector <Herbivore*> getArrayHerbivores()
	{
		return this->ArrayHerbivores;
	}

	void EatHerbivore()
	{
		for (int i = 0; i < ArrayHerbivores.size(); i++)
		{
			Herbivore* obj = ArrayHerbivores[i];
			obj->EatGrass();
		}
	}

	void EatCarnivore()
	{
		if (ArrayHerbivores.size() == 0)
		{
			cout << "Array of herbivores is empty" << endl;
			return;
		}

		for (int i = 0; i < ArrayCarnivore.size(); i++)
		{
			bool IsEat = false;
			Carnivore* objCarnivore = ArrayCarnivore[i];

			for (int j = 0; j < ArrayHerbivores.size(); j++)
			{
				Herbivore* objHerbivore = ArrayHerbivores[i];
				
				if (objHerbivore->getIsLife() == true)
				{
					objCarnivore->Eat(objHerbivore);
					IsEat = true;
					break;
				}
			}

			if (!IsEat)
			{
				int power = objCarnivore->getPower();
				power -= 10;
				objCarnivore->setPower(power);
				cout << /*objCarnivore->getName() <<*/ " is starving" << endl;
			}
		}
	}

	void PrintStatus()
	{
		cout << "\tCarnivore status:\n";
		for (int i = 0; i < ArrayCarnivore.size(); i++)
		{
			Carnivore* obj = ArrayCarnivore[i];
			cout << obj->getName() << " have " << obj->getPower() << " power;" << endl;
		}
		cout << "------------------------------------\n";
		cout << "\tCarnivore status:\n";
		for (int i = 0; i < ArrayHerbivores.size(); i++)
		{
			Herbivore* obj = ArrayHerbivores[i];
			cout << obj->getName() << " is " << ((obj->getIsLife() == true) ? "alive" : "dead") << " and have " << obj->getWeight() << " weight;" << endl;
		}
	}
};

int main()
{
	AnimalWorld obj;
	srand(time(NULL));

	Africa ContinentAfrica;
	obj.AddCarnivoreAnimal(ContinentAfrica.CreateCarnivore(50, 80));
	obj.AddHerbivoreAnimal(ContinentAfrica.CreateHerbivore(50, 80));

	NorthAmerica ContinentNorthAmerica;
	obj.AddCarnivoreAnimal(ContinentNorthAmerica.CreateCarnivore(50, 80));
	obj.AddHerbivoreAnimal(ContinentNorthAmerica.CreateHerbivore(50, 80));

	Eurasia ContinentEurasia;
	obj.AddCarnivoreAnimal(ContinentEurasia.CreateCarnivore(50, 80));
	obj.AddHerbivoreAnimal(ContinentEurasia.CreateHerbivore(50, 80));

	obj.EatHerbivore();
	obj.EatCarnivore();

	system("pause");
	system("cls");

	obj.PrintStatus();
}