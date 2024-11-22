#include "Stud.h"
#include "Mylib.h"
#include "timer.h"

bool inputInteger(int &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear(); // Clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true; 
}

void input(Stud &Local, int n){
    int temp;
    for (int i = 0; i < n; i++)
    {
        while (true) {
            cout << "Homework " << (i + 1) << ": "; 
            if (inputInteger(temp)) { // Function checks if temp is an integer
                Local.nd.push_back(temp); 
                break;
            } else {
                cout << "Invalid input. Please enter a number.\n"; 
            }
        }
    }
    cout << "Exam: ";
    while (true) {
        if (inputInteger(temp)) {
            Local.egz = temp; 
            break;
        } else {
            cout << "Invalid input. Please enter a number.\n"; 
        }
    }
    
}

void inputRandom(Stud &Local, int n){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);

    for (int i = 0; i < n; i++)
        Local.nd.push_back(static_cast<int>(dist10(rng)));
    Local.egz = static_cast<int>(dist10(rng));
}

void empty(Stud &Local){
    Local.name.clear();
    Local.surname.clear();
    Local.nd.clear();
}

double averageResult(vector<int> nd, int egz){
    double sum=0;
    for (auto &i : nd)
        sum+=i;
    return sum/ static_cast<double>(nd.size())*0.4+egz*0.6;
}

double medianResult(vector<int> nd, int egz){
    std::sort(nd.begin(), nd.end());
    auto n = nd.size();
    if (n % 2 == 0) 
        return (double) ((nd[n / 2 - 1] + nd[n / 2]) / 2)*0.4+egz*0.6;
    else return (double) nd[n / 2]*0.4+egz*0.6;
}

bool compareStud(Stud &a, Stud &b){
    if(a.name != b.name)
        return a.name < b.name;
    else
        return a.surname < b.surname;
}   

bool compareStudSurname(Stud &a, Stud &b){
    return a.surname < b.surname;
}

bool compareStudAverage(Stud &a, Stud &b){
    return averageResult(a.nd, a.egz) < averageResult(b.nd, b.egz);
}   
bool compareStudMedian(Stud &a, Stud &b){
    return medianResult(a.nd, a.egz) < medianResult(b.nd, b.egz);
}   
bool averageAt5(Stud &a) {return averageResult(a.nd, a.egz) >= 5.0;}

bool medianAt5(Stud &a) {return medianResult(a.nd, a.egz) >= 5.0;}
