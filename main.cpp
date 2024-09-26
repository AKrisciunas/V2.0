#include "Mylib.h"
#include "Stud.h"
#include <iostream>

int main()
{
    vector<Stud> V1;
    char temp, choice1, choice2;
    int n;
    cout<<"Randomly generate students homework and exam point? No - (0) / Yes - (1): ";
    cin>>choice1;
    cout<<"Use average - (0) or median - (1) for result calculation: ";
    cin>>choice2;
    cout<<"How much homework results per student: \n";
    cin>>n;

    char end;
    Stud S;
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
    
    if(choice2 == '1')    
        output(V1, "Med.");
    else 
        output(V1, "Vid.");
    
    cout<<"type anything to exit...";
    cin >> temp;        //pause terminal

    return 0;   
}
