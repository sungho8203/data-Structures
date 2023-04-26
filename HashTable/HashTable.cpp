#include <HashTable.h>

CHashTable::CHashTable(): HASH() {
    countNode = 0;
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


bool CHashTable::addNewNode(int key, string value){
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

        countNode++;

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

        countNode--;

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

CHashTable::Node * CHashTable::searchNode(int key){
    CHashTable::Node * searchNode = CHashTable::HASH[key % COUNT_HASH];

    do{
        if(searchNode == nullptr)
            throw "키에 맞는 노드가 없습니다.";
    }while(searchNode->content.key != key && changeNextNode(&searchNode));    // and 논리연산자 순서 왼쪽부터, and 연산자를 이용해서 왼쪽 연산자가 True일때 다음 노드로 이동한다.

    return searchNode;
}

string CHashTable::searchContent(int key){
    try{
        CHashTable::Node * node = CHashTable::searchNode(key);

        return *(node->content.value);
    }
    catch(const char * ex){
        cout << ex << endl;
        return "";
    }
    catch(exception ex){
        return "";
    }
}

bool CHashTable::showAllContnet(){
    try{
        CHashTable::Node * nextNode;

        cout << "\n\n===========================================================================" << endl;
        cout << "Show All Content" << endl;

        for(int i = 0; i < COUNT_HASH; i++){
            nextNode = HASH[i];
            for(int j = 0; nextNode != nullptr; j++, nextNode = nextNode->nextNode)
                cout << i << "번째 HashTable의 " << j << "번째 노드는 키는 " << nextNode->content.key << "이고 값은 " << *(nextNode->content.value) << "입니다." << endl;
        }

        cout << "===========================================================================\n\n" << endl;
        
        return true;
    }
    catch(exception ex){
        return false;
    }
}

int CHashTable::getCountNode(){
    return countNode;
}

bool CHashTable::changeCotentValue(int key, string value){
    try{
        CHashTable::Node * node = CHashTable::searchNode(key);

        *(node->content.value) = value;

        return true;
    }
    catch(const char * ex){
        cout << ex << endl << "그래서 새로운 노드를 만들어서 저장합니다." << endl;
        CHashTable::addNewNode(key, value);     // 노드를 추가합니다.

        return true;
    }
    catch(exception ex){
        return false;
    }
}