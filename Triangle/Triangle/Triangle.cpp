#include "Triangle.h"
void Triangle::SetTringle(double a, double b, int degree, int minute)
{
	m_a = a;
	m_b = b;
	m_ab.SetAngle(degree, minute);
	if (a == b)
	{

		if (m_ab == Angle(60, 0))
		{
			m_c = m_a;
			m_bc.SetAngle(60, 0);
			m_ac.SetAngle(60, 0);
		}
		else
		{
			m_c = sqrt(m_a * m_a + m_b * m_b - 2 * m_a * m_b * m_ab.GetCos());
			m_bc.SetAngle((180 - m_ab) / 2);
			m_ac.SetAngle(m_bc);
		}
	}
	else
	{
		m_c = sqrt(m_a * m_a + m_b * m_b - 2 * m_a * m_b * m_ab.GetCos());
		double u = m_b * m_ab.GetSin();
		double y = u / m_c;
		double z;
		if (1 - y <= 0.000001)
		{
			z = 1.57;
		}
		else
		{
			z = asin(y);
		}
		m_ac.SetAngle(z * 180 / 3.14);
		m_bc.SetAngle(Angle(180, 0) - m_ab - m_ac);
	}
}
void Triangle::Config()const
{
	bool F = true;
	if ((m_a == m_b) && (m_a == m_c))
	{
		cout << "\nEquilateral ";
		F = false;
	}
	else
	{
		if ((m_a == m_b) || (m_a == m_c) || (m_b == m_c))
		{
			cout << "\nIsosceles ";
			F = false;
		}
		if ((m_ab == Angle(90, 0)) || (m_bc == Angle(90, 0)) || (m_ac == Angle(90, 0)))
		{
			cout << "Rectangular ";
			F = false;
		}
	}
	if (F)
	{
		cout << "\nGeneral view triangle";
	}
	else
	{
		cout << "triangle";
	}
}
