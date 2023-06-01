#pragma once

#include <iostream>

using namespace std;

template<typename TYPE>
class List{
public:
    int size;

    struct Node{
        TYPE content;
        Node * nextNode;
    };

    List() : firstNode(nullptr){
        lastNode = &firstNode;
        size = 0;
    }
    ~List(){
        clear();
    }

    bool add(TYPE value){
        try{
            Node * newNode = new Node;
            newNode->content = value;
            newNode->nextNode = nullptr;

            *lastNode = newNode;
            lastNode = &(newNode->nextNode);

            this->size++;

            return true;
        }
        catch(const std::bad_alloc&){
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

    bool find(TYPE value){
        Node * tempNode = firstNode;

        while(tempNode != nullptr){
            if(tempNode->content == value)
                return true;
            tempNode = tempNode->nextNode;
        }
        return false;
    }

    TYPE find(string value){
        // 문자열을 이용해서 특정 노드를 찾기 위한 함수 **(specialization을 해야됨)**
    }

    template<typename Func>
    bool listTravel(Func fun){
        fun();
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
    }
private:
    Node ** lastNode;
    Node * firstNode;
};