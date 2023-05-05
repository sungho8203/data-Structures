#pragma once

#include <iostream>

using namespace std;

class BinaryTree{
public :
    struct Content{
        int key;
        string value;
        int level;
    };
    struct Node{
        Content content;
        BinaryTree::Node * leftNode;
        BinaryTree::Node * rigthNode;
    };

    BinaryTree::Node * rootNode;

    BinaryTree();
    ~BinaryTree();

    bool addValue(int key, string value);

    string searchValue(int key);

    bool deleteTree();

    bool showAllData();

private :
    static BinaryTree::Node ** searchNode(BinaryTree::Node ** node, int value);
    
    bool treeTraversal(BinaryTree::Node * node, void (BinaryTree::*operateNode)(BinaryTree::Node * ));

    void deleteNode(BinaryTree::Node * node){
        delete(node);
    }

    void showNodeValue(BinaryTree::Node * node){
        cout << node->content.value << endl;
    }
};