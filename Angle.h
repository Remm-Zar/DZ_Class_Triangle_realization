#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Angle
{
	short m_degree=0;
	short m_minute=0;
public:
	Angle(){}
	Angle(int degree, int minute)
	{
		m_minute = minute % 60;
		m_degree = degree + minute / 60;
	}
	Angle(double D)
	{
		SetAngle(D);
	}
	double Radians()const
	{
		double angle = (static_cast<double>(m_degree)*100 + m_minute)/100.0;
		return (angle * 3.14159) / 180.0;
	}
	void Diapasone()
	{
		m_degree %= 360;
	}
	void increase(int degree, int minute)
	{
		m_minute = (m_minute + minute) % 60;
		m_degree += degree+ (m_minute + minute) / 60;
	}
	void descrease(int degree, int minute)
	{
		m_minute = (m_minute+60 - minute % 60)%60;
		if (m_minute < 0)
		{
			m_minute = -m_minute;
			m_degree = m_degree - degree - 1;
		}
		else
		{
			m_degree = m_degree;
		}
	}
	void SetAngle(int degree, int minute)
	{
		m_degree = degree;
		m_minute = minute;
	}
	void SetAngle(double D)
	{
		double c;
		m_minute = static_cast<short>(60*modf(D, &c));
		m_degree = static_cast<short>(c);
	}
	void SetAngle(const Angle& a)
	{
		m_degree = a.m_degree;
		m_minute = a.m_minute;
	}
	short GetDeg()
	{
		return m_degree;
	}
	short GetMin()
	{
		return m_minute;
	}	
	double GetSin()const
	{
		if (m_degree == 90)
		{
			return 1.0;
		}
		if (m_degree == 30)
		{
			return 0.5;
		}
		return sin(this->Radians());
	}
	double GetCos()
	{
		if (m_degree == 90)
		{
			return 0.0;
		}
		if (m_degree == 60)
		{
			return 0.5;
		}
		return cos(this->Radians());
	}
	void operator+=(const Angle& a)
	{
		increase(a.m_degree, a.m_minute);
	}
	friend ostream& operator<<(ostream& out, Angle& a)
	{
		out << a.m_degree << "." << a.m_minute << "'";
		return out;
	}
	friend Angle operator+(const Angle& a, const Angle& b);
	friend Angle operator-(const Angle& a, const Angle& b);
	friend Angle operator+(int a, const Angle& b);
	friend Angle operator+(const Angle& b, int a);
	friend Angle operator-(int a, const Angle& b);
	friend Angle operator-(const Angle& b, int a);
	friend Angle operator/(const Angle& a, int b);
	friend bool operator==(const Angle& a, const Angle& b);
	friend bool operator!=(const Angle& a, const Angle& b);
	friend bool operator<(Angle& a, Angle& b);
	friend bool operator<=(Angle& a, Angle& b);
	friend bool operator>(Angle& a, Angle& b);
	friend bool operator>=(Angle& a, Angle& b);
};
