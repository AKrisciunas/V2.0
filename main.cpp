#include "Mylib.h"
#include "Stud.h"
#include "FileIO.h"
#include <iostream>

int main()
{
    vector<Stud> V1;
    char temp, choice1, choice2, choice3;
    int n;
    cout<<"(0) - Input information yourself \n(1) - Generate random homework and exam points \n(2) - Read data from file \n(3) - Generate random data to file\n: ";
    cin>>choice1;
    cout<<"Use average - (0) or median - (1) for result calculation: ";
    cin>>choice2;
    string calculationMethod = "Vid.";
    if(choice2 == '1')  calculationMethod = "Med.";

    //If reading data from file, program will find the number of homework results automatically
    if(choice1 != '2'){
        try
        {
            cout<<"How much homework results per student: ";
            cin>>n;    
            if (n==0)
                throw;
        }
        catch(const std::exception& e)
        {
            return 0;
        }
    }

    char end;
    Stud S;
    string fileName;
    if(choice1 == '2'){
        cout<<"Write file directory: ";
        cin>>fileName;
        readFile(V1, fileName);
    }
    else if(choice1 == '3'){
        //add outputFile();
    }
    else{
        while (true)
        {
            if(choice1 == '1')
                inputRandom(S, n);
            else 
                input(S, n);
            V1.push_back(S);  
            empty(S); 
            cout<<"Type (0) if you wish to stop, type (1) to continue: ";
            cin>>end;
            if(end == '0'){
                break;
            } 
        }
        output(V1, calculationMethod);
    }
    cout<<"type anything to exit...";
    cin >> temp;        //pause terminal

    return 0;   
}
