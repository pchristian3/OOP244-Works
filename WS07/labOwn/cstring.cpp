#include "cstring.h"
namespace sdds {

	void strCpy(char* des, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}

		des[i] = '\0';
		return;
	}


	void strnCpy(char* des, const char* src, int len)
	{
		int i = 0;
		while (i < len)
		{
			des[i] = src[i];
			i++;
		}
		return;
	}


	int strCmp(const char* s1, const char* s2)
	{
		int i = 0, valuereturn;
		bool stop = false;

		while (s1[i] == s2[i] && !stop)
		{
			if (s1[i] == '\0' || s2[i] == '\0')
			{
				stop = true;
			}
			i++;
		}

		if (s1[i] == '\0' && s2[i] == '\0')
		{
			valuereturn = 0;
		}
		else
		{
			valuereturn = 1;
		}

		return valuereturn;
	}



	int strnCmp(const char* s1, const char* s2, int len)
	{

		int i = 0, valuereturn;
		bool stop = false;
		while (s1[i] == s2[i] && i < len && !stop)
		{

			if (s1[i] == '\0' || s2[i] == '\0')
			{
				stop = true;
			}
			i++;
		}

		if ((s1[i] == '\0' && s2[i] == '\0') || s2[i] == s2[len])
		{
			valuereturn = 0;
		}
		else
		{
			valuereturn = 1;
		}
		return valuereturn;
	}


	int strLen(const char* s)
	{
		int i = 0;

		while (*s != '\0')
		{
			i++;
			s++;
		}

		return i;
	}


	const char* strStr(const char* str1, const char* str2)
	{

		if (*str2 == '\0')
		{
			return  str1;
		}

		for (int i = 0; i < strLen(str1); i++)
		{
			if (*(str1 + i) == *str2)
			{
				const char* ptr = strStr(str1 + i + 1, str2 + 1);
				return (ptr) ? ptr - 1 : nullptr;
			}
		}

		return nullptr;
	}


	void strCat(char* des, const char* src) {
		int i = 0, j = 0;

		while (des[i] != '\0')
		{
			i++;
		}

		while (src[j] != '\0')
		{
			des[i] = src[j];
			j++;
			i++;
		}
		des[i] = '\0';

		return;
	}
}