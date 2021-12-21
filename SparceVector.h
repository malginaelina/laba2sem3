#ifndef LABA2SEM3_SPARCEVECTOR_H
#define LABA2SEM3_SPARCEVECTOR_H

#include "Dictionary.h"

template <class T>
class SparceVector {
private:

    Dictionary<int, T>* dict;
    int size = 0;

public:

    SparceVector(T* vector, int size) {
        dict = new Dictionary<int, int>();
        for (int j = 0; j < size; j++) {
            if (vector[j] != 0) {
                dict->add(j, vector[j]);
                this->size++;
            }
        }
    }

    ~SparceVector() {
        delete dict;
    }

    void addElem(int index, T elem) {
        if (elem != T(0)) {
            dict->add(index, elem);
            this->size++;
        }
    }

    T getElem(int index) {
        return dict->get(index);
    }

    void changeElem(int index, T elem) {
        dict->changeElem(index, elem);
    }

    T* fillSparceVector() {
        T* get_vector = new T[size];
        for (int i = 0; i < size; i++) {
            if (dict->containsKey(i))
                get_vector[i] = dict->get(i);
            else
                get_vector[i] = 0;
        }
        return get_vector;
    }

    int getSize() {
        return size;
    }

    void Print() {
        dict->print();
    }

};

#endif //LABA2SEM3_SPARCEVECTOR_H
