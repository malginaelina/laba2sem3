#ifndef LABA2SEM3_HISTOGRAM_H
#define LABA2SEM3_HISTOGRAM_H

#include "Dictionary.h"
#include "BinaryTree.h"
#include "Sequence.h"
#include "Person.h"
#include "ArraySequence.h"
#include <string>

class Histogram
{
private:

    Dictionary<int, int>* dict;

    int HistogramParamAge(Person man, int gap) {
        int age = man.getAge(2021);
        if (age < 0)
            throw out_of_range("Wrong age!");
        int category = 1;
        while ((age - gap) > 0) {
            category++;
            age -= gap;
        }
        return category;
    }

    int HistogramParamName(Person man, int gap) {
        string middleName = man.getMiddleName();
        char firstLetter = middleName[0];
        if (firstLetter < 'A' || firstLetter > 'Z')
            throw out_of_range("Wrong Middle Name!");
        int category = 1;
        int symbol = firstLetter;
        while ((symbol - gap) > 64) {
            category++;
            symbol -= gap;
        }
        return category;
    }


public:

    Histogram(){
        this->dict = new Dictionary<int, int>();
    }

    void AgeHistogram(Sequence<Person>* seq, int gap) {
        int amount;
        int category = HistogramParamAge(seq->Get(0), gap);
        this->dict = new Dictionary<int, int>(category, 1);
        for (int i = 1; i < seq->GetSize(); i++)
        {
            category = HistogramParamAge(seq->Get(i), gap);
            if (this->dict->containsKey(category))
            {
                amount = this->dict->get(category) + 1;
                this->dict->changeElem(category, amount);
            }
            else {
                this->dict->add(category, 1);
            }
        }
    }

    void MiddleNameHistogram(Sequence<Person>* seq, int gap) {
        int amount;
        int category = HistogramParamName(seq->Get(0), gap);
        this->dict = new Dictionary<int, int>(category, 1);
        for (int i = 1; i < seq->GetSize(); i++)
        {
            category = HistogramParamName(seq->Get(i), gap);
            if (this->dict->containsKey(category))
            {
                amount = this->dict->get(category) + 1;
                this->dict->changeElem(category, amount);
            }
            else {
                this->dict->add(category, 1);
            }
        }
    }

    int getCategorysAmount(int category)
    {
        return this->dict->get(category);
    }
    int getAmountOfCategories()
    {
        return this->dict->getCount();
    }

    void print()
    {
        dict->print();
    }

    ~Histogram()
    {
        delete dict;
    }
};

#endif //LABA2SEM3_HISTOGRAM_H
