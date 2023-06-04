/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds
{

	//  Defining a variable name record of integer-type.
	int record;

	//  Defining a variable name pop of user-define data type Population
	Population* pop;

	//  Function defination for loading a data.
	bool load(Population& popData)
	{
		bool ok = false;
		char name[128];

		if (read(name) && read(popData.population))
		{
			int lenght = strLen(name) + 1;
			popData.postalCode = new char[lenght];
			strCpy(popData.postalCode, name);
			ok = true;
		}
		return ok;
	}

	//  Function defination for loadind a data into allocated array.
	bool load(const char datafile[])
	{
		bool ok = false;
		bool stop = false;

		if (openFile(datafile))
		{
			record = noOfRecords();
			pop = new Population[record];

			for (int i = 0; i < record && !stop; i++)
			{
				if (load(pop[i]) == false)
				{
					cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
					stop = true;
				}
				else
				{
					ok = true;
				}
			}

			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << datafile;
		}
		return ok;
	}

	//  Function defination for sorting the data from the file.
	void sort()
	{
		int i, j;
		Population temp;
		for (i = record - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (pop[j].population > pop[j + 1].population)
				{
					temp = pop[j];
					pop[j] = pop[j + 1];
					pop[j + 1] = temp;
				}
			}
		}
	}

	//  Function defination for displaying the sorted output
	void display()
	{
		int totPopulation = 0;

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort();

		for (int i = 0; i < record; i++)
		{
			cout << i + 1 << "- " << pop[i].postalCode << ":  " << pop[i].population << endl;
			totPopulation += pop[i].population;
		}

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totPopulation << endl;
	}


	//  Function defination for deallocateing the Memory
	void deallocateMemory()
	{
		delete[] pop;
	}
}