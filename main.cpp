#include "Stud.h"
#include "Mylib.h"
#include "timer.h"
#include <fstream>
int globalND=0;


template<typename Container>
void sortContainer(Container& A, char sortType, string method) {
    if (sortType == '0') {
        if (method == "Vid.") {
            if constexpr (std::is_same_v<Container, std::vector<Stud>>) {
                std::sort(A.begin(), A.end(), [](const Stud& a, const Stud& b) {
                    return averageResult(a.nd, a.egz) < averageResult(b.nd, b.egz);
                });
            } else if constexpr (std::is_same_v<Container, std::list<Stud>>) {
                A.sort([](const Stud& a, const Stud& b) {
                    return averageResult(a.nd, a.egz) < averageResult(b.nd, b.egz);
                });
            }
        } else if (method == "Med.") {
            if constexpr (std::is_same_v<Container, std::vector<Stud>>) {
                std::sort(A.begin(), A.end(), [](const Stud& a, const Stud& b) {
                    return medianResult(a.nd, a.egz) < medianResult(b.nd, b.egz);
                });
            } else if constexpr (std::is_same_v<Container, std::list<Stud>>) {
                A.sort([](const Stud& a, const Stud& b) {
                    return medianResult(a.nd, a.egz) < medianResult(b.nd, b.egz);
                });
            }
        }
    } else if (sortType == '1') {
        if constexpr (std::is_same_v<Container, std::vector<Stud>>) {
            std::sort(A.begin(), A.end(), compareStud);
        } else if constexpr (std::is_same_v<Container, std::list<Stud>>) {
            A.sort(compareStud);
        }
    } else if (sortType == '2') {
        if constexpr (std::is_same_v<Container, std::vector<Stud>>) {
            std::sort(A.begin(), A.end(), compareStudSurname);
        } else if constexpr (std::is_same_v<Container, std::list<Stud>>) {
            A.sort(compareStudSurname);
        }
    }
}

template<typename Container>
void readFile(Container& A, string fileName){
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
            A.push_back(S);
        }
        input.close();
        cout << "file reading time: " << t.elapsed() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

