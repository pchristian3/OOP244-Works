#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"

using namespace std;
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

    bool read(char* postCode) {
        return fscanf(fptr, "%3s,", postCode) == 1;
    }

    bool read(int& population) {
        return fscanf(fptr, "%d\n", &population) == 1;
    }

}