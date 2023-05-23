#pragma once

#include <iostream>

using namespace std;

template<typename TYPE>
class List{
public:
    template<typename TYPE_T>
    struct Node{
        TYPE content;
        List<TYPE>::Node<TYPE> * nextNode;
    };

    List();
    ~List();

    bool add(TYPE value);

    bool remove(TYPE value);

    bool find(TYPE value);
private:
    List<TYPE>::Node<TYPE> * lastNode;
    List<TYPE>::Node<TYPE> * fistNode;
};