#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include "./List.h"

using namespace std;

class Tree{
public :
    struct Node{
        List<Tree::Node *> childNode;
        string value;
    };

    Tree();
    ~Tree();

    bool addCurNode(string value);

    bool changeCurNode(string routeStr);

    bool deleteCurNode();
    bool traversal(bool (Tree::* opFun)(Tree::Node * operand));
private:
    Tree::Node * rootNode;
    Tree::Node * curNode;

protected:
    vector<string> split(string str, char delimiter);
    bool deleteNode(Tree::Node * operands);
};


template<>
Tree::Node* List<Tree::Node *>::find(string value);

template<>
template<typename Func>
bool List<Tree>::listTravel(Func fun);