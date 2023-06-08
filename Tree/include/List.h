#pragma once

#include <iostream>

using namespace std;

template<typename TYPE>
class List{
public:

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

protected:
    Node ** lastNode;
    Node * firstNode;

private:
    int size;
};