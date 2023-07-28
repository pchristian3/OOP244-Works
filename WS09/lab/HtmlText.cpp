#include "HtmlText.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
		if (title) {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
		if (other.m_title) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& other) {
		if (this != &other) {
			Text::operator=(other);
			delete[] m_title;
			m_title = nullptr;
			if (other.m_title) {
				m_title = new char[strLen(other.m_title) + 1];
				strCpy(m_title, other.m_title);
			}
		}
		return *this;
	}
	
	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}
	void HtmlText::write(std::ostream& os) const
	{
		int i = 0;
		bool ms = false;
		os << "<html><head><title>";
		m_title ? os << m_title : os << "No Title";
		os << "</title></head>\n<body>\n";
		if (m_title) os << "<h1>" << m_title << "</h1>\n";
		while ((*this)[i])
		{
			if ((*this)[i] == ' ')
			{
				if (ms) os << "&nbsp;";
				else {
					ms = true;
					os << ' ';
				}
			}
			else if ((*this)[i] == '<')
			{
				os << "&lt;";
				ms = false;
			}
			else if ((*this)[i] == '>')
			{
				os << "&gt;";
				ms = false;
			}
			else if ((*this)[i] == '\n')
			{
				os << "<br />\n";
				ms = false;
			}
			else
			{
				ms = false;
				os << (*this)[i];
			}
			i++;
		}
		os << "</body>\n</html>";
	}
}