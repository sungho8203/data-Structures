#pragma once

#include <iostream>

using namespace std;

class BinaryTree{
public :
    struct Content{
        int key;
        string value;
    };

    struct Node{
        Content content;
        BinaryTree::Node * leftNode;
        BinaryTree::Node * rigthNode;

        int level;
    };

    BinaryTree::Node * rootNode;

    BinaryTree();
    ~BinaryTree();

    bool addValue(int key, string value);

    string searchValue(int key);

    bool deleteTree();
    bool deleteSubTree(int key);

    bool showAllData();

private :
    int searchNodeLevel;
    BinaryTree::Node ** searchNode(BinaryTree::Node ** node, int value);
    
    bool treeTraversal(BinaryTree::Node * node, void (BinaryTree::*operateNode)(BinaryTree::Node * ));

    void deleteNode(BinaryTree::Node * node){
        delete(node);
    }

    void showNodeValue(BinaryTree::Node * node){
        cout << "값 : " << node->content.value << "\t레벨 : " << node->level << endl;
    }
};
