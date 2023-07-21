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

vector<string> Tree::split(string str, char delimiter){
    vector<string> resultSplit;
    stringstream strStream(str);
    string splitTemp;

    while(getline(strStream, splitTemp, delimiter))
        resultSplit.push_back(splitTemp);

    return resultSplit;
}

bool Tree::addNode(string value){
    return this->addNode(curNode, value);
}

bool Tree::addNode(Tree::Node * targetNode, string value){
    Tree::Node * newNode;
    try{
        newNode  = new Tree::Node;

        if (value == "")
            throw "데이터가 비어있습니다.";
        newNode->value = value;
        newNode->parentNode = targetNode;

        if (rootNode == nullptr){
            rootNode = newNode;
            curNode = rootNode;
            newNode->parentNode = rootNode;
            return true;
        }

        if (findValueAtParamNode(targetNode, value) != nullptr)
            throw "현재 노드에 이미 있는 값입니다.";

        targetNode->childNode.add(newNode);

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
    Tree::Node * targetNode = this->searchNode(routeStr);

    if (targetNode == nullptr)
        return false;
    
    this->curNode = targetNode;
    return true;
}

Tree::Node * Tree::searchNode(string routeStr){
    try{
        if (curNode == nullptr){
            curNode = rootNode;
            throw (string)"현재 노드가 비어있습니다.rootNode로 이동합니다.";
        }

        vector<string> routeToken = Tree::split(routeStr, '/');

        Tree::Node * routeNode = curNode;
        int routeIndex = 0;

        if (routeToken[0].compare("~") == 0){
            routeIndex = 1;
            routeNode = rootNode;
        }

        for(;routeIndex < routeToken.size();routeIndex++){
            Tree::Node * tempNode = routeNode;
            
            if ((tempNode = findValueAtParamNode(tempNode, routeToken[routeIndex])) == nullptr)
                throw string(routeStr + " 경로에서 \"" +routeToken[routeIndex] + "\" Node는 없습니다.");

            routeNode = tempNode;
        }

        return routeNode;
    }
    catch(const string ex){
        cout << ex << endl;
        return nullptr;
    }
}

bool Tree::delNode(string nodeValue){
    return this->delNode(curNode, nodeValue);
}

bool Tree::delNode(Tree::Node * routeNode, string nodeValue){
    try{
        Tree::Node * targetNode = findValueAtParamNode(routeNode, nodeValue);
        if (targetNode == nullptr)
            throw (nodeValue + "Node를 찾을 수 없습니다.");

        targetNode->parentNode->childNode.remove(targetNode);
        traversal(targetNode, &Tree::deleteNode);

        if (targetNode == rootNode)
            curNode = rootNode = nullptr;

        return true;
    }
    catch(string ex){
        cout << ex << endl;
        return false;
    }
    catch(exception ex){
        return false;
    }
}

bool Tree::showChildNode(){
    if (curNode == nullptr){
        curNode = rootNode;
        cout << "Tree가 비어 있습니다." << endl;
        return false;
    }
    return this->showChildNode(curNode);
}

bool Tree::showChildNode(Tree::Node * targetNode){
    try{
        if (targetNode == nullptr)
            return false;
        cout << "현재 노드 : " << targetNode->value << endl;
        cout << "  하위 노드";

        if (targetNode->childNode.setNextCurNode()){
            for (int i = 0; i < targetNode->childNode.getSize(); i++)
                cout << " - " << (targetNode->childNode++)->value;
            cout << "\n  갯수는    = " << targetNode->childNode.getSize() << "\n\n";
        }
        else
            cout << "가 없습니다." << endl;

        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
        return false;
    }
}

// 현재 노드의 value를 제외한 data를 출력하는 함수 (미구현)
bool Tree::showNodeData(){
    return false;
}

#pragma region Protected

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
    // List가 비어있으면
    if(!nextNode->childNode.getSize() || !nextNode->childNode.setNextCurNode())
        return (this->*opFunc)(nextNode);

    for(int i = 0; i < nextNode->childNode.getSize(); i++){
        traversal(nextNode->childNode++, opFunc);
    }

    if (opFunc == &Tree::deleteNode)
        nextNode->childNode.clear();

    return (this->*opFunc)(nextNode);
}

Tree::Node * Tree::findValueAtParamNode(Tree::Node * curNode_local, string value){
    Tree::Node * resultNode = nullptr, * tempNode;

    // Parameter로 들어온 Tree Node의 childNode 요소(List)의 순환을 위해 setting하는 코드 (List가 비었으면 nullptr return)
    if (!curNode_local->childNode.setNextCurNode())
        return nullptr;

    for(int i = 0; i < curNode_local->childNode.getSize(); i++){
        if ((tempNode = curNode_local->childNode++)->value == value){
            resultNode = tempNode;
            break;
        }
    }
    return resultNode;
}

#pragma endregion