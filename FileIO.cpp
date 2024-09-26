#include "Mylib.h"
#include "Stud.h"
#include <fstream>

void readFile(vector<Stud> &Vec){
    std::ifstream input("kursiokai.txt");

    if (!input.is_open())
    {
        std::cerr << "Failed to open file\n";
        return;
    }

    string line, column;
    int countND=0;
    std::getline(input, line);
    std::istringstream header(line);

    //counting columns from first line
    while (header >> column)
        countND++;

    while (std::getline(input, line))
    {
        std::istringstream iss(line);
        Stud S;

        iss >> S.name >> S.surname;

        int temp;
        for (int i = 0; i < countND-3; i++) {
            if (iss >> temp) {
                S.nd.push_back(temp);
            }
        }

        iss >> S.egz;
        Vec.push_back(S);
    }
}
