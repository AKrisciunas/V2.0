#include "Stud.h"
#include "Mylib.h"
#include "timer.h"

bool inputInteger(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

std::istream& operator>>(std::istream& is, Stud& stud) {
        int temp;
        vector<int> nd;
        cout << "Name: ";
        is >> stud.name_;
        cout << "Surname: ";
        is >> stud.surname_;

        for (int i = 0; i < globalND; ++i) {
            while (true) {
                std::cout << "Homework " << (i + 1) << ": ";
                if (inputInteger(temp)) {
                    nd.push_back(temp);
                    break;
                } else {
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }
            }
        }
        stud.nd_ = nd;

        while (true) {
            std::cout << "Exam: ";
            if (inputInteger(temp)) {
                stud.egz_ = temp;
                break;
            } else {
                std::cout << "Invalid input. Please enter a number." << std::endl;
            }
        }

        return is;
}

void inputRandom(Stud& Local, int n) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);

    std::vector<int> nd;
    for (int i = 0; i < n; i++)
        nd.push_back(static_cast<int>(dist10(rng)));
    Local.setNd(nd);
    Local.setEgz(static_cast<int>(dist10(rng)));
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

bool compareStud(Stud& a, Stud& b) {
    if (a.name() != b.name())
        return a.name() < b.name();
    else
        return a.surname() < b.surname();
}

bool compareStudSurname(Stud& a, Stud& b) {
    return a.surname() < b.surname();
}

bool compareStudAverage(Stud& a, Stud& b) {
    return averageResult(a.nd(), a.egz()) < averageResult(b.nd(), b.egz());
}

bool compareStudMedian(Stud& a, Stud& b) {
    return medianResult(a.nd(), a.egz()) < medianResult(b.nd(), b.egz());
}

bool averageAt5(Stud& a) {
    return averageResult(a.nd(), a.egz()) >= 5.0;
}

bool medianAt5(Stud& a) {
    return medianResult(a.nd(), a.egz()) >= 5.0;
}
