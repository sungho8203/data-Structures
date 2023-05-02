#include <BinarySearchTree.h>

BinaryTree::BinaryTree(){
    this->rootNode = nullptr;
}

BinaryTree::~BinaryTree(){
    this->deleteTree();
}

string BinaryTree::searchValue(int key){
    try{
        BinaryTree::Node ** tempNode = searchNode(&rootNode, key);
        if(*tempNode == nullptr)
            return "데이터가 없습니다.";

        return (*tempNode)->content.value;

    }
    catch(exception ex){
        return "에러 상황입니다.";
    }
}

bool BinaryTree::addValue(int key, string value){
    try{
        BinaryTree::Node ** addNode = searchNode(&rootNode, key);

        if (*addNode != nullptr)
            throw "이미 데이터가 있습니다.";

        *addNode = new BinaryTree::Node;

        (*addNode)->content.key = key;
        (*addNode)->content.value = value;

        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
        return false;
    }
    catch(exception ex){
        return false;
    }
}

bool BinaryTree::deleteTree(){
    try{
        treeTraversal(rootNode, &BinaryTree::deleteNode);
        rootNode = nullptr;
        return true;
    }
    catch(exception ex){
        return false;
    }
}


#pragma region Private

bool BinaryTree::treeTraversal(BinaryTree::Node * node, void (BinaryTree::*operateNode)(BinaryTree::Node * )){
    if (node == nullptr)
        return false;

    if (node->leftNode != nullptr)
        treeTraversal(node->leftNode, operateNode);

    if (node->rigthNode != nullptr)
        treeTraversal(node->rigthNode, operateNode);

    (this->*operateNode)(node);

    return true;
}


BinaryTree::Node ** BinaryTree::searchNode(BinaryTree::Node ** node, int key){
    BinaryTree::Node ** resultNode = node;
    int nodeKey;

    if (*node == nullptr)
        return node;

    nodeKey = (*node)->content.key;

    if (nodeKey > key)
        resultNode = searchNode(&(*node)->leftNode, key);
    else if (nodeKey < key)
        resultNode = searchNode(&(*node)->rigthNode, key);
    else   
        resultNode = node;
    
    return resultNode;
}

#pragma endregion