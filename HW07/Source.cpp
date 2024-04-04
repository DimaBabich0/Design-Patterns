#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component abstract
{
protected:
	string name;
	int price;
public:
	Component(string name)
	{
		this->name = name;
		this->price = 0;
	}
	Component(string name, int price)
	{
		this->name = name;
		this->price = price;
	}
	virtual void Add(Component* c) abstract;
	virtual void Remove(Component* c) abstract;
	virtual void Display(int depth) abstract;
};

class Composite : public Component
{
	vector<Component*> root2onents;

public:
	Composite(string name) : Component(name) {}
	Composite(string name, int price) : Component(name, price) {}

	void Add(Component* root2onent) override
	{
		root2onents.push_back(root2onent);
	}
	void Remove(Component* root2onent) override
	{
		auto iter = find(root2onents.begin(), root2onents.end(), root2onent);
		root2onents.erase(iter);
	}
	void Display(int depth) override
	{
		if (this->name.size() != 0)
		{
			string s(depth, '-');
			if(this->price != 0)
				cout << s << this->name << " (" << this->price << ")" << endl;
			else
				cout << s + this->name << endl;
		}

		for (Component* root2onent : root2onents)
		{
			root2onent->Display(depth + 2);
		}
	}
};

class Leaf : public Component
{
public:
	Leaf(string name) : Component(name) {}
	Leaf(string name, int price) : Component(name, price) {}

	void Add(Component* c) override
	{
		cout << "Cannot add to file\n";
	}
	void Remove(Component* c) override
	{
		cout << "Cannot remove from file\n";
	}
	void Display(int depth) override
	{
		string s(depth, '-');
		if(this->price != 0)
			cout << s << this->name << " (" << this->price << ")" << endl;
		else
			cout << s << this->name << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Component* main = new Composite("");

	Component* root1 = new Composite("Receiving room");
	root1->Add(new Leaf("Should be made in warm colors"));

	Component* root11 = new Composite("Coffee table", 2800);
	root11->Add(new Leaf("10-20 journals such as «computer world»", 1600));
	root1->Add(root11);

	root1->Add(new Leaf("Soft sofa", 2200));

	Component* root12 = new Composite("Secretary's desk", 1699);
	Component* root121 = new Composite("Computer", 11599);
	root121->Add(new Leaf("It's important to have a large hard drive"));

	Component* root122 = new Composite("Office tooling", 1299);

	root12->Add(root121);
	root12->Add(root122);
	root1->Add(root11);

	root1->Add(new Leaf("Cooler with warm and cold water", 1299));
	main->Add(root1);

	Component* root2 = new Composite("Audience 1");
	root2->Add(new Leaf("10 tables", 12999));
	root2->Add(new Leaf("Board", 2600));

	Component* root21 = new Composite("Teacher’s table", 1300);
	root21->Add(new Leaf("Computer", 11299));
	root2->Add(root21);

	root2->Add(new Leaf("Posters of the great mathematicians", 1299));
	main->Add(root2);

	Component* root3 = new Composite("Audience 2");

	Component* root31 = new Composite("20 tables", 1699);
	root31->Add(new Leaf("Black tables"));
	root31->Add(new Leaf("Tables set in oval or circle"));
	root3->Add(root31);

	root3->Add(new Leaf("Board", 2600));
	root3->Add(new Leaf("Soft sofa", 2600));
	main->Add(root3);

	Component* root4 = new Composite("Computer audience");
	root4->Add(new Leaf("10 computer tables", 15999));
	Component* root41 = new Composite("Computer on each desk");
	Component* root411 = new Leaf("Processor 2.2GHz");
	Component* root412 = new Leaf("80GB Hard Drive");
	Component* root413 = new Leaf("RAM 1024MB");
	root41->Add(root411);
	root41->Add(root412);
	root41->Add(root413);
	root4->Add(root41);

	root4->Add(new Leaf("Board", 2600));
	main->Add(root4);

	Component* root5 = new Composite("Cafeteria");
	root5->Add(new Leaf("Coffee machine", 50599));
	Component* root51 = new Composite("Table", 1299);
	root51->Add(new Leaf("4 chairs", 1699));
	root5->Add(root51);
	root5->Add(new Leaf("Fridge", 2229));
	root5->Add(new Leaf("Sink", 1599));
	main->Add(root5);

	main->Display(1);
	cout << "\n\n";

	system("pause");
}
