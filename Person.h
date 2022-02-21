#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>

class Person{
public:
    std::string name;
    std::string surname;
    
    Person insPerson(Person person);
    Person removePerson(Person person);
    void viewPerson(Person person);
    void viewList(Person person[], int size);
    void removeList(Person person[], int size);
    int selectPerson();
    void bubbleSort(Person listaPersone[], int size);
    void visMenu();
    int choiceOption(char input, bool &hasToLoop, Person listOfPeople[], int i);
};

#endif