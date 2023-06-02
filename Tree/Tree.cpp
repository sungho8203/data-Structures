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
            Tree::Node * tempNode;// = routeNode->childNode.find(routeToken[routeIndex]);
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
        traversal(curNode, &Tree::deleteNode);
        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool Tree::traversal(Tree::Node * nextNode, bool (Tree::*opFunc)(Tree::Node *)){
    if(nextNode->childNode.getSize())
        return (this->*opFunc)(nextNode);
    else
        nextNode->childNode.travelList(&Tree::traversal, nextNode, opFunc);

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



 #pragma region ChildNodeList_Method

#pragma endregion