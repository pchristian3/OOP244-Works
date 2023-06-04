/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {
	void Food::setEmpty() {
		strCpy(foodName, "\0");
		calorieNo = 0;
		timeConsumption = 0;
	}

	int Food::getCalories() {
		return calorieNo;
	}

	void Food::set(const char* name, int calories, int consumptionTime) {
		if (name != nullptr)
		{
			if (name[0] != '\0' && calories > 0 && calories <= 3000 && consumptionTime > 0 && consumptionTime <= 4) 
			{
				setName(name);
				setCalories(calories);
				setTOC(consumptionTime);
			}
		}
		else 
		{
			setEmpty();
		}
	}

	void Food::setName(const char* name) {
		strnCpy(foodName, name, 31);
		foodName[30] = '\0';
	}

	void Food::setCalories(int calories) {
		calorieNo = calories;
	}

	void Food::setTOC(int consumptionTime) {
		timeConsumption = consumptionTime;
	}

	bool Food::isValid()const {
		return foodName[0] != '\0';
	}

	void Food::display() const {
		if (isValid() == true) 
		{

			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout.setf(ios::left);
			cout << foodName;
			cout.unsetf(ios::left);

			cout << " | ";
			cout.fill(' ');
			cout.width(4);
			cout.setf(ios::right);
			cout << calorieNo <<	" | ";

			if (timeConsumption == 1) 
			{
				cout << "Breakfast  |" << endl;
			}
			else if (timeConsumption == 2) 
			{
				cout << "Lunch      |" << endl;
			}
			else if (timeConsumption == 3) 
			{
				cout << "Dinner     |" << endl;
			}
			else if (timeConsumption == 4) 
			{
				cout << "Snack      |" << endl;
			}

			cout.unsetf(ios::right);
		}
		else 
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}