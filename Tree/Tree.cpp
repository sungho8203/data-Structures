#include "./include/Tree.h"
#include <algorithm>

Tree::Tree(){
    Tree::rootNode = nullptr;
    Tree::curNode = rootNode;
}

Tree::~Tree(){
    if (rootNode == nullptr)
        return ;
    traversal(rootNode, &Tree::deleteNode);
}

bool Tree::addCurNode(string value){
    Tree::Node * newNode;
    try{
        newNode  = new Tree::Node;

        newNode->value = value;

        if (rootNode == nullptr){
            rootNode = newNode;
            curNode = rootNode;
            return true;
        }

        if (findValueAtParamNode(curNode, value) != nullptr)
            throw "현재 노드에 이미 있는 값입니다.";

        curNode->childNode.add(newNode);

        return true;
    }
    catch (const char * ex){
        delete newNode;
        cout << ex << endl;
        return false;
    }
    catch(std::bad_alloc ex){
        cout << "메모리 할당 실패" << endl;
        return false;
    }
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
            Tree::Node * tempNode = routeNode;
            int i = 0;
            
            if ((tempNode = findValueAtParamNode(tempNode, routeToken[routeIndex])) == nullptr)
                throw (routeStr + "이 경로에서 \"" +routeToken[routeIndex] + "\" Node는 없습니다.");

            routeNode = tempNode;
        }
        curNode = routeNode;
        return true;
    }
    catch(const string ex){
        cout << ex << endl;
        return false;
    }
}

bool Tree::deleteCurNode(){
    try{
        traversal(curNode, &Tree::deleteNode);

        if (curNode == rootNode)
            curNode = rootNode = nullptr;

        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool Tree::showCurNodeChildNode(){
    try{
        if (curNode == nullptr)
            throw "Tree가 비어 있습니다.";

        cout << "현재 노드 : " << curNode->value << endl;
        cout << "  하위 노드";

        curNode->childNode.initCurNode();
        for (int i = 0; i < curNode->childNode.getSize(); i++)
            cout << " - " << curNode->childNode.nextCurNode()->value;
        cout << "\n  갯수는    = " << curNode->childNode.getSize() << "\n\n";

        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
        return false;
    }
}

// 현재 노드의 value를 제외한 data를 출력하는 함수 (미구현)
bool Tree::showCurNodeData(){
    return false;
}

#pragma region Protected

vector<string> Tree::split(string str, char delimiter){
    vector<string> resultSplit;
    stringstream strStream(str);
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

bool Tree::traversal(Tree::Node * nextNode, bool (Tree::*opFunc)(Tree::Node *)){
    if(!nextNode->childNode.getSize())
        return (this->*opFunc)(nextNode);

    nextNode->childNode.initCurNode();

    for(int i = 0; i < nextNode->childNode.getSize(); i++){
        traversal(nextNode->childNode.nextCurNode(), opFunc);
    }

    if (opFunc == &Tree::deleteNode)
        nextNode->childNode.clear();

    return (this->*opFunc)(nextNode);
}
Tree::Node * Tree::findValueAtParamNode(Tree::Node * curNode_local, string value){
    Tree::Node * resultNode = nullptr, * tempNode;
    curNode_local->childNode.initCurNode(); // Parameter로 들어온 Tree Node의 childNode 요소(List)의 initCurNode메소드를 실행

    for(int i = 0; i < curNode_local->childNode.getSize(); i++){
        if ((tempNode = curNode_local->childNode.nextCurNode())->value == value){
            resultNode = tempNode;
            break;
        }
    }
    return resultNode;
}

#pragma endregion