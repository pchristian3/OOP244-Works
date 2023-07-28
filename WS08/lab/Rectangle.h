#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		private:
			int m_width;
			int m_height;

		public:
			Rectangle();
			Rectangle(const char* cstring, int width, int height);
			void getSpecs(std::istream& istr);
			void draw(std::ostream& ostr) const;
	};
}
#endif 