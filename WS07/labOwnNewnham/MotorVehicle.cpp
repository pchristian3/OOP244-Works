/*
Name : Prarthan Dhaval Christian
Id : 175063213
Email : pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "MotorVehicle.h"

using namespace sdds;
namespace sdds {
	
	MotorVehicle::MotorVehicle(const char* plateNumber, int yearBuilt) {
		strCpy(m_plateNumber, plateNumber);
		m_yearBuilt = yearBuilt;
		strCpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_address, address) && address!=nullptr)
		{
			cout << '|';
			cout.setf(ios::right);
			cout.width(8);
			cout << m_plateNumber << "| |";
			cout.width(20);
			cout << m_address << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address << '|' << endl;
			strCpy(m_address, address);
			cout.unsetf(ios::left);
		}
	}

	ostream& MotorVehicle:: write(ostream& os) const{
		os <<  "| " << m_yearBuilt << " | " << m_plateNumber << " | " << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {

		cout << "Built year: ";
		in >> m_yearBuilt;
		while (in.get() != '\n');
		cout << "License plate: ";
		in.get(m_plateNumber, sizeof(m_plateNumber));
		if (in.fail()) in.clear();
		while (in.get() != '\n');
		cout << "Current location: ";
		in.get(m_address, sizeof(m_address));
		if (in.fail()) in.clear();
		while (in.get() != '\n');
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& motor)
	{
		return motor.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, MotorVehicle& motor)
	{
		return motor.read(istr);
	}
}
