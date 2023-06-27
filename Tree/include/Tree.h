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

    static vector<string> split(string str, char delimiter); // 문자열 split

    bool addNode(string value);
    bool addNode(Tree::Node * targetNode, string value);

    bool changeCurNode(string routeStr);
    Tree::Node * searchNode(string routeStr);

    bool delNode();
    bool delNode(Tree::Node * targetNode);

    bool showChildNode();
    bool showChildNode(Tree::Node * targetNode);

    bool showNodeData();
private:
    Tree::Node * curNode;
    Tree::Node * rootNode;

protected:
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