#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include "./List.h"

using namespace std;

template<typename T>
class ChildNodeList : public List<T>{
public:
    typename List<T>::Node * curIndexNode;

    ChildNodeList() : curIndexNode(List<T>::firstNode){}

    T operator++(){
    }

    T find(string value){
    }
};

class Tree{
public :
    struct Node;

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

template<>
class ChildNodeList<Tree::Node *> : public List<Tree::Node *>{
public :
    List<Tree::Node *>::Node * curIndexNode;

    ChildNodeList() : curIndexNode(List<Tree::Node *>::firstNode){}

    Tree::Node * operator++(){
        if(curIndexNode == *List<Tree::Node *>::lastNode)
            curIndexNode = List<Tree::Node *>::firstNode;
        else
            curIndexNode = curIndexNode->nextNode;

        return curIndexNode->content;
    }
};

struct Tree::Node{
    ChildNodeList<Tree::Node *> childNode;
    string value;
};
