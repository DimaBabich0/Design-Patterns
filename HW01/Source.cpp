#include <iostream>
#include <string>
using namespace std;

class Figure
{
protected:
	bool arr[4][4];
	int color;
public:
	Figure()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	virtual void Create() = 0;
	void Print()
	{
		int dColor = 31 + color;
		string strColor = "\033[" + to_string(dColor) + "m";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == true)
					cout << strColor << "*" << "\033[0m";
				else
					cout << strColor << " " << "\033[0m";
			}
			cout << endl;
		}
	}
};

class FigureO : public Figure
{
public:
	void Create() override
	{
		arr[0][0] = 1;
		arr[0][1] = 1;
		arr[1][0] = 1;
		arr[1][1] = 1;

		color = 2;
	}
};

class FigureI : public Figure
{
public:
	void Create() override
	{
		arr[0][0] = 1;
		arr[1][0] = 1;
		arr[2][0] = 1;
		arr[3][0] = 1;

		color = 3;
	}
};

class FigureS : public Figure
{
public:
	void Create() override
	{
		arr[0][1] = 1;
		arr[0][2] = 1;
		arr[1][0] = 1;
		arr[1][1] = 1;

		color = 4;
	}
};

class FigureZ : public Figure
{
public:
	void Create() override
	{
		arr[0][0] = 1;
		arr[0][1] = 1;
		arr[1][1] = 1;
		arr[1][2] = 1;

		color = 5;
	}
};

class FigureL : public Figure
{
public:
	void Create() override
	{
		arr[0][0] = 1;
		arr[1][0] = 1;
		arr[2][0] = 1;
		arr[2][1] = 1;

		color = 6;
	}
};

class Developer abstract
{
public:
	virtual Figure* Create() = 0;
};

class FigureODeveloper : public Developer
{
public:
	Figure* Create() override
	{
		Figure* obj = new FigureO;
		obj->Create();
		obj->Print();
		return obj;
	}
};

class FigureIDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		Figure* obj = new FigureI;
		obj->Create();
		obj->Print();
		return obj;
	}
};

class FigureSDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		Figure* obj = new FigureS;
		obj->Create();
		obj->Print();
		return obj;
	}
};

class FigureZDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		Figure* obj = new FigureZ;
		obj->Create();
		obj->Print();
		return obj;
	}
};

class FigureLDeveloper : public Developer
{
public:
	Figure* Create() override
	{
		Figure* obj = new FigureL;
		obj->Create();
		obj->Print();
		return obj;
	}
};

void main()
{
	srand(time(NULL));

	cout << "\tFigure \"O\":\n";
	Developer* pDev = new FigureODeveloper();
	pDev->Create();
	delete pDev;
	cout << "------------------------\n";

	cout << "\tFigure \"I\":\n";
	pDev = new FigureIDeveloper();
	pDev->Create();
	delete pDev;
	cout << "------------------------\n";

	cout << "\tFigure \"S\":\n";
	pDev = new FigureSDeveloper();
	pDev->Create();
	delete pDev;
	cout << "------------------------\n";

	cout << "\tFigure \"Z\":\n";
	pDev = new FigureZDeveloper();
	pDev->Create();
	delete pDev;
	cout << "------------------------\n";

	cout << "\tFigure \"L\":\n";
	pDev = new FigureLDeveloper();
	pDev->Create();
	delete pDev;
	cout << "------------------------\n";
}
