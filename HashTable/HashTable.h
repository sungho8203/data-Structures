#pragma once

#include <iostream>

#define COUNT_HASH 15 // 키 값에서 15의 나머지 값을 해쉬값으로 사용

using namespace std;

class CHashTable{
public:
    struct Content{
        int key;
        char * value;
    };

    struct Node{
        Content cont;
        Node * nextNode;
    };
    
    Node * HASH[COUNT_HASH];

    CHashTable();
    ~CHashTable();

    bool addContent(int key, char * value);

private:
};