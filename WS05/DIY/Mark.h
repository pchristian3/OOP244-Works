#ifndef SDDS_MARK_H_

using namespace std;
namespace sdds {
	class Mark {
		int m_grade;
		void setEmpty();
	public:
		Mark();
		Mark(int grd);
		operator bool() const;
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator +=(int gradeAdd);
		Mark& operator =(int gradeSet);
	};

	int& operator +=(int& value, Mark& marked);

}
#define SDDS_MARK_H_
#endif // !SDDS_MARK_H_

