#ifndef LABA2SEM3_DICTIONARY_H
#define LABA2SEM3_DICTIONARY_H
#include <iostream>
#include <utility>
#include "BinaryTree.h"

template<class TKey, class TElement>
class Pair
{
private:
    TKey key;
    TElement element;

public:

    Pair() = default;
    Pair(TKey key, TElement element)
    {
        this->key = key;
        this->element = element;
    }

    TElement getElem() const
    {
        return this->element;
    }
    TKey getKey() const
    {
        return this->key;
    }

    void setKey(TKey key)
    {
        this->key = key;
    }
    void setElem(TElement elem)
    {
        this->element = elem;
    }

    bool operator<(const Pair another)
    {
        return this->key < another.key;
    }
    bool operator>(const Pair another)
    {
        return this->key > another.key;
    }
    bool operator<=(const Pair another)
    {
        return this->key <= another.key;
    }
    bool operator>=(const Pair another)
    {
        return this->key >= another.key;
    }
    bool operator!=(const Pair another)
    {
        return this->key != another.key;
    }
    bool operator==(const Pair <TKey, TElement> another)
    {
        return this->key == another->key;
    }
};

template <class TKey, class TElement>
std::ostream& operator<< (std::ostream& out, const Pair<TKey, TElement> pair)
{
    return out << "<" << pair.getKey() << ", " << pair.getElem() << ">";
}

template <class TKey, class TElement>
class Dictionary
{
protected:

    BinaryTree<Pair<TKey, TElement>>* dict;
    bool (*cmp)(Pair<TKey, TElement>, Pair<TKey, TElement>) = compare;
public:

    Dictionary()
    {
        this->dict = new BinaryTree<Pair<TKey, TElement>>();
    }

    Dictionary(const TKey key, const TElement elem)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>(key, elem);
        this->dict = new BinaryTree<Pair<TKey, TElement>>(pair_, cmp);
    }
    int getCount()
    {
        return this->dict->getSize();
    }

    TElement get(TKey key)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>();
        pair_.setKey(key);
        if (this->dict->find(pair_))
        {
            return this->dict->getElem(dict->search(pair_)).getElem();
        }
        throw out_of_range("No element!");
    }
    bool containsKey(TKey key)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>();
        pair_.setKey(key);
        return (this->dict->find(pair_));
    }
    void add(TKey key, TElement element)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>(key, element);
        if (this->dict == nullptr) {
            this->dict->add(pair_);
        }
        else if (this->dict->find(pair_))
        {
            return;
        }
        this->dict->add(pair_);
    }

    void remove(TKey key)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>();
        pair_.setKey(key);
        if (this->dict->find(pair_))
        {
            this->dict->erase(pair_);
            return;
        }
        throw out_of_range("No element!");
    }

    void print()
    {
        this->dict->printAll();
    }

    void changeElem(TKey key, TElement elem)
    {
        Pair<TKey, TElement> pair_ = Pair<TKey, TElement>(key, elem);
        this->dict->setElem(this->dict->search(pair_), pair_);
    }

    ~Dictionary(){
        delete dict;
    }
};

#endif //LABA2SEM3_DICTIONARY_H
