#pragma once

#include <iostream>

using namespace std;

class BinaryTree{
public :
    struct Content{
        int value;
    };
    struct Node{
        Content content;
        BinaryTree::Node * leftNode;
        BinaryTree::Node * rigthNode;
    };

    BinaryTree::Node * rootNode;

    BinaryTree();
    ~BinaryTree();

    bool addValue(int valjue);

    bool searchValue(int value);

private :
    BinaryTree::Node * searchNode(BinaryTree::Node * node, int value);
};