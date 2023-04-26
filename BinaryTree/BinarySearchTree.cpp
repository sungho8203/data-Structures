#include <BinarySearchTree.h>

BinaryTree::BinaryTree(){
    this->rootNode = nullptr;
}

BinaryTree::~BinaryTree(){

}

BinaryTree::Node * BinaryTree::searchNode(BinaryTree::Node * node, int value){
    BinaryTree::Node * result = nullptr;

    if (node->leftNode != nullptr){
        if (value == node->content.value)
            return node;
        else if (value < node->content.value)
            result = this->searchNode(node->leftNode, value);
    }
    else if (node->rigthNode != nullptr){
        if (value == node->content.value)   
            return node;
        else if(value > node->content.value)
            result = this->searchNode(node->rigthNode, value);
    }

    return result;
}

bool BinaryTree::searchValue(int value){
    try{
        if(!searchNode(rootNode, value)){
            cout << "데이터가 없습니다." << endl;
            return false;
        }

        return true;

    }
    catch(exception ex){
        return false;
    }
}

bool BinaryTree::addValue(int value){
    try{
        BinaryTree::Node * addNode = searchNode(rootNode, value);

        return true;
    }
    catch(exception ex){
        return false;
    }
}