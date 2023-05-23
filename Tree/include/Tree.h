#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include "./List.h"

using namespace std;

class Tree{
public :
    struct Content{
        string value;
    };

    struct Node{
        vector<Tree::Node *> childNode;
        Tree::Content content;
    };

    Tree();
    ~Tree();

    bool addCurNode(string value);

    bool changeNode(string routeStr);

private:
    Tree::Node * rootNode;
    Tree::Node * curNode;

protected:
    vector<string> split(string str, char delimiter);
};