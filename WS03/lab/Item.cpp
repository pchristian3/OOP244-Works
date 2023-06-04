#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20]='\0';
	}
		
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = char(0);
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name == nullptr || price < 0) {
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const 
	{
		double taxReturn;
		const double taxRate = 0.13;

		if (m_taxed == true)
		{
			taxReturn = taxRate * m_price;
		}
		else
		{
			taxReturn = 0;
		}
		return taxReturn;
		
	}

	bool Item::isValid()const {
		return m_itemName[0] != '\0';
	}

	void Item::display()const {
		if (isValid() == true) 
		{

			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::fixed);

			cout << " | ";
			cout.setf(ios::fixed);
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::right);
			cout.precision(2);
			cout << m_price;
			cout << " | ";
			cout.unsetf(ios::right);
			if (m_taxed == true)
			{
				cout << "Yes";

			}
			else
			{
				cout << "No ";

			}
			cout << " |" << endl;

		}
		else{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}

	}
}