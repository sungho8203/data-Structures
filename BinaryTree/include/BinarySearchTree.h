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
        string route;
    };

    BinaryTree::Node * rootNode;

    BinaryTree();
    ~BinaryTree();

    bool addValue(int key, string value);

    string searchKey(int key);

    bool deleteTree();
    bool deleteSubTree(int key);

    bool showAllData();

private :
    int searchNodeLevel;
    string searchNodeRoute;
    BinaryTree::Node ** searchNode(BinaryTree::Node ** node, int value);
    BinaryTree::Node ** searchNode_run(BinaryTree::Node ** node, int value);
    
    bool treeTraversal(BinaryTree::Node * node, void (BinaryTree::*operateNode)(BinaryTree::Node * ));

    void deleteNode(BinaryTree::Node * node){
        delete(node);
    }

    void showNodeValue(BinaryTree::Node * node){
        cout << "값 : " << node->content.value << "\t레벨 : " << node->level << "\tkey : ";
        printf("%2d", node->content.key);   // key값이 한 글자면 탭이 이상해짐 (키 값이 너무 길어져도 문제가 될듯)
        cout << "\troute : " << node->route << endl;
    }
};
