#include "./include/Tree.h"
#include <algorithm>

Tree::Tree(){
    Tree::rootNode = nullptr;
    Tree::curNode = rootNode;
}

Tree::~Tree(){

}

bool Tree::addCurNode(string value){
    return false;
}

bool Tree::changeCurNode(string routeStr){
    try{
        vector<string> routeToken = this->split(routeStr, '/');
        Tree::Node * routeNode = curNode;
        int routeIndex = 0;

        if (routeToken[0].compare("~") == 0){
            routeIndex = 1;
            routeNode = rootNode;
        }

        for(;routeIndex < routeToken.size();routeIndex++){
            Tree::Node * tempNode = routeNode->childNode.find(routeToken[routeIndex]);
            if (tempNode == nullptr)
                throw (routeToken[routeIndex] + " Node는 없습니다.").c_str();
            routeNode = tempNode;
        }
        curNode = routeNode;
        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
        return false;
    }
}

bool Tree::deleteCurNode(){
    try{
        traversal(curNode);
        return true;
    }
    catch(exception ex){
        return false;
    }
}

#pragma region Protected

vector<string> Tree::split(string str, char delimiter){
    vector<string> resultSplit;
    stringstream strStream;
    string splitTemp;

    while(getline(strStream, splitTemp, delimiter))
        resultSplit.push_back(splitTemp);

    return resultSplit;
}

bool Tree::traversal(Tree::Node * nextNode){
    return nextNode->childNode.listTravel([this](Tree::Node * node){
        return traversal(node);
    });
}

bool Tree::deleteNode(Tree::Node * operand){
    try{
        delete (operand);
        return true;
    }
    catch(exception ex){
        return false;
    }
}

#pragma endregion



#pragma region List_Method_Specialization

template<>
Tree::Node* List<Tree::Node *>::find(string value){
    List::Node * tempNode = this->firstNode;

    while(tempNode != nullptr){
        if (tempNode->content->value == value)
            return tempNode->content;
        tempNode = tempNode->nextNode;
    }
    return (Tree::Node *)nullptr;
}

template<>
template<typename Func>
bool List<Tree::Node *>::listTravel(Func traversal){
    List::Node * tempNode = firstNode;

    for(int i = 0; i < this->size; i++){
        traversal(tempNode->content);

        tempNode = tempNode->nextNode;
    }
}

#pragma endregion