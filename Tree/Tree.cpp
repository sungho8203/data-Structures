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

bool Tree::changeNode(string routeStr){
    try{
        vector<string> routeToken = this->split(routeStr, '/');
        int tokenIndex = 0;
        Tree::Node * routeNode = curNode;
        string throwStr = "는 없는 Node입니다.";

        if(routeToken[0] == "~"){
            routeNode = rootNode;
            tokenIndex++;   // 첫 번째 token이 ~이므로 다음 token으로 이동
        }

        for(; tokenIndex < routeToken.size(); tokenIndex++){
            vector<Tree::Content> childNode;
            
            if(1)
                throw throwStr.insert(0, routeToken[tokenIndex]);
            
            routeNode = curNode; // 변경해
        }
        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
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

#pragma endregion