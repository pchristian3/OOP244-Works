#include"Shape.h"

using namespace std;

namespace sdds {
	
	std::ostream& operator<<(::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& shape){
		shape.getSpecs(istr);
		return istr;
	}
}