template<typename Container>
void writeFile(Container& A, string fileName, int countND) {
    std::ostringstream buffer;
    buffer << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde"; 
    for (int i = 0; i < countND; i++) buffer << std::left << setw(5) << "ND" + std::to_string(i+1);
    buffer << "Egz.\n";    
    for (const auto& stud : A) {
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

template<typename Container>
void output(Container &A, string method){
    cout << std::left << setw(20) << "Adresas" <<setw(15) << "Vardas" << setw(15) << "Pavarde" << "Galutinis ("<< method <<")\n";
    cout << "-----------------------------------------------------------------\n";
    if constexpr (std::is_same_v<Container, std::vector<Stud>>){
        std::sort(A.begin(), A.end(), compareStud);
    }
    else if constexpr (std::is_same_v<Container, std::list<Stud>>){
        A.sort(compareStud);
    }
    if(method == "Vid."){
        for (auto &&Stud : A)
            cout << std::left << setw(20) << &Stud << setw(15) << Stud.name << setw(15) << Stud.surname 
            << std::fixed << std::setprecision(2) << averageResult(Stud.nd, Stud.egz) <<"\n";
    }
    else{
        for (auto &&Stud : A)
            cout << std::left << setw(20) << &Stud << setw(15) << Stud.name << setw(15) << Stud.surname 
            << std::fixed << std::setprecision(2) << medianResult(Stud.nd, Stud.egz) << "\n";
    }
    cout << "-----------------------------------------------------------------\n";
}

template<typename Container>
void splitFileStrat1(Container& A, Container& kietiakai, Container& vargsiukai, string method, char sortType){
    Timer t;
    if(method == "Vid."){
        for (const auto& stud : A) {
            if (averageResult(stud.nd, stud.egz) < 5.0) {
                vargsiukai.push_back(stud);
            }
            else {
                kietiakai.push_back(stud);
            }
        }
    }
    else{
        for (const auto& stud : A) {
            if (medianResult(stud.nd, stud.egz) < 5.0) {
                vargsiukai.push_back(stud);
            }
            else {
                kietiakai.push_back(stud);
            }
        }
    }
    sortContainer(vargsiukai, sortType, method);
    sortContainer(kietiakai, sortType, method);
    writeFile(vargsiukai, "nelaimingi.txt", globalND);
    writeFile(kietiakai, "protingi.txt", globalND);
    cout << "Splitting into 2 groups time: " << t.elapsed() << "\n";
}

template<typename Container>
void splitFile(Container& A, string method, int size, char sortType){
    Timer t;
    Timer t1;
    auto iter = A.begin();
    sortContainer(A, '0', method);
    if (method == "Med.") {
        iter = std::find_if(A.begin(), A.end(), medianAt5);
    } else {
        iter = std::find_if(A.begin(), A.end(), averageAt5);
    }
    cout << size << " entries sorting and finding the split point time: " << t.elapsed() << "\n";

    t.reset();
    Container below5(A.begin(), iter);
    Container aboveOrEqual5(iter, A.end());
    if constexpr (std::is_same_v<Container, std::vector<Stud>>){
        std::copy(A.begin(), iter, std::back_inserter(below5));
        std::copy(iter, A.end(), std::back_inserter(aboveOrEqual5));
    }
    else if constexpr (std::is_same_v<Container, std::list<Stud>>){
        below5.splice(below5.begin(), A, A.begin(), iter);
        aboveOrEqual5.splice(aboveOrEqual5.begin(), A, iter, A.end());
    }
    if (sortType != '0')
    {    
        sortContainer(below5, sortType, method);
        sortContainer(aboveOrEqual5, sortType, method);
    }
    cout << size << " entries splitting into 2, time: " << t.elapsed() << "\n";
    cout << "separation into 2 groups time: " << t1.elapsed() << "\n-----\n";
    t1.reset();
    t.reset();
    writeFile(below5, "nelaimingi.txt", globalND);
    writeFile(aboveOrEqual5, "protingi.txt", globalND);
    cout << size << " entries 'nelaimingu' to file time: " << t.elapsed() << "\n";
    t.reset();
    cout << size << " entries 'protingu' to file time: " << t.elapsed() << "\n";
    cout << "both groups to files time: " << t1.elapsed() << "\n-----\n";
}

template<typename Container>
void userInterface(Container& A){
    Stud S;
    char choice1, choice2;
    int n=0;
    cout<<"(0) - Input information yourself \n(1) - Generate random homework and exam points \n(2) - Read data from file\n" 
    << "(3) - Generate random data to file \n(4) - Split file into 2, based on results\n: ";
    cin>>choice1;
    if(choice1 != '3'){
        cout<<"Use average - (0) or median - (1) for result calculation: ";
        cin>>choice2;
    }
    string calculationMethod = "Vid.";
    if(choice2 == '1')  calculationMethod = "Med.";

    //If reading data from file, program will find the number of homework results automatically
    if(choice1 != '2' && choice1 != '4'){
        cout<<"How much homework results per student: ";  
        while(n<=0)
            cin>>n;  
    }
    string fileName;
    int generateCount;
    if(choice1 == '2'){
        cout<<"Write file directory: ";
        cin>>fileName;
        readFile(A, fileName);
        output(A, calculationMethod);
    }
    else if(choice1 == '3'){
        cout<<"How much students to generate: ";
        cin>>generateCount;
        for (int i = 0; i < generateCount; i++)
        {
           S.name = "Vardas" + std::to_string(i+1);
           S.surname = "Pavarde" + std::to_string(i+1);
           inputRandom(S, n);
           A.push_back(S);
           empty(S);
        }
        writeFile(A, std::to_string(generateCount)+"studentu.txt", n);
    }
    else if(choice1 == '4'){
        int strategy = 1;
        cout<<"Which strategy to use (1,2,3): \n1 - Looping through all students and splitting into 2\n"
        << "\n 2 - Finding the split point and splitting into 2";
        cin>>strategy;
        cout<<"Write file directory: ";
        cin>>fileName;
        cout<<"(0) - to sort new files by result, (1) - sort by name and surname or (2) - sort only surname\n:";
        char sortType = '0';
        cin >> sortType;
        Timer t;
        readFile(A, fileName);
        generateCount = (int) A.size();
        if(strategy == 1){
            Container kietiakai;
            Container vargsiukai;
            splitFileStrat1(A, kietiakai, vargsiukai, calculationMethod, sortType);
        }else if (strategy == 2)
        {
            splitFile(A, calculationMethod, generateCount, sortType);
        }else{
            
        }
        cout << A.size() << " entries whole test time: " << t.elapsed() << "\n";
    }
    else{
        char end;
        while (true){
            cout<<"Input Name: ";
            cin >> S.name;
            cout <<"Surname: ";
            cin >> S.surname;
            if(choice1 == '1')
                inputRandom(S, n);
            else 
                input(S, n);
            A.push_back(S);  
            empty(S); 
            cout<<"Type (0) if you wish to stop, type (1) to continue: ";
            cin>>end;
            if(end == '0'){
                break;
            } 
        }
        output(A, calculationMethod);
    }
}

int main()
{
    char temp;
    cout<< "Do you want to use: (0) - VECTOR or (1) - test speed with LIST type student container: ";
    cin >> temp;
    if (temp == '1'){
        list<Stud> studList;
        userInterface(studList);
    }
    else{
        vector<Stud> studVector;
        userInterface(studVector);
    }
    cout<<"type anything to exit...";
    cin >> temp;

    return 0;   
}

