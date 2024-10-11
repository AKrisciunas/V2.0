#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include "Mylib.h"
#include "Stud.h"

void readFile(vector<Stud> &S, string fileName);
void writeFile(vector<Stud> V, string fileName, int countND);

#endif