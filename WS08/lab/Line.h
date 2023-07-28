#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {
	
	class Line : public LblShape {
		private:
			int m_length;

		public:
			Line();
			Line(const char* cstring, int length);
			void getSpecs(std::istream& istr);
			void draw(std::ostream& ostr)const;
	};


}

#endif 