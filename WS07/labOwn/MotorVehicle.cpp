/*
Name : Prarthan Dhaval Christian
Id : 175063213
Email : pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "cstring.h"
#include "MotorVehicle.h"

using namespace sdds;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNum, int builtYear)
	{
		strCpy(m_plateNum, plateNum);
		m_builtYear = builtYear;
		strCpy(m_currentAddress, "Factory");
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (address != nullptr && strcmp(m_currentAddress, address))
		{
			cout << '|';
			cout.setf(ios::right);
			cout.width(8);
			cout << m_plateNum << "| |";
			cout.width(20);
			cout << m_currentAddress << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address << '|' << endl;
			strCpy(m_currentAddress, address);
			cout.unsetf(ios::left);
		}
	}
	ostream& MotorVehicle::write(ostream& os) const
	{
		os << "| " << m_builtYear << " | " << m_plateNum << " | " << m_currentAddress;
		return os;
	}
	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_builtYear;
		while (in.get() != '\n');
		cout << "License plate: ";
		in.get(m_plateNum, sizeof(m_plateNum));
		if (in.fail()) in.clear();
		while (in.get() != '\n');
		cout << "Current location: ";
		in.get(m_currentAddress, sizeof(m_currentAddress));
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
