/*
Name : Prarthan Dhaval Christian
Id : 175063213
Email : pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}


	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		if (fname)
		{
			if (!isCopy)
			{
				delete[] m_filename;
				m_filename = new char[strLen(fname) + 1];
				strCpy(m_filename, fname);
			}
			else
			{
				delete[] m_filename;
				m_filename = new char[strLen(fname) + 3];
				strCpy(m_filename, "C_");
				strCat(m_filename, fname);
			}
		}
	}

	void TextFile::setNoOfLines()
	{
		ifstream istr(m_filename);
		m_noOfLines = 0;
		char ch;
		bool isEmpty = true;

		while ((ch = istr.get()) != -1)
		{
			if (isEmpty) isEmpty = false;
			if (ch == '\n') m_noOfLines++;
		}

		if (!isEmpty) m_noOfLines++;
		else setEmpty();
	}

	void TextFile::loadText()
	{
		if (m_filename)
		{
			int i = 0;
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];
			ifstream istr(m_filename);
			string str;
			for (i = 0; getline(istr, str, '\n'); i++)
			{
				m_textLines[i] = str.c_str();
			}
			m_noOfLines = i;
		}
	}

	void TextFile::saveAs(const char* fileName) const
	{
		if (fileName)
		{
			ofstream ostr(fileName);
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				ostr << m_textLines[i] << endl;
			}
		}
	}

	void TextFile::setEmpty()
	{
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(unsigned pageSize) :m_textLines(nullptr), m_filename(nullptr)
	{
		setEmpty();
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) :m_textLines(nullptr), m_filename(nullptr)
	{
		setEmpty();
		m_pageSize = pageSize;
		setFilename(filename);
		setNoOfLines();
		loadText();

	}

	TextFile::TextFile(const TextFile& other) :m_textLines(nullptr), m_filename(nullptr)
	{
		setEmpty();
		m_pageSize = other.m_pageSize;
		if (other)
		{
			setFilename(other.m_filename, true);
			other.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}

	}

	TextFile& TextFile::operator=(const TextFile& other)
	{
		if (this != &other && *this && other)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			other.saveAs(m_filename);
			setNoOfLines();
			loadText();

		}
		return *this;
	}

	TextFile::~TextFile()
	{
		delete[] m_textLines;
		delete[] m_filename;
	}

	std::ostream& TextFile::view(std::ostream& ostr) const
	{
		if (*this)
		{
			ostr << m_filename << endl;
			ostr.width(strLen(m_filename));
			ostr.fill('=');
			ostr << '=';
			ostr << endl;
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				if (i != 0 && i % m_pageSize == 0)
				{
					ostr << "Hit ENTER to continue...";
					while (cin.get() != '\n');
				}
				ostr << m_textLines[i] << endl;
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string filename;
		getline(istr, filename, '\n');
		delete[] m_filename;
		setFilename(filename.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	TextFile::operator bool() const
	{
		return !(m_textLines == nullptr && m_filename == nullptr && m_noOfLines == 0);

	}

	unsigned TextFile::lines() const
	{
		return m_noOfLines;
	}

	const char* TextFile::name() const
	{
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index) const
	{
		if (m_filename != nullptr && m_filename[0] != '\0') {
			if (index >= m_noOfLines)
				index -= m_noOfLines;
		}

		return m_textLines[index].m_value;
	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
	{
		text.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		text.getFile(istr);

		return istr;
	}

}