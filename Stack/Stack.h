#pragma once

#include <iostream>

using namespace std;

class Stack{
public:
    struct Node{
        int content;
        Stack::Node *prevNode;
    };

    Stack::Node * topNode;

    Stack();
    ~Stack();

    bool pushStack(int pushContent);

    int popStack();

    bool showAllData();
    int getLength(){
        return countNode;
    };
private:
    int countNode;
};