#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
	//  user-defined data-type for name Population
	struct Population
	{
		char* postalCode;
		int population;
	};

	//  Function declaration for loading an Population structure. It has one parameter and it returns true and false. This has return type of bool.
	bool load(Population& popData);

	//  Function declaration for allocating a array of Population and load all the file data into the array.This has return type of bool
	bool load(const char datafile[]);

	//  Function declaration for sorting the dynamic array of employees based on GPA of employees. This doesn't return any value
	void sort();

	//  Function declaration for displaying the sorted output.This doesn't return any value
	void display();

	//  Function declaration  for deallocating the postalcode in Population elements then deallocate the population.
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_