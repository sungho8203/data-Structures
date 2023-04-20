#include "HashTable.h"

CHashTable::CHashTable(): HASH() {

}

CHashTable::~CHashTable(){
    CHashTable::Node * nextNode, * delNode;
    for(int i = 0; i < COUNT_HASH; i++){
        delNode = nextNode = HASH[i];
        while(nextNode != nullptr){
            nextNode = delNode->nextNode;
            delete(delNode->content.value);
            delete(delNode);
            delNode = nextNode;
        }
    }
}


bool CHashTable::addContent(int key, string value){
    try{
        CHashTable::Node * tempNode = new CHashTable::Node;
        int hashKey = key % COUNT_HASH;
        
        tempNode->content.key = key;
        tempNode->content.value = new string(value);

        tempNode->nextNode = nullptr;

        if(HASH[hashKey] == nullptr){
            HASH[hashKey] = tempNode;
        }
        else{
            CHashTable::Node * endNode = HASH[hashKey];
            for(int i = 0; endNode->nextNode != nullptr; i++){
                if (endNode->content.key == key)
                    throw "이미 사용 중인 키입니다.";
                endNode = endNode->nextNode;
            }
            endNode->nextNode = tempNode;
        }
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


bool CHashTable::deleteContent(int key){
    try{
        CHashTable::Node * nextNode = HASH[key % COUNT_HASH];
        CHashTable::Node ** ptrNextNodeElement = (HASH + (key % COUNT_HASH));

        if (nextNode == nullptr)
            throw "키가 없습니다.";
        
        while(nextNode->content.key != key){
            ptrNextNodeElement = &(nextNode->nextNode);
            nextNode = nextNode->nextNode;

            if (nextNode == nullptr)
                throw "키를 찾을 수 없습니다.";
        }

        cout << key << "의 값은 \"" << *(nextNode->content.value) << "\" 이고 삭제 합니다." << endl;

        *ptrNextNodeElement = nextNode->nextNode;

        delete(nextNode->content.value);
        delete(nextNode);

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


bool CHashTable::changeNextNode(CHashTable::Node ** nextNode){
    *nextNode = (*nextNode)->nextNode;
    return true;
}

string CHashTable::searchContent(int key){
    try{
        CHashTable::Node * nextNode = HASH[key % COUNT_HASH];

        do{
            if(nextNode == nullptr)
                throw "키가 맞는 노드가 없습니다.";
        }while(nextNode->content.key != key && changeNextNode(&nextNode));   // and 논리연산자 순서 왼쪽부터, and 연산자를 이용해서 왼쪽 연산자가 True일때 다음 노드로 이동한다.

        return *(nextNode->content.value);
    }
    catch(const char * ex){
        cout << ex << endl;
        return "";
    }
    catch(exception ex){
        return "";
    }
}