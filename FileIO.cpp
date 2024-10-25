#include "Mylib.h"
#include "Stud.h"
#include "timer.h"
#include <fstream>
int globalND=0;

void readFile(vector<Stud> &Vec, string fileName){
    try {
        Timer t;
        std::ifstream input(fileName);

        if (!input.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        string line, column;
        std::getline(input, line);
        std::istringstream header(line);

        //counting columns from first line
        while (header >> column)
            globalND++;
        globalND-=3;    //excludes name surname and exam
        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            Stud S;

            iss >> S.name >> S.surname;

            int temp;
            for (int i = 0; i < globalND; i++) {
                if (iss >> temp) {
                    S.nd.push_back(temp);
                }
            }

            iss >> S.egz;
            Vec.push_back(S);
        }
        input.close();
        cout << "file reading time: " << t.elapsed() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void writeFile(vector<Stud> V, string fileName, int countND) {
    std::ostringstream buffer;
    buffer << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde"; 
    for (int i = 0; i < countND; i++) buffer << std::left << setw(5) << "ND" + std::to_string(i+1);
    buffer << "Egz.\n";    
    for (const auto& stud : V) {
        buffer << setw(15) << stud.name << setw(15) << stud.surname << setw(5);
        for (auto i = 0; i < countND; i++)   buffer << stud.nd.at(std::vector<int>::size_type(i)) << setw(5);   
        buffer << stud.egz << "\n";
    }

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file\n";
        return;
    }
    file << buffer.str();  
    file.close();

}

void readFileList(list<Stud> &Vec, string fileName){
    try {
        Timer t;
        std::ifstream input(fileName);

        if (!input.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        string line, column;
        std::getline(input, line);
        std::istringstream header(line);

        //counting columns from first line
        while (header >> column)
            globalND++;
        globalND-=3;    //excludes name surname and exam
        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            Stud S;

            iss >> S.name >> S.surname;

            int temp;
            for (int i = 0; i < globalND; i++) {
                if (iss >> temp) {
                    S.nd.push_back(temp);
                }
            }

            iss >> S.egz;
            Vec.push_back(S);
        }
        input.close();
        cout << "file reading time: " << t.elapsed() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void writeFileList(list<Stud> V, string fileName, int countND) {
    std::ostringstream buffer;
    buffer << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde"; 
    for (int i = 0; i < countND; i++) buffer << std::left << setw(5) << "ND" + std::to_string(i+1);
    buffer << "Egz.\n";    
    for (const auto& stud : V) {
        buffer << setw(15) << stud.name << setw(15) << stud.surname << setw(5);
        for (auto i = 0; i < countND; i++)   buffer << stud.nd.at(std::vector<int>::size_type(i)) << setw(5);   
        buffer << stud.egz << "\n";
    }

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file\n";
        return;
    }
    file << buffer.str();  
    file.close();

}