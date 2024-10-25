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

void userInterface();
void userInterfaceList();
void input(Stud &Local, int n);
void inputRandom(Stud &Local, int n);
void output(vector<Stud> &vec, string method);
void outputList(list<Stud> &vec, string method);
void empty(Stud &Local);
double averageResult(vector<int> nd, int egz);
double medianResult(vector<int> nd, int egz);
bool compareStud(Stud &a, Stud &b);
void splitFile(vector<Stud> &vec, string method, int size, char sortName);
void splitFileList(list<Stud> &vec, string method, int size, char sortName);

#endif