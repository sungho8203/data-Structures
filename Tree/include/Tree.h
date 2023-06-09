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

    ChildNodeList(){
    }

    void initCurNode(){
    }

    T nextCurNode(){
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

    bool showCurNodeChildNode();
    bool showCurNodeData();
private:
    Tree::Node * rootNode;
    Tree::Node * curNode;

protected:
    vector<string> split(string str, char delimiter);
    bool deleteNode(Tree::Node * operands);
    bool traversal(Tree::Node * nextNode, bool (Tree::*opFunc)(Tree::Node *));
    Tree::Node * findValueAtParamNode(Tree::Node * curNode_local, string value);
};


template<>
class ChildNodeList<Tree::Node *> : public List<Tree::Node *>{
public :
    List<Tree::Node *>::Node * curIndexNode;

    ChildNodeList(){
        initCurNode();
    }

    void initCurNode(){
        curIndexNode = List<Tree::Node *>::firstNode;
    }

    Tree::Node * nextCurNode(){
        List<Tree::Node *>::Node * tempNode;
        
        if(curIndexNode == nullptr)
            curIndexNode = List<Tree::Node *>::firstNode;        
        tempNode = curIndexNode;

        curIndexNode = curIndexNode->nextNode;

        return tempNode->content;
    }
};

struct Tree::Node{
    ChildNodeList<Tree::Node *> childNode;
    string value;
};