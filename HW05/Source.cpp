#include <iostream>
#include <map>
#include <string>
using namespace std;

class Context
{
public:
	int x;
	int y;
};

class Character abstract
{
protected:
	string sprite;
	int speed;
	int power;
public:
	void Show(Context* obj)
	{
		cout << "Sprite: " << this->sprite << endl;
		cout << "Speed: " << this->speed << endl;
		cout << "Power: " << this->power << endl;
		cout << "Location: " << obj->x << "; " << obj->y << endl;
	}
};

class Character1 : public Character
{
public:
	Character1()
	{
		this->sprite = "LightInfantry.jpeg";
		this->speed = 20;
		this->power = 10;
	}
};

class Character2 : public Character
{
public:
	Character2()
	{
		this->sprite = "TransportVehicle.jpeg";
		this->speed = 70;
		this->power = 0;
	}
};

class Character3 : public Character
{
public:
	Character3()
	{
		this->sprite = "HeavyGroundTransportVehicle.jpeg";
		this->speed = 15;
		this->power = 150;
	}
};

class Character4 : public Character
{
public:
	Character4()
	{
		this->sprite = "LightGroundTransportVehicle.jpeg";
		this->speed = 50;
		this->power = 30;
	}
};

class Character5 : public Character
{
public:
	Character5()
	{
		this->sprite = "Aircraft.jpeg";
		this->speed = 300;
		this->power = 100;
	}
};

class CharacterFactory
{
private:
	map<char, Character*> characters;
public:
	Character* GetCharacter(char key)
	{
		Character* character = characters[key];
		if (character == nullptr)
		{
			switch (key)
			{
			case '1':
				character = new Character1();
				break;
			case '2':
				character = new Character2();
				break;
			case '3':
				character = new Character3();
				break;
			case '4':
				character = new Character4();
				break;
			case '5':
				character = new Character5();
				break;
			}
			characters[key] = character;
		}
		return character;
	}
};

int main()
{
	string s = "1122334455";
	CharacterFactory* pCF = new CharacterFactory();
	Context coordinates;
	coordinates.x = 0;
	coordinates.y = 0;
	for (int i = 0; i < s.length(); i++)
	{
		coordinates.x = 15 * i;
		coordinates.y = 10 * i;
		Character* character = pCF->GetCharacter(s[i]);
		character->Show(&coordinates);
		cout << "--------------------------------" << endl;
	}
}
