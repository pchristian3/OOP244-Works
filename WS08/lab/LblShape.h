#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {

	private:
		char* m_label = nullptr;
		
	protected:
		const char * label() const;
		
	public:
		LblShape(const char* cstring = nullptr);
		~LblShape();
		LblShape(LblShape& I ) = delete;
		LblShape& operator = (LblShape& other) = delete;
		void getSpecs(std::istream& istr);
	};
}


#endif // !SDDS_LBLSHAPE_H_