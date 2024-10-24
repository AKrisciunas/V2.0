#include "Mylib.h"
#include "Stud.h"
#include <iostream>

int main()
{
    char temp;
    cout<< "Do you want to use: (0) - VECTOR or (1) - test speed with LIST type student container: ";
    cin >> temp;
    if (temp == '1')    userInterfaceList();
    else    userInterface();
    
    cout<<"type anything to exit...";
    cin >> temp;

    return 0;   
}
