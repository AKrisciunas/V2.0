#include "Stud.h"
#include "Mylib.h"
#include "FileIO.h"
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
        Local.nd.push_back(dist10(rng));
    Local.egz = dist10(rng);
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
    return sum/nd.size()*0.4+egz*0.6;
}

double medianResult(vector<int> nd, int egz){
    std::sort(nd.begin(), nd.end());
    int n = nd.size();
    if (n % 2 == 0) 
        return ((nd[n / 2 - 1] + nd[n / 2]) / 2)*0.4+egz*0.6;
    else return nd[n / 2]*0.4+egz*0.6;
}

bool compareStud(Stud &a, Stud &b){
    if(a.name != b.name)
        return a.name < b.name;
    else
        return a.surname < b.surname;
}   

void output(vector<Stud> &vec, string method){
    cout << std::left << setw(20) << "Vardas" << setw(20) << "Pavarde" << "Galutinis ("<< method <<")\n";
    cout << "------------------------------------------------------------\n";
    std::sort(vec.begin(), vec.end(), compareStud);
    if(method == "Vid."){
        for (auto &&Stud : vec)
            cout << std::left << setw(20) << Stud.name << setw(20) << Stud.surname 
            << std::fixed << std::setprecision(2) << averageResult(Stud.nd, Stud.egz) <<"\n";
    }
    else{
        for (auto &&Stud : vec)
            cout << std::left << setw(20) << Stud.name << setw(20) << Stud.surname 
            << std::fixed << std::setprecision(2) << medianResult(Stud.nd, Stud.egz) << "\n";
    }
    cout << "------------------------------------------------------------\n";
}

bool compareStudAverage(Stud &a, Stud &b){
    return averageResult(a.nd, a.egz) < averageResult(b.nd, b.egz);
}   
bool compareStudMedian(Stud &a, Stud &b){
    return medianResult(a.nd, a.egz) < medianResult(b.nd, b.egz);
}   
bool averageAt5(Stud &a) {return averageResult(a.nd, a.egz) >= 5.0;}

bool medianAt5(Stud &a) {return medianResult(a.nd, a.egz) >= 5.0;}

void sortToFile(vector<Stud> &vec, string method, int countND, int size){
    Timer t;
    Timer t2;
    writeFile(vec, std::to_string(size)+"studentu.txt", countND);
    cout << size << " entries to file time: " << t.elapsed() << "\n";
    vector<Stud>::iterator iter;
    t.reset();
    if (method == "Med."){
        std::sort(vec.begin(), vec.end(), compareStudMedian);
        iter = std::find_if(vec.begin(), vec.end(), medianAt5);
    } 
    else {
        std::sort(vec.begin(), vec.end(), compareStudAverage);
        iter = std::find_if(vec.begin(), vec.end(), averageAt5);
    }
    cout << size << " entries sorting time: " << t.elapsed() << "\n";

    t.reset();
    vector<Stud> below5(std::distance(vec.begin(), iter));
    vector<Stud> aboveOrEqual5(std::distance(iter, vec.end()));
    below5.assign(vec.begin(), iter);
    aboveOrEqual5.assign(iter, vec.end()); 
    cout << size << " entries splitting into 2, time: " << t.elapsed() << "\n";

    t.reset();
    writeFile(below5, "nelaimingi.txt", countND);
    cout << size << " entries 'nelaimingu' to file time: " << t.elapsed() << "\n";
    t.reset();
    writeFile(aboveOrEqual5, "protingi.txt", countND);
    cout << size << " entries 'protingu' to file time: " << t.elapsed() << "\n";

    cout << size << " entries whole test time: " << t2.elapsed() << "\n";
}