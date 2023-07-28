#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
	
	const char* LblShape::label()const {
		return m_label;
	}

	LblShape::LblShape(const char* cstring) {
		if (cstring)
		{
			m_label = new char[strlen(cstring) + 1];
			strcpy(m_label, cstring);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& istr) {
		char str[1024] = {};
		istr.getline(str, 1023, ',');
		delete[] m_label;
		m_label = new char[strlen(str) + 1];
		strcpy(m_label, str);
	}

}