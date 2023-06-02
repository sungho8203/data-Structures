#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include "./List.h"

using namespace std;

template<typename T, typename FUNC, typename OP_FUNC>
class ChildNodeList : List<T>{
public:
    using List<T>::getSize;
    T travelList(FUNC fun, T nextNode, OP_FUNC opFun){
        *fun(nextNode, opFun);
    }
};

class Tree{
public :
    struct Node{
        ChildNodeList<Tree::Node *, bool (Tree::*)(Tree::Node * nextNode, bool (Tree::*opFunc)(Tree::Node *)), bool (Tree::*)(Tree::Node *)> childNode;
        string value;
    };

    Tree();
    ~Tree();

    bool addCurNode(string value);

    bool changeCurNode(string routeStr);

    bool deleteCurNode();

    bool traversal(Tree::Node * nextNode, bool (Tree::*opFunc)(Tree::Node *));
private:
    Tree::Node * rootNode;
    Tree::Node * curNode;

protected:
    vector<string> split(string str, char delimiter);
    bool deleteNode(Tree::Node * operands);
};