#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
   void strnCpy(char* des, const char* src, int len);
   //1. function defination of strCpy function which has two parameters.
   void strCpy(char* des, const char* src);

   //2. function defination of strnCpy function which has three parameters.
   void strnCpy(char* des, const char* src, int len);

   //3. function defination of strCmp function which has two parameters.
   int strCmp(const char* s1, const char* s2);

   //4. function defination of strnCmp function which has three parameters.
   int strnCmp(const char* s1, const char* s2, int len);

   //5. function defination of strLen function which has one parameters.
   int strLen(const char* s);

   //6. function defination of strstr function which has two parameters.
   const char* strStr(const char* str1, const char* str2);

   //7.function defination of strCat function which has two parameters.
   void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_



