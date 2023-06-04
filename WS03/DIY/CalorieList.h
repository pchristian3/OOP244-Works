/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds {
	class CalorieList {
		Food* food;
		int m_size;
		int m_count;

	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display();
		void deallocate();
		void setEmpty();
		bool isValid() const;
		void Title(bool isValid)const;
		void Footer(bool isValid)const;
	};
}


#endif // !SDDS_CALORIELIST_H
