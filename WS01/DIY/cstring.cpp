#include<iostream>
#include "cstring.h"
//#include <stddef.h>
using namespace std;
using namespace sdds;

namespace sdds 
{
    void strCpy(char* des, const char* src)
    {
        while (*src) 
        {
            *des++ = *src++;
        }
        *des = '\0'; // Null-terminate the destination string
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (*src && i < len)
        {
            *des++ = *src++;
            i++;
        }
        if (i < len) 
        {
            *des = '\0'; // Null-terminate the destination string if characters copied < len
        }
    }

    int strCmp(const char* s1, const char* s2) 
    {
        while (*s1 && *s1 == *s2) 
        {
            s1++;
            s2++;
        }
        return (*s1 - *s2); // Difference between the differing characters
    }

    int strnCmp(const char* s1, const char* s2, int len) 
    {
        int i = 0;
        while (*s1 && *s1 == *s2 && i < len) 
        {
            s1++;
            s2++;
            i++;
        }
        if (i == len) 
        {
            return 0; // Strings are equal within specified length
        }
        return (*s1 - *s2); // Difference between the differing characters
    }

    int strLen(const char* s)
    {
        int length = 0;
        while (*s) 
        {
            length++;
            s++;
        }
        return length;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        if (*str2 == '\0') 
        {
            return str1;  // Empty substring, return the original string
        }
        while (*str1 != '\0') 
        {
            const char* p1 = str1;
            const char* p2 = str2;
            while (*p1 == *p2 && *p2 != '\0')
            {
                p1++;
                p2++;
            }
            if (*p2 == '\0')
            {
                return str1;  // Substring found
            }
            str1++;
        }
        return nullptr;  // Substring not found
    }

    void strCat(char* des, const char* src)
    {
        while (*des) 
        {
            des++;
        }
        while (*src)
        {
            *des++ = *src++;
        }
        *des = '\0'; // Null-terminate the destination string
    }

}


