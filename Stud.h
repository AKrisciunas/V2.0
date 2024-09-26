#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

struct Stud
{
    string name, surname;
    vector<int> nd;
    int egz;
};

void input(Stud &Local, int n);
void inputRandom(Stud &Local, int n);
void output(vector<Stud> &vec, string method);
void empty(Stud &Local);
double averageResult(vector<int> nd, int egz);
double medianResult(vector<int> nd, int egz);
bool compareStud(Stud &a, Stud &b);

#endif