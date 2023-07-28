#include"Line.h"

using namespace std;

namespace sdds {
	Line::Line() {
		m_length = 0;
	}

	Line::Line(const char* cstring, int length):LblShape(cstring){
		m_length = length;
	}

	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		while (istr.get() != '\n');
	}

	void Line::draw(std::ostream& ostr) const {
		if (m_length > 0 && label()!=nullptr) 
		{
			ostr << label() << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << '=';
		}
	}

}