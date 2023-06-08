#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	const double PI = 3.14159265;
	const double H_MIN = 10.0;
	const double H_MAX = 40.0;
	const double D_MIN = 10;
	const double D_MAX = 30.0;
	const double D_DEFAULT = 10.0;
	const double H_DEFAULT = 13.0;
	const double V_DEFAULT = 0.0;
	const double V_VOL = 0.00001;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = H_DEFAULT;
		m_diameter = D_DEFAULT;
		m_contentVolume = V_DEFAULT;
		m_usable = true;
	}

	bool Canister::isEmpty()const {
		bool ok = true;
		if (m_contentVolume < V_VOL) {
			return ok;
		}
	}

	bool Canister::hasSameContent(const Canister& C)const {
		bool ok = true;
		int result;
		result = strCmp(C.m_contentName, m_contentName);

		if (result == 0)
		{
			ok = true;
			return ok;
		}
		else
		{
			ok = false;
			return ok;

		}
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable) {
			delete[] m_contentName;
			size_t length = strlen(Cstr) + 1;
			m_contentName = new char[length];
			strcpy(m_contentName, Cstr);

		}
		else
		{
			//do nothing
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);

	}

	Canister::Canister(double hieght, double diameter, const char* contentName) {
		setToDefault();
		if (m_height > 0.0 && m_diameter > 0.0) {
			m_height = hieght;
			m_diameter = diameter;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}

	}

	Canister::~Canister() {
		delete[] m_contentName;
	}

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;

	}

	double Canister::capacity() const {

		double radius = m_diameter / 2.0;
		double capacity = PI * radius * radius * m_height;
		return capacity;
	}

	double Canister::volume() const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) 
		{
			m_usable = false;
		}
		else if(isEmpty())
		{
			setName(contentName);
		}
		else if (!hasSameContent(contentName))
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0)
		{

			if ((quantity + volume()) <= capacity())
			{
				m_contentVolume += quantity;
			}
			else
			{
				m_usable = false;
			}
		
		}
		else
		{
			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);

		if (C.m_contentVolume > this->capacity() - this->volume())
		{
			C.m_contentVolume = C.m_contentVolume - (this->capacity() - this->volume());
			this->m_contentVolume = this->capacity();
		}
		else
		{
			pour(C.volume());
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	std::ostream& Canister::display()const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable)
		{
			cout << " of Unusable content, discard!";
		}
		else
		{
			if (m_contentName)
			{
				cout << " of ";
				cout.width(7);
				cout << volume() << "cc   " << m_contentName;
			}

		}
		return cout;
	}

}