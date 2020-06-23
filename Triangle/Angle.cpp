#include "Angle.h"
bool operator==(const Angle& a, const Angle& b)
{
	return ((a.m_degree == b.m_degree) && (a.m_minute == b.m_minute));
}
bool operator!=(const Angle& a, const Angle& b)
{
	return !(a==b);
}
bool operator<(Angle& a, Angle& b)
{
	return ((static_cast<double>(a.m_degree) * 100 + a.m_minute) / 100.0) < ((static_cast<double>(b.m_degree) * 100 + b.m_minute) / 100.0);
}
bool operator<=(Angle& a, Angle& b)
{
	return ((a<b)||(a==b));
}
bool operator>(Angle& a, Angle& b)
{
	return !(a <= b);
}
bool operator>=(Angle& a, Angle& b)
{
	return !(a<b);
}
 Angle operator+(const Angle& a, const Angle& b)
{
	Angle temp;
	temp.m_minute = (a.m_minute + b.m_minute) % 60;
	temp.m_degree = a.m_degree + b.m_degree + (a.m_minute + b.m_minute) / 60;
	return temp;
}
 Angle operator-(const Angle& a, const Angle& b)
{
	Angle temp;
	temp.m_minute = (60 + a.m_minute - b.m_minute) % 60;
	temp.m_degree = a.m_degree - b.m_degree - 1 + (60 + a.m_minute - b.m_minute) / 60;
	return temp;
}
 Angle operator+(int a, const Angle& b)
{
	return Angle(a + b.GetDeg(), b.GetMin());
}
 Angle operator+(const Angle& b, int a)
{
	 return (a + b);
}
 Angle operator-(int a, const Angle& b)
{	
	short min = (60 - b.GetMin()) % 60;
	short deg = a - b.GetDeg() - 1 + (60 - b.GetMin()) / 60;
	return Angle(deg, min);
}
 Angle operator-(const Angle& b, int a)
{	
	 return a - b;
}
 Angle operator/(const Angle& a, int b)
{
	Angle temp;
	double c = (a.m_degree * 60 + a.m_minute) / (b * 60);
	temp.SetAngle(c);
	return temp;
}
