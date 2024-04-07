#include <iostream>
#include <string>
using namespace std;

class Character abstract
{
public:
	virtual int GetAttack() abstract;
	virtual int GetSpeed() abstract;
	virtual int GetHealth() abstract;
	virtual int GetArmor() abstract;
	void PrintInfo()
	{
		cout << "Attack: " << GetAttack() << endl;
		cout << "Speed: " << GetSpeed() << endl;
		cout << "Health: " << GetHealth() << endl;
		cout << "Armor: " << GetArmor() << endl;
	}
};

//humans
class Human : public Character
{
public:
	int GetAttack() override { return 20; }
	int GetSpeed() override { return 20; }
	int GetHealth() override { return 150; }
	int GetArmor() override { return 0; }
};

class HumanDecorator abstract : public Human
{
protected:
	Human* human;
public:
	HumanDecorator(Human* human) { this->human = human; }
};

class HumanWarrior : public HumanDecorator
{
public:
	HumanWarrior(Human* human = nullptr) : HumanDecorator(human) {}
	int GetAttack() override { return human->GetAttack() + 20; }
	int GetSpeed() override { return human->GetSpeed() + 10; }
	int GetHealth() override { return human->GetHealth() + 50; }
	int GetArmor() override { return human->GetArmor() + 20; }
};

class HumanWarriorDecorator abstract : public HumanWarrior
{
protected:
	HumanWarrior* humanWarrior;
public:
	HumanWarriorDecorator(HumanWarrior* humanWarrior) { this->humanWarrior = humanWarrior; }
};

class HumanSwordsman : public HumanWarriorDecorator
{
public:
	HumanSwordsman(HumanWarrior* humanWarrior = nullptr) : HumanWarriorDecorator(humanWarrior) {}
	int GetAttack() override { return humanWarrior->GetAttack() + 40; }
	int GetSpeed() override { return humanWarrior->GetSpeed() - 10; }
	int GetHealth() override { return humanWarrior->GetHealth() + 50; }
	int GetArmor() override { return humanWarrior->GetArmor() + 40; }
};
class HumanArcher : public HumanWarriorDecorator
{
public:
	HumanArcher(HumanWarrior* humanWarrior = nullptr) : HumanWarriorDecorator(humanWarrior) {}
	int GetAttack() override { return humanWarrior->GetAttack() + 20; }
	int GetSpeed() override { return humanWarrior->GetSpeed() + 20; }
	int GetHealth() override { return humanWarrior->GetHealth() + 50; }
	int GetArmor() override { return humanWarrior->GetArmor() + 10; }
};

class HumanSwordsmanDecorator abstract : public HumanSwordsman
{
protected:
	HumanSwordsman* swordsman;
public:
	HumanSwordsmanDecorator(HumanSwordsman* swordsman) { this->swordsman = swordsman; }
};

class HumanHorseman : public HumanSwordsmanDecorator
{
public:
	HumanHorseman(HumanSwordsman* swordsman = nullptr) : HumanSwordsmanDecorator(swordsman) {}
	int GetAttack() override { return swordsman->GetAttack() - 10; }
	int GetSpeed() override { return swordsman->GetSpeed() + 40; }
	int GetHealth() override { return swordsman->GetHealth() + 200; }
	int GetArmor() override { return swordsman->GetArmor() + 100; }
};

//elfs
class Elf : public Character
{
public:
	int GetAttack() override { return 15; }
	int GetSpeed() override { return 30; }
	int GetHealth() override { return 100; }
	int GetArmor() override { return 0; }
};

class ElfDecorator abstract : public Elf
{
protected:
	Elf* elf;
public:
	ElfDecorator(Elf* elf) { this->elf = elf; }
};

class ElfWarrior : public ElfDecorator
{
public:
	ElfWarrior(Elf* elf = nullptr) : ElfDecorator(elf) {}
	int GetAttack() override { return elf->GetAttack() + 20; }
	int GetSpeed() override { return elf->GetSpeed() - 10; }
	int GetHealth() override { return elf->GetHealth() + 100; }
	int GetArmor() override { return elf->GetArmor() + 20; }
};
class ElfWizard : public ElfDecorator
{
public:
	ElfWizard(Elf* elf = nullptr) : ElfDecorator(elf) {}
	int GetAttack() override { return elf->GetAttack() + 10; }
	int GetSpeed() override { return elf->GetSpeed() + 10; }
	int GetHealth() override { return elf->GetHealth() - 50; }
	int GetArmor() override { return elf->GetArmor() + 10; }
};

