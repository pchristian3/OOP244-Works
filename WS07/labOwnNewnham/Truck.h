#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
	class Truck : public MotorVehicle {
		private: 
			double m_capacity;
			double m_currentCargo;

		public:
			Truck(const char* plateNumber, int yearBUILT, double capacity , const char* currentAddress);
			bool addCargo(double cargo);
			bool unloadCargo();
			ostream& write(ostream& os) const;
			istream& read(istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
	std::istream& operator>>(std::istream& istr, Truck& truck);

}



#endif // !SDDS_TRUCK_H_