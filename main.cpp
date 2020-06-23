#include "Triangle.h"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	Triangle t;
	cout << "Demonstration of Triangle class capabilities\nMENU:";
	cout << "\n1 - create triangle\n2 - perimetr\n3 - square\n4 - calculate high:\n     a - AH\n     b - BH\n     c - CH\n5 - set side:\n     d - a\n     e - b\n     f - c";
	cout << "\n6 - print info";
	string choice;
	cout << "\nDo you want to continue?(input yes or no)\ninput>>";
	cin >> choice;
	while (choice!="no")
	{		
		char ch;
		cout << "\nUse menu:\ninput>>";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			double a, b;
			int deg, min;
			cout << "\ninput \"a\" side: ";
			cin >> a;
			cout << "\ninput \"b\" side: ";
			cin >> b;
			cout << "\nab-angle: input degrees: ";
			cin >> deg;
			cout << "\ninput minutes: ";
			cin >> min;
			t.SetTringle(a, b, deg, min);
		}break;
		case '2':
		{
			cout << "\nPerimetr=" << t.Perimetr();
		}break;
		case '3':
		{
			cout << "\nSquare=" << t.Square();
		}break;
		case '4':
		{
			cout << "\nuse sub-menu\ninput>>";
			cin >> ch;
			switch (ch)
			{
			case 'a':
			{
				cout << "\nAH=" << t.High_AH();
			}break;
			case 'b':
			{
				cout << "\nBH=" << t.High_BH();
			}break;
			case 'c':
			{
				cout << "\nCH=" << t.High_CH();
			}break;
			}
		}
		case '5':
		{
			cout << "\nuse sub-menu\ninput>>";
			cin >> ch;
			switch (ch)
			{
				double a;
			case 'g':
			{

				cout << "\ninput \"a\" side: ";
				cin >> a;
				t.SetA(a);
			}break;
			case 'h':
			{
				cout << "\ninput \"b\" side: ";
				cin >> a;
				t.SetB(a);
			}break;
			case 'i':
			{
				cout << "\ninput \"c\" side: ";
				cin >> a;
				t.SetC(a);
			}break;
			}
		}
		case '6':
		{
			cout << t;
			t.Config();
		}
		}
		choice.erase();
		cout << "\nDo you want to continue?(input yes or no)\ninput>>";
		cin >> choice;
	}
	return 0;
}