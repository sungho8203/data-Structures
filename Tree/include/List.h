#pragma once

#include <iostream>

using namespace std;

template<typename TYPE>
class List{
private:
    struct Node{
        TYPE content;
        Node * nextNode;
    };

    Node ** lastNode;
    Node * firstNode;

    Node * curIndexNode; // typename 키워드를 사용해서 Node가 변수가 아닌 형식임을 알려준다.

    int size;

public:

    List() : firstNode(nullptr){
        lastNode = &firstNode;
        size = 0;
        curIndexNode = firstNode;
    }
    ~List(){
        clear();
    }

    bool add(TYPE value){
        try{
            Node * newNode = new Node;
            newNode->content = value;
            newNode->nextNode = nullptr;

            if (firstNode == nullptr){
                firstNode = newNode;
                lastNode = &(newNode->nextNode);
            }
            else{            
                *lastNode = newNode;
                lastNode = &(newNode->nextNode);
            }
            
            size++;

            return true;
        }
        catch(exception ex){
            return false;
        }
    }

    bool remove(TYPE value){
        Node * tempNode = firstNode;
        Node ** prevNode = &firstNode;

        while(tempNode != nullptr){
            if(tempNode->content == value){
                *prevNode = tempNode->nextNode;
                delete(tempNode);
                this->size--;

                return true;
            }
            prevNode = &(tempNode->nextNode);
            tempNode = tempNode->nextNode;
        }
        return false;
    }

    virtual bool find(TYPE value){
        Node * tempNode = firstNode;

        while(tempNode != nullptr){
            if(tempNode->content == value)
                return true;
            tempNode = tempNode->nextNode;
        }
        return false;
    }

    void clear(){
        Node * tempNode = firstNode;
        Node * nextNode = nullptr;

        while(tempNode != nullptr){
            nextNode = tempNode->nextNode;
            delete(tempNode);
            tempNode = nextNode;
        }

        firstNode = nullptr;
        lastNode = &firstNode;
        size = 0;
    }
    
    int getSize(){
        return size;
    }


    bool emptyList(){
        if (firstNode == nullptr)
            return true;
        else {
            return false;
        }
    }

#pragma region FOR_ALL_DATA_REFERENCE
    // List의 증가연산를 사용할 때 초기화를 해줘야 한다.
    bool setNextCurNode(){
        curIndexNode = firstNode;
        return !emptyList();
    }

    TYPE nextCurNode(){
        Node * tempNode;

        if (firstNode == nullptr)
            return nullptr;

        if(curIndexNode == nullptr)
            curIndexNode = firstNode;      
        tempNode = curIndexNode;

        curIndexNode = curIndexNode->nextNode;

        return tempNode->content;
    }
    TYPE operator++(){
        return nextCurNode();
    }
    TYPE operator++(int){
        return nextCurNode();
    }
#pragma endregion
};