/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;
namespace sdds {
	void CalorieList::setEmpty() {
		food = nullptr;
	}

	void CalorieList::init(int size) {
		int i;

		if (size > 0) 
		{
			food = new Food[size];
			m_size = size;
			m_count = 0;

			for (i = 0; i < m_size; i++) 
			{
				food[i].setEmpty();
			}
		}
		else 
		{
			setEmpty();
		}
	}

	bool CalorieList::isValid() const {
		return food == nullptr;
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {
		if (m_count < m_size) 
		{
			food[m_count].set(item_name, calories, when);
			m_count++;
			return true;
		}
		return false;
	}



	void CalorieList::Title(bool isValid)const {

		cout << "+----------------------------------------------------+" << endl;

		if (!isValid) 
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		else 
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::display() {
		bool isValid = true;
		int i;
		for (i = 0; i < m_size; i++) 
		{
			if (!food[i].isValid()) 
			{
				isValid = false;
				break;
			}
		}

		Title(isValid);

		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

		for (i = 0; i < m_size; i++) 
		{
			food[i].display();
		}
		Footer(isValid);

	}

	void CalorieList::Footer(bool isValid)const {
		int total;
		int i;
		cout << "+--------------------------------+------+------------+" << endl;
		if (!isValid) 
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		else
		{
			total = 0;
			for (i = 0; i < m_size; i++) 
			{
				total = total + food[i].getCalories();

			}

			cout << "|    Total Calories for today:";
			cout.width(9);
			cout.setf(ios::right);
			cout << total;
			cout.unsetf(ios::right);

			cout << " |";
			cout.width(13);
			cout.fill(' ');
			cout << " |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::deallocate() 
	{
		delete[] food;
		food = nullptr;
	}

}