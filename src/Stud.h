#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

extern int globalND; //global variable for students homework count

class Stud {
private:
    string name_;
    string surname_;
    vector<int> nd_;
    int egz_;
public:
    // default constructor
    Stud(): name_(""), surname_(""), nd_({}), egz_(0) {}

    // constructor
    Stud(const std::string& name, const std::string& surname, const std::vector<int>& nd, int egz)
        : name_(name), surname_(surname), nd_(nd), egz_(egz) {}

    // copy assignment operator
    Stud& operator=(const Stud& other) {    
        if (this != &other) {
            name_ = other.name_;
            surname_ = other.surname_;
            nd_ = other.nd_;
            egz_ = other.egz_;
        }
        return *this;
    }

    // destructor
    ~Stud() {
        nd_.clear();
    }
    
    // getters
    string& name() { return name_; }
    string& surname() { return surname_; }
    vector<int>& nd() { return nd_; }
    double egz() { return egz_; }
    // setters
    void setName(std::string name) {
        name_ = name;
    }
    void setSurname(std::string surname) {
        surname_ = surname;
    }
    void setNd(std::vector<int> nd) {
        nd_ = nd;
    }
    void setEgz(int egz) {
        egz_ = egz;
    }
    // operators
    friend std::istream& operator>>(std::istream& is, Stud& stud);
    friend std::ostream& operator<<(std::ostream& os, const Stud& stud) {
        os << std::left << setw(20) << &stud << setw(15) << stud.name_ << setw(15) << stud.surname_;
        // for (int i : stud.nd_) {
        //     os << i << " ";
        // }
        // os << ", EGZ: " << stud.egz_;
        return os;
    }
};

void inputRandom(Stud &Local, int n);
double averageResult( vector<int> nd, int egz);
double medianResult( vector<int> nd, int egz);
bool compareStud(Stud &a, Stud &b);
bool compareStudSurname(Stud &a, Stud &b);
bool compareStudAverage(Stud &a, Stud &b);
bool compareStudMedian(Stud &a, Stud &b);
bool averageAt5(Stud &a);
bool medianAt5(Stud &a);

#endif
