#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>

namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& other);
        Text& operator=(const Text& other);
        virtual ~Text();
        void read();
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__