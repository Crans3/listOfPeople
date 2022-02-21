#include <iostream>
#include "Person.h"
using namespace std;

Person Person::insPerson(Person person){
    // cin.ignore() on other Function make this work
    cout << "\nInsert the name of the Person: ";
    getline(cin, person.name);
    cout << "Insert the surname of the Person: ";
    getline(cin, person.surname);

    return person;
}

Person Person::removePerson(Person person){
    person.name = "";
    person.surname = "";

    cout << "\nRemoved Person\n";
    cin.ignore();

    return person;
}

void Person::viewPerson(Person person){
    if(person.name != "" || person.surname != ""){
        cout << "\nName: " << person.name << "\n";
        cout << "Surname: " << person.surname << "\n";
    } else{
        cout << "\nYou didn't insert a Person in that place\n";
    }

    cin.ignore();
}

void Person::viewList(Person person[], int size){
    if(size != 0){
        cout << "\nList in alphabetical order\n";
        for(int i=0; i<size; i++){
            if(person[i].name == "" && person[i].surname == ""){
                continue;
            }
            cout << i+1 << ": " << person[i].name << " " << person[i].surname << "\n";
        }
    } else{
        cout << "\nThe list is empty\n";
    }
}

void Person::removeList(Person person[], int size){
    for(int i=0; i<size; i++){
        person[i].name = "";
        person[i].surname = "";
    }
    cout << "\nList Cleared\n";
}

int Person::selectPerson(){
    int i;

    cout << "\nInsert the number of the person: ";
    cin >> i;

    return i-1;
}

void Person::bubbleSort(Person listOfPeople[], int size){
    for(int i=0; i<size-1; i++){
        for (int j=0; j<size-1; j++){
            string tempName;
            string tempSurname;

            if(listOfPeople[j].name > listOfPeople[j+1].name || listOfPeople[j].surname > listOfPeople[j+1].surname || listOfPeople[j].name == listOfPeople[j+1].name || listOfPeople[j].name == ""){
                // temps become the current name and surname
                tempName = listOfPeople[j].name;
                tempSurname = listOfPeople[j].surname;
                // the current name and surname go on the next spot
                listOfPeople[j].name = listOfPeople[j+1].name;
                listOfPeople[j].surname = listOfPeople[j+1].surname;
                // the next name and surname go on the current spot
                listOfPeople[j+1].name = tempName;
                listOfPeople[j+1].surname = tempSurname;
            }
        }
    }
}

void Person::visMenu(){
    cout << "\n\t0: Show this menu\n";
    cout << "\t1: Insert a Person\n";
    cout << "\t2: Remove a Person\n";
    cout << "\t3: View a Person\n";
    cout << "\t4: View the List\n";
    cout << "\t5: Clear the List\n";
    cout << "\t6: Quit\n";
}

int Person::choiceOption(char input, bool &hasToLoop, Person listOfPeople[], int i){
    hasToLoop = true;
    int temp;

    switch(input){
        case '0':
            listOfPeople->visMenu();
            return i-1;
        case '1':
            listOfPeople[i] = listOfPeople->insPerson(listOfPeople[i]);
            break;
        case '2':
            temp = i-1;
            i = listOfPeople->selectPerson();
            listOfPeople[i] = listOfPeople->removePerson(listOfPeople[i]);
            i = temp;
            break;
        case '3':
            temp = i-1;
            i = listOfPeople->selectPerson();
            listOfPeople->viewPerson(listOfPeople[i]);
            i = temp;
            break;
        case '4':
            listOfPeople->viewList(listOfPeople, i);
            i--;
            break;
        case '5':
            listOfPeople->removeList(listOfPeople, i);
            i=-1;
            break;
        case '6':
            hasToLoop = false;
            break;
        default:
            return i-1;
    }

    return i;
}