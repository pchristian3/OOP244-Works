/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

namespace sdds {

	template <typename T1, typename T2>
	bool search(Collection<T1>& object,T1 arr[], int noOfEmenets, T2 key){
		bool ok = false;

		for (int i = 0; i < noOfEmenets; i++)
		{
			if (arr[i] == key)
			{
				ok = true;
				object.add(arr[i]);
			}
		}

		return ok;
	}
	
	template <typename T>
	void listArrayElements(const char* title,  const T arr[], int noOfElements) {

		if(title) std::cout << title << std::endl;
		for (int i = 0; i << noOfElements; i++)
		{
			std::cout << i + 1 << ": " << arr[i] << std::endl;
		}
	}
}

#endif // !SDDS_SEARCHNLIST_H_
