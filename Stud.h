#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

extern int globalND; //global variable for students homework count

struct Stud
{
    string name, surname;
    vector<int> nd;
    int egz;
};

void input(Stud &Local, int n);
void inputRandom(Stud &Local, int n);
void empty(Stud &Local);
double averageResult(vector<int> nd, int egz);
double medianResult(vector<int> nd, int egz);
bool compareStud(Stud &a, Stud &b);
bool compareStudAverage(Stud &a, Stud &b);
bool compareStudMedian(Stud &a, Stud &b);
bool averageAt5(Stud &a);
bool medianAt5(Stud &a);

#endif