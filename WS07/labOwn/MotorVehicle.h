#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
#include <iostream>
using namespace std;
namespace sdds {
	class MotorVehicle {
		char m_plateNum[9];
		char m_currentAddress[64];
		int m_builtYear;
	public:
		MotorVehicle(const char* plateNum, int builtYear);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& motor);
	std::istream& operator>>(std::istream& istr, MotorVehicle& motor);

}
#endif // !SDDS_MOTORVEHICLE_H_