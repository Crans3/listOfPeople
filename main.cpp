#include <iostream>
#include <conio.h>
#include "Person.h"
using namespace std;

int main(){
    Person listOfPeople[100];
    char input;
    bool hasToLoop = true;
    int i = 0;
    
    cout << "\t   >>>> MENU <<<<\n";
    listOfPeople->visMenu();
    while(hasToLoop){
        listOfPeople->bubbleSort(listOfPeople, i);
        cout << "\nInsert an option: ";
        input = getch();
        cout << "\n";
        i = listOfPeople->choiceOption(input, hasToLoop, listOfPeople, i);
        i++;
    }

    return 0;
}