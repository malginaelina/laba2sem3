#include <gtest/gtest.h>
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Dictionary.h"
#include "AlphabetIndex.h"
#include "SparceVector.h"
#include "Histogram.h"

TEST(DynamiсArray, Test) {
    int initArr1[] = { 1,2,3,4,5 };
    DynamicArray<int> arr1(initArr1, 5);

    EXPECT_EQ(arr1.Get(0), 1);
    EXPECT_EQ(arr1.Get(3), 4);
    EXPECT_EQ(arr1.Get(4), 5);
    EXPECT_EQ(arr1.GetSize(), 5);
}

TEST(LinkedList, Test) {
    int initArr1[] = { 1,2,3,5 };
    LinkedList<int> list1(initArr1, 4);

    EXPECT_EQ(list1.Get(0), 1);
    EXPECT_EQ(list1.GetFirst(), 1);
    EXPECT_EQ(list1.Get(2), 3);
    EXPECT_EQ(list1.Get(3), 5);
    EXPECT_EQ(list1.GetLast(), 5);

    list1.Prepend(0);
    list1.Append(6);
    list1.Insert(-1, 0);
    list1.Insert(7, 7);
    list1.Insert(4, 5);
    EXPECT_EQ(list1.Get(0), -1);
    EXPECT_EQ(list1.Get(5), 4);

    list1.Set(-2, 0);
    list1.Set(8, 8);
    list1.Set(0, 7);
    EXPECT_EQ(list1.Get(0), -2);
}

TEST(ArraySequence, Test) {
    int initArr1[] = { 1,2,3,5 };
    ArraySequence<int> seq1(initArr1, 4);

    EXPECT_EQ(seq1.Get(0), 1);
    EXPECT_EQ(seq1.GetFirst(), 1);
    EXPECT_EQ(seq1.Get(2), 3);
    EXPECT_EQ(seq1.Get(3), 5);
    EXPECT_EQ(seq1.GetLast(), 5);
    EXPECT_EQ(seq1.GetSize(), 4);
}

TEST(ListSequence, Test) {
    int initArr1[] = { 1,2,3,5 };
    ListSequence<int> seq1(initArr1, 4);

    EXPECT_EQ(seq1.Get(0), 1);
    EXPECT_EQ(seq1.GetFirst(), 1);
    EXPECT_EQ(seq1.Get(2), 3);
    EXPECT_EQ(seq1.Get(3), 5);
    EXPECT_EQ(seq1.GetLast(), 5);
    EXPECT_EQ(seq1.GetSize(), 4);
}

TEST(Dictionary, Test){
    auto* dict = new Dictionary<int, int>(5, 1);
    EXPECT_EQ(true, dict->containsKey(5));
    EXPECT_EQ(dict->get(5), 1);
    EXPECT_EQ(dict->getCount(), 1);

    dict->add(10, 0);
    dict->add(100, 101);
    EXPECT_EQ(true, dict->containsKey(10));
    EXPECT_EQ(true, dict->containsKey(100));
    EXPECT_EQ(dict->getCount(), 3);
    EXPECT_EQ(dict->get(100), 101);

    dict->changeElem(100, 99);
    EXPECT_EQ(true, dict->containsKey(100));
    EXPECT_EQ(dict->getCount(), 3);
    EXPECT_EQ(dict->get(100), 99);

    dict->remove(100);
    EXPECT_EQ(false, dict->containsKey(100));
    EXPECT_EQ(dict->getCount(), 2);
}

TEST(AlphabetIndex, Test){
    string String = " abc defghi jklmnopq rstu vwxyz ";
    auto* Collection = new AlphabetIndex(String, 15);

    EXPECT_EQ(Collection->GetNumberOfPages(), 4);
    EXPECT_EQ(Collection->GetPageOfString("abc"), 1);
    EXPECT_EQ(Collection->GetPageOfString("defghi"), 2);
    EXPECT_EQ(Collection->GetPageOfString("jklmnopq"), 3);
    EXPECT_EQ(Collection->GetPageOfString("rstu"), 3);
    EXPECT_EQ(Collection->GetPageOfString("vwxyz"), 4);
}

TEST(Histogram, Test){
    auto* seq = new ArraySequence<Person>();
    seq->Append(Person("a", "f", "z", 2001));
    seq->Append(Person("b", "g", "x", 2004));
    seq->Append(Person("c", "h", "c", 2003));
    seq->Append(Person("d", "j", "b", 2014));
    seq->Append(Person("e", "k", "m", 1980));
    seq->Append(Person("e", "k", "m", 1999));

    auto* hist = new Histogram();
    hist->AgeHistogram(seq, 10);

    EXPECT_EQ(hist->getAmountOfCategories(), 4);
    EXPECT_EQ(hist->getCategorysAmount(1), 1);
    EXPECT_EQ(hist->getCategorysAmount(2), 3);
    EXPECT_EQ(hist->getCategorysAmount(3), 1);
    EXPECT_EQ(hist->getCategorysAmount(5), 1);
}

TEST(SparceVector, Test){
    int value;
    int* vect = new int[10];
    for (int i = 0; i < 10; i++) {
        value = i;
        if (i % 3 == 0)
            value = 0;
        vect[i] = value;
    }
    auto*  Sparce_Vector = new SparceVector<int>(vect, 10);

    EXPECT_EQ(Sparce_Vector->getSize(), 6);
    for (int i = 0; i < 10; i++) {
        if (i%3 != 0)
            EXPECT_EQ(Sparce_Vector->getElem(i), i);
    }
    Sparce_Vector->addElem(20, 5);
    EXPECT_EQ(Sparce_Vector->getElem(20), 5);
    EXPECT_EQ(Sparce_Vector->getSize(), 7);
}