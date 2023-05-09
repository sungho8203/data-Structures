#include <BinarySearchTree.h>

BinaryTree::BinaryTree(){
    this->rootNode = nullptr;
    this->searchNodeLevel = 0;
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
        (*addNode)->level = searchNodeLevel;
        (*addNode)->route = searchNodeRoute;

        (*addNode)->leftNode = (*addNode)->rigthNode = nullptr;
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

bool BinaryTree::deleteSubTree(int key) {
    try {
        BinaryTree::Node** tempNode = searchNode(&rootNode, key);
        treeTraversal(*tempNode, &BinaryTree::deleteNode);
        *tempNode = nullptr;

        return true;
    }
    catch (exception ex) {
        return false;
    }
}

bool BinaryTree::showAllData(){
    try{
        cout << "\n\n================================================" << endl;
        cout << "Show All Data Function 입니다." << endl;

        treeTraversal(rootNode, &BinaryTree::showNodeValue);
        
        cout << "================================================\n\n" << endl;
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
    BinaryTree::Node ** tempNode;
    searchNodeRoute.clear();

    tempNode = searchNode_run(node, key);

    if (searchNodeRoute.empty())
        searchNodeRoute = "Root Node";

    return tempNode;
}

BinaryTree::Node ** BinaryTree::searchNode_run(BinaryTree::Node ** node, int key){
    BinaryTree::Node ** resultNode = node;
    int nodeKey;

    if (*node == nullptr || (nodeKey = (*node)->content.key) == key){
        searchNodeLevel = 0;
        return node;
    }

    if (nodeKey > key){
        searchNodeRoute += "0";
        resultNode = searchNode_run(&(*node)->leftNode, key);
    }
    else if (nodeKey < key){
        searchNodeRoute += "1";
        resultNode = searchNode_run(&(*node)->rigthNode, key);
    }

    searchNodeLevel++;
    
    return resultNode;
}

#pragma endregion
