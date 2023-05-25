#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   //TODO: read functions go here    
 
   bool read(char* name) 
   {
       return (name != nullptr && fptr != nullptr) ? fscanf(fptr, "%[^\n]\n", name) == 1 : false;
   }

   bool read(int& number) 
   {
       return (fptr != nullptr) ? fscanf(fptr, "%d,", &number) == 1 : false;
   }


 
   bool read(double& salary) 
   {
       return (fptr != nullptr) ? fscanf(fptr, "%lf,", &salary) == 1 : false;
   }

}