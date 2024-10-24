#include "Stud.h"
#include "Mylib.h"
#include "FileIO.h"
#include "timer.h"

void userInterface(){
    Stud S;
    vector<Stud> A;
    char choice1, choice2;
    int n;
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
        S.nd.reserve(n);
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
        A.reserve(generateCount);
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
        cout<<"Write file directory: ";
        cin>>fileName;
        cout<<"(0) - to sort new files by result, or (1) - sort by name and surname\n:";
        char sortName = '0';
        cin >> sortName;
        Timer t;
        readFile(A, fileName);
        generateCount = (int) A.size();
        splitFile(A, calculationMethod, generateCount, sortName);
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

void userInterfaceList(){
    Stud S;
    list<Stud> A;
    char choice1, choice2;
    int n;
    cout<<"(0) - Split file into 2, based on results\n(1) - Generate random data to file \n: ";
    cin>>choice1;
    if(choice1 != '1'){
        cout<<"Use average - (0) or median - (1) for result calculation: ";
        cin>>choice2;
    }
    string calculationMethod = "Vid.";
    if(choice2 == '1')  calculationMethod = "Med.";

    //If reading data from file, program will find the number of homework results automatically
    if(choice1 != '0'){
        cout<<"How much homework results per student: ";  
        while(n<=0)
            cin>>n;  
        S.nd.reserve(n);
    }
    string fileName;
    int generateCount;
    if(choice1 == '1'){
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
        writeFileList(A, std::to_string(generateCount)+"studentu.txt", n);
    }
    else{
        cout<<"Write file directory: ";
        cin>>fileName;
        cout<<"(0) - to sort new files by result, or (1) - sort by name and surname\n:";
        char sortName = '0';
        cin >> sortName;
        Timer t;
        readFileList(A, fileName);
        generateCount = (int) A.size();
        splitFileList(A, calculationMethod, generateCount, sortName);
        cout << A.size() << " entries whole test time: " << t.elapsed() << "\n";
    }
}