class ElfWarriorDecorator : public ElfWarrior
{
protected:
	ElfWarrior* elfWarrior;
public:
	ElfWarriorDecorator(ElfWarrior* elfWarrior) { this->elfWarrior = elfWarrior; }
};

class ElfCrossbowman : public ElfWarriorDecorator
{
public:
	ElfCrossbowman(ElfWarrior* elfWarrior = nullptr) : ElfWarriorDecorator(elfWarrior) {}
	int GetAttack() override { return elfWarrior->GetAttack() + 20; }
	int GetSpeed() override { return elfWarrior->GetSpeed() + 10; }
	int GetHealth() override { return elfWarrior->GetHealth() + 50; }
	int GetArmor() override { return elfWarrior->GetArmor() - 10; }
};

class ElfWizardDecorator : public ElfWizard
{
protected:
	ElfWizard* elfWizard;
public:
	ElfWizardDecorator(ElfWizard* elfWizard) { this->elfWizard = elfWizard; }
};

class ElfEvilWizard : public ElfWizardDecorator
{
public:
	ElfEvilWizard(ElfWizard* elfWizard = nullptr) : ElfWizardDecorator(elfWizard) {}
	int GetAttack() override { return elfWizard->GetAttack() + 70; }
	int GetSpeed() override { return elfWizard->GetSpeed() + 20; }
	int GetHealth() override { return elfWizard->GetHealth() + 0; }
	int GetArmor() override { return elfWizard->GetArmor() + 0; }
};

class ElfGoodWizard : public ElfWizardDecorator
{
public:
	ElfGoodWizard(ElfWizard* elfWizard = nullptr) : ElfWizardDecorator(elfWizard) {}
	int GetAttack() override { return elfWizard->GetAttack() + 50; }
	int GetSpeed() override { return elfWizard->GetSpeed() + 30; }
	int GetHealth() override { return elfWizard->GetHealth() + 100; }
	int GetArmor() override { return elfWizard->GetArmor() + 30; }
};

int main()
{
	Human* Human1 = new Human();
	cout << "\tClass \"Human\"" << endl;
	Human1->PrintInfo();
	cout << "-----------------------" << endl;

	HumanWarrior* HumanWarrior1 = new HumanWarrior(Human1);
	cout << "\tClass \"Human Warrior\"" << endl;
	HumanWarrior1->PrintInfo();
	cout << "-----------------------" << endl;

	HumanSwordsman* Swordsman1 = new HumanSwordsman(HumanWarrior1);
	cout << "\tClass \"Human Swordsman\"" << endl;
	Swordsman1->PrintInfo();
	cout << "-----------------------" << endl;

	HumanHorseman* Horseman1 = new HumanHorseman(Swordsman1);
	cout << "\tClass \"Human Horseman\"" << endl;
	Horseman1->PrintInfo();
	cout << "-----------------------" << endl;

	delete Human1;
	delete HumanWarrior1;
	delete Swordsman1;
	delete Horseman1;

	system("pause");
	system("cls");

	Elf* Elf1 = new Elf();
	cout << "\tClass \"Elf\"" << endl;
	Elf1->PrintInfo();
	cout << "-----------------------" << endl;

	ElfWizard* ElfWizard1 = new ElfWizard(Elf1);
	cout << "\tClass \"Elf Wizard\"" << endl;
	ElfWizard1->PrintInfo();
	cout << "-----------------------" << endl;

	ElfGoodWizard* ElfGoodWizard1 = new ElfGoodWizard(ElfWizard1);
	cout << "\tClass \"Elf Good Wizard\"" << endl;
	ElfGoodWizard1->PrintInfo();
	cout << "-----------------------" << endl;

	delete Elf1;
	delete ElfWizard1;
	delete ElfGoodWizard1;
}