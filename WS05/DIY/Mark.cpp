
/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream> 
#include <iomanip>
#include <cstring>
#include "Mark.h"


namespace sdds 
{

void Mark::setEmpty()
{
	m_grade = -1;
}

Mark::Mark()
{
	m_grade = 0;
}

Mark::Mark(int grd)
{
	setEmpty();
	
	if (grd <=100 && grd >= 0 )
	{
		m_grade = grd;
	}
}

Mark::operator bool() const
{
	return m_grade <= 100 && m_grade >= 0;
}

Mark::operator int() const
{
	int no = 0;
	if (*this) no = m_grade;
	{
		return no;
	}
}

Mark::operator double() const
{
	double no = 0.0;

	if (*this)
	{
		if (m_grade < 50)
		{
			no = 0.0;
		}
			
		else if (m_grade < 60)
		{
			no = 1.0;
		}
			
		else if (m_grade < 70)
		{
			no = 2.0;
		}
			
		else if (m_grade < 80)
		{
			no = 3.0;
		}
			
		else
		{
			no = 4.0;
		}
			
	}
	return no;
}
Mark::operator char() const
{
	char ch = 'X';

	if (*this)
	{
		if (m_grade < 50)
		{
			ch = 'F';
		}
			
		else if (m_grade < 60)
		{
			ch = 'D';
		}
			
		else if (m_grade < 70)
		{
			ch = 'C';
		}
			
		else if (m_grade < 80)
		{
			ch = 'B';
		}
			
		else
		{
			ch = 'A';
		}

	}
	return ch;
}

Mark& Mark::operator+=(int gradeAdd)
{
	if (gradeAdd >= 0 && *this)
	{
		m_grade += gradeAdd;
	}
	return *this;
}

Mark& Mark::operator=(int gradeSet)
{
	m_grade = gradeSet;
	return *this;
}

int& operator+=(int& value, Mark& marked)
{
	if (marked) value += marked.operator int();
	{
		return value;
	}

}
}	