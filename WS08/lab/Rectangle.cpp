
/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Rectangle.h"
#include<cstring>

using namespace std;

namespace sdds {

	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* cstring, int width, int height) : LblShape(cstring){
		m_width = width;
		m_height = height;

		if (cstring && height <= 3 && m_width <= (int)strlen(label()) + 2)
		{
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		while (istr.get() != '\n');
	}

	void Rectangle::draw(std::ostream& ostr) const {
		if (m_width > 0 && m_height > 0)
		{
			cout << '+';
			cout.width(m_width - 2);
			cout.fill('-');
			cout << '-' << '+' << endl;
			cout << '|';
			cout.setf(ios::left);
			cout.width(m_width - 2);
			cout.fill(' ');
			cout << label() << '|' << endl;
			cout.unsetf(ios::left);
			for (int i = 0; i < m_height - 3; i++)
			{
				cout << '|';
				cout.width(m_width - 2);
				cout.fill(' ');
				cout << ' ' << '|' << endl;
			}
			cout << '+';
			cout.width(m_width - 2);
			cout.fill('-');
			cout << '-' << '+';
		}
	}
}