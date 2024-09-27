#include "Mylib.h"
#include "Stud.h"
#include <fstream>

void readFile(vector<Stud> &Vec, string fileName){
    try {
        std::ifstream input(fileName);

        if (!input.is_open()) {
            throw std::runtime_error("Failed to open file");
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
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
