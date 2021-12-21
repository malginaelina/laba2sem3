#ifndef LABA2SEM3_INTERFACE_H
#define LABA2SEM3_INTERFACE_H
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "SparceVector.h"
#include "Histogram.h"
#include "AlphabetIndex.h"
#include <iostream>
#include <string>

Person enterPerson()
{
    string a;
    string b;
    string c;
    int d = 0;
    cout << "First name: ";
    cin >> a;
    cout << endl;
    cout << "Middle name: ";
    cin >> b;
    cout << endl;
    cout << "Last name:";
    cin >> c;
    cout << endl;
    cout << "Birth year: ";
    cin >> d;
    cout << endl;
    return Person(a, b, c, d);
}

void interface() {
    int switcher = 1;
    while (switcher) {
        cout << "1. Create histogram" << endl
             << "2. Create sparce vector" << endl
             << "3. Building an alphabetical index" << endl
             << "0. Exit" << endl;

        cin >> switcher;
        if (switcher == 1) {
            string FirstNames[16]{ "Maria", "Olga", "Ivan", "Alexey", "Daria", "Filip", "Vasiliy", "Stepan", "Egor", "Elizaveta", "Alsu", "Liza", "Michael", "Andrey", "Kirill", "Alexander" };
            string MiddleNames[16]{ "Smirnov", "Frolov", "Nikitin", "Zaharov", "Oleksuk", "Polyakova", "Ershov", "Romanov", "Ilyin", "Grigorieva", "Ivanchenko", "Vinogradov", "Maksimova", "Medvedeva", "Semenov", "Kuzmin" };
            string LastNames[16]{ "Pavlovna", "Alexeevich", "Ivanovna", "Vasilievich", "Alekseevna", "Pavlovich", "Olegovich", "Vladimirovich", "Alexandrovich", "Michaelovna", "Mihailovna", "Nikolaevna", "Victorovich", "Pavlovich", "Petrovich", "Zaharovich" };

            Person Person_;
            int gap = 0;
            int amount = 0;
            int option = 0;
            int hist = 0;
            Histogram* histogramofpersons;
            Sequence<Person>* seq = new ArraySequence<Person>();
            cout << "Choose option" << endl;
            cout << "1 - age histogram" << endl;
            cout << "2 - middle name histogram" << endl;
            cin >> hist;
            switch(hist){
                case 1:
                    cout << "Choose option" << endl;
                    cout << "1 - auto generating sequence" << endl;
                    cout << "2 - enter sequence yourself" << endl;
                    cin >> option;
                    switch (option) {
                        case 1:
                            cout << "Amount of people: ";
                            srand(time(0));
                            amount = 5 + rand() % 10;
                            cout << amount << endl;
                            cout << "People:" << endl;
                            for (int i = 0; i < amount; i++) {
                                Person_ = Person(FirstNames[(rand() + i) % 16], MiddleNames[(rand() + i) % 16], LastNames[(rand() + i) % 16], 1950 + (rand() + i) % 71);
                                seq->Append(Person_);
                                cout << Person_.getFIO() << " ";
                                cout << Person_.getBirthYear() << endl;
                            }
                            cout << "Gap: ";
                            gap = 5 + rand() % 20;
                            cout << gap << endl;
                            histogramofpersons = new Histogram();
                            histogramofpersons->AgeHistogram(seq, gap);
                            cout << "Category - Amount: " << endl;
                            histogramofpersons->print();
                            break;
                        case 2:
                            cout << "Enter amount of people" << endl;
                            cin >> amount;
                            for (int i = 0; i < amount; i++) {
                                Person_ = enterPerson();
                                seq->Append(Person_);
                            }
                            cout << "Enter gap: ";
                            cin >> gap;
                            histogramofpersons = new Histogram();
                            histogramofpersons->AgeHistogram(seq, gap);
                            cout << "Key - category; Element - Amount" << endl;
                            histogramofpersons->print();
                            break;
                    }
                    break;
                case 2:
                    cout << "Choose option" << endl;
                    cout << "1 - auto generating sequence" << endl;
                    cout << "2 - enter sequence yourself" << endl;
                    cin >> option;
                    switch (option) {
                        case 1:
                            cout << "Amount of people: ";
                            srand(time(0));
                            amount = 5 + rand() % 10;
                            cout << amount << endl;
                            cout << "People:" << endl;
                            for (int i = 0; i < amount; i++) {
                                Person_ = Person(FirstNames[(rand() + i) % 16], MiddleNames[(rand() + i) % 16], LastNames[(rand() + i) % 16], 1950 + (rand() + i) % 71);
                                seq->Append(Person_);
                                cout << Person_.getMiddleName() << " ";
                                cout << Person_.getBirthYear() << endl;
                            }
                            cout << "Gap: ";
                            gap = 3 + rand() % 3;
                            cout << gap << endl;
                            histogramofpersons = new Histogram();
                            histogramofpersons->MiddleNameHistogram(seq, gap);
                            cout << "Category - Amount: " << endl;
                            histogramofpersons->print();
                            break;
                        case 2:
                            cout << "Enter amount of people" << endl;
                            cin >> amount;
                            for (int i = 0; i < amount; i++) {
                                Person_ = enterPerson();
                                seq->Append(Person_);
                            }
                            cout << "Enter gap: ";
                            cin >> gap;
                            histogramofpersons = new Histogram();
                            histogramofpersons->MiddleNameHistogram(seq, gap);
                            cout << "Key - category; Element - Amount" << endl;
                            histogramofpersons->print();
                            break;
                    }
                    break;

            }

        }

        else if (switcher == 2) {
            int option = 0;
            int amount = 0;
            int* vect;
            int value = 0;
            SparceVector<int>* Sparce_Vector;
            cout << "Choose option" << endl;
            cout << "1 - auto generating a vector" << endl;
            cout << "2 - enter the vector yourself" << endl;
            cin >> option;
            switch (option) {
                case 1:
                    cout << "Amount of the elements in the vector: " << endl;
                    srand(time(0));
                    amount = 1 + rand() % 30;
                    vect = new int[amount];
                    for (int i = 0; i < amount; i++) {
                        value = (rand() + i * 16) % 50;
                        if (i%10 == 0) value = 0;
                        cout << i << ". " << value << endl;
                        vect[i] = value;
                    }
                    Sparce_Vector = new SparceVector<int>(vect, amount);
                    cout << "size of vector is: " << Sparce_Vector->getSize() << endl;
                    cout << "vector:" << endl;
                    cout << "index - value" << endl;
                    Sparce_Vector->Print();
                    cout << endl;
                    break;
                case 2:
                    cout << "Enter amount of the elements in the vector: " << endl;
                    cin >> amount;
                    vect = new int[amount];
                    for (int i = 0; i < amount; i++) {
                        value = 0;
                        cout << i << ". ";
                        cin >> value;
                        vect[i] = value;
                    }
                    Sparce_Vector = new SparceVector<int>(vect, amount);
                    cout << "size of vector is: " << Sparce_Vector->getSize() << endl;
                    cout << "vector:" << endl;
                    cout << "index - value" << endl;
                    Sparce_Vector->Print();
                    cout << endl;
                    break;
            }
        }

        else if (switcher == 3) {

            const string letters = " abc defghi jklm nopqrstu vwxyz ";
            int option = 0;
            int sizeOfString;
            string String;
            int SizePageInLetters;
            AlphabetIndex* Collection;
            cout << "Choose option" << endl;
            cout << "1 - auto string" << endl;
            cout << "2 - enter the string yourself" << endl;
            cin >> option;
            switch (option) {
                case 1:
                    srand(time(0));
                    sizeOfString = 1 + rand() % 40;
                    for (int i = 0; i < sizeOfString; i++) {
                        String = String + letters[(rand()+i) % letters.size()];
                    }
                    cout << "String: " << String<< endl;
                    srand(time(0));
                    SizePageInLetters = 10 + rand() % 30;
                    cout << "Size of Page: " << SizePageInLetters << endl;
                    Collection = new AlphabetIndex(String, SizePageInLetters);
                    cout << "Number of Pages" << Collection->GetNumberOfPages() << endl;
                    cout << "Word - Page" << endl;
                    Collection->PrintWordsWithIndex();
                    break;
                case 2:
                    cout << "enter string: " << endl;
                    cin.ignore();
                    getline(cin, String);
                    cout << "enter Size of Page In Letters: " << endl;
                    cin >> SizePageInLetters;

                    Collection = new AlphabetIndex(String, SizePageInLetters);
                    cout << "Number of Pages" << Collection->GetNumberOfPages() << endl;
                    cout << "Word - Page" << endl;
                    Collection->PrintWordsWithIndex();
                    break;
            }
        }
    }
}
#endif //LABA2SEM3_INTERFACE_H
