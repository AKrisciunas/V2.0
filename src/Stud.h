#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

extern int globalND; //global variable for students homework count

class Person {
protected:
    string name_;
    string surname_;

public:
    Person() : name_(""), surname_("") {}

    Person(const string& name, const string& surname)
        : name_(name), surname_(surname) {}
    virtual ~Person() = default;
    virtual void print() const = 0;

    void setName(const std::string& name) { name_ = name; }
    void setSurname(const std::string& surname) { surname_ = surname; }

    inline string name() const { return name_; }
    inline string surname() const { return surname_; }
};

class Stud : public Person {
private:
    std::vector<int> nd_;
    int egz_;
public:
    // default constructor
    Stud(): Person(), nd_({}), egz_(0) {}

    // constructor
    Stud(const string& name, const string& surname, const std::vector<int>& nd, int egz)
        : Person(name, surname), nd_(nd), egz_(egz) {}

    // Copy constructor
    Stud(const Stud& other) : Person(other.name_, other.surname_), nd_(other.nd_), egz_(other.egz_) {}

    // copy assignment operator
    Stud& operator=(const Stud& other) {    
        if (this != &other) return *this;
        name_ = other.name_;
        surname_ = other.surname_;
        nd_ = other.nd_;
        egz_ = other.egz_;
        return *this;
    }

    // destructor
    ~Stud() {
        nd_.clear();
    }
    
    // getters
    std::vector<int>& nd() { return nd_; }
    double egz() { return egz_; }
    // setters
    void setName(string name) {
        name_ = name;
    }
    void setSurname(string surname) {
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
        os << std::left << std::setw(20) << &stud << std::setw(15) << stud.name_ << std::setw(15) << stud.surname_;
        // for (int i : stud.nd_) {
        //     os << i << " ";
        // }
        // os << ", EGZ: " << stud.egz_;
        return os;
    }
    void print() const override{cout << *this;}
};

void inputRandom(Stud &Local, int n);
double averageResult(std::vector<int> nd, int egz);
double medianResult(std::vector<int> nd, int egz);
bool compareStud(Stud &a, Stud &b);
bool compareStudSurname(Stud &a, Stud &b);
bool compareStudAverage(Stud &a, Stud &b);
bool compareStudMedian(Stud &a, Stud &b);
bool averageAt5(Stud &a);
bool medianAt5(Stud &a);

#endif

