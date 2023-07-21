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
        Tree::Node * parentNode;
    };

    Tree();
    ~Tree();

    static vector<string> split(string str, char delimiter); // 문자열 split

    bool addNode(string value);
    bool addNode(Tree::Node * targetNode, string value);

    bool changeCurNode(string routeStr);
    Tree::Node * searchNode(string routeStr);

    bool delNode(string value);
    bool delNode(Tree::Node * routeNode, string value);

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