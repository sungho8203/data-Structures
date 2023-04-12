#pragma once

#include <iostream>

using namespace std;

class Stack{
public:
    struct Node{
        int content;
        Stack::Node *underNode;
    };

    Stack::Node * topNode;

    Stack();
    ~Stack();

    bool initStack();

    bool pushStack(int pushContent);

    int popStack();

    bool showAllData();

    int getLength(){
        return countNode;
    };
private:
    int countNode;
};