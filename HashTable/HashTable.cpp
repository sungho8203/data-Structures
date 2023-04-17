#include "HashTable.h"

CHashTable::CHashTable(): HASH{nullptr, } {

}

CHashTable::~CHashTable(){

}


bool CHashTable::addContent(int key, char * value){
    try{
        CHashTable::Node * tempNode = new CHashTable::Node;
        int hashKey = key % COUNT_HASH;
        
        tempNode->cont.key = key;
        tempNode->cont.value = value;

        if(HASH[hashKey] == nullptr){
            HASH[hashKey] = tempNode;
        }
        else{
            CHashTable::Node * endNode = HASH[hashKey];
            for(int i = 0; endNode->nextNode != nullptr; i++){
                endNode = endNode->nextNode;
            }
            endNode->nextNode = tempNode;
        }
    }
    catch(exception ex){
        return false;
    }
}