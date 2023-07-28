/*
Name : Prarthan Dhaval Christian
Id : 175063213
Email : pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Truck.h"
using namespace std;
namespace sdds {
	
	Truck::Truck(const char* plateNumber, int yearBUILT, double capacity, const char* currentAddress) : MotorVehicle(plateNumber, yearBUILT){
		m_currentCargo = 0;
		m_capacity = capacity;
		moveTo(currentAddress);
	}

	bool Truck::addCargo(double cargo) {
		double temp = m_currentCargo;
		if (m_currentCargo < m_capacity)
		{
			m_currentCargo += cargo;
			if (m_currentCargo > m_capacity)
				m_currentCargo = m_capacity;
			
		}
		return temp != m_currentCargo;
	}

	bool Truck::unloadCargo() {
		double temp = m_currentCargo;
		m_currentCargo = 0;
		return temp != m_currentCargo;
	}

	ostream& Truck::write(ostream& os) const{
		return MotorVehicle::write(os) << " | " << m_currentCargo << '/' << m_capacity;

	}

	istream& Truck::read(istream& in) {

		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_currentCargo;
		return in;

	}
	

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck) {
		return truck.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& truck) {
		return truck.read(istr);
	}
}