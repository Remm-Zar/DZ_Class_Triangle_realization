#pragma once
#include "Angle.h"
#include <cmath>
#include <iostream>
using namespace std;
class Triangle
{
	double m_a=0;
	double m_b=0;
	double m_c=0;
	Angle m_ab;
	Angle m_bc;
	Angle m_ac;
public:
	Triangle()
	{

	}
	Triangle(double a, double b, int degree, int minute)
	{
		SetTringle(a, b, degree, minute);
	}
	void Config()const;
	void SetTringle(double a, double b, int degree, int minute);
	double GetA()const
	{
		return m_a;
	}
	double GetB()const
	{
		return m_b;
	}
	double GetC()const
	{
		return m_c;
	}
	void SetA(double x)
	{
		SetTringle( x ,m_b, m_ab.GetDeg(), m_ab.GetMin());
	}
	void SetB(double x)
	{
		SetTringle(m_a, x, m_ab.GetDeg(), m_ab.GetMin());
	}
	void SetC(double x)
	{
		SetTringle(m_b, x, m_bc.GetDeg(), m_ab.GetMin());
	}
	double Perimetr()const
	{
		return m_a + m_b + m_c;
	}
	double Square()const
	{
		return m_a * m_c * 0.5 * m_ac.GetSin();
	}
	double High_BH()const
	{
		return m_a * m_ac.GetSin();
	}
	double High_AH()const
	{
		return m_c *m_bc.GetSin();
	}
	double High_CH()const
	{
		return m_c * m_ab.GetSin();
	}
	friend ostream& operator<<(ostream& out, Triangle& t)
	{
		out << "\nSides: a=" << t.m_a << ",b=" << t.m_b << ",c=" << t.m_c << "\nangles: ab=" << t.m_ab << ",bc=" << t.m_bc << ",ac=" << t.m_ac;
		return out;
	}
};

