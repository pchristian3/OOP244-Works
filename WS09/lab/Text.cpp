#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
using namespace sdds;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index) const
    {
        return m_content[index];
    }

    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr)
    {
        if (filename)
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }

    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr)
    {
        operator=(other);
    }

    Text& Text::operator=(const Text& other)
    {
        if (this != &other)
        {
            delete[] m_filename;
            delete[] m_content;
            m_filename = new char[strLen(other.m_filename) + 1];
            strCpy(m_filename, other.m_filename);
            m_content = new char[strLen(other.m_content) + 1];
            strCpy(m_content, other.m_content);
        }
        return *this;
    }

    Text::~Text()
    {
        delete[] m_filename;
        delete[] m_content;
    }

    void Text::read()
    {
        ifstream fin(m_filename);
        int size = getFileLength() + 1;
        m_content = new char[size];
        fin.getline(m_content, size, -1);
    }

    void Text::write(ostream& os) const
    {
        os << m_content;
    }

    ostream& operator<<(ostream& os, const Text& text)
    {
        text.write(os);
        return os;
    }

}