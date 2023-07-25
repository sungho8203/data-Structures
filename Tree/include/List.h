#pragma once

#include <iostream>

using namespace std;


class ListException : exception{
private :
    unsigned int errorCode;

public :
    enum ErrorCode{
        e_EMPTY = 1,
        e_OUT_OF_RANGE,
    };

    ListException(unsigned int code){
        errorCode = code;
    }

    unsigned int getErrorCode(){
        return errorCode;
    }

    const char * getErrorMsg(){
        switch(errorCode){
        case e_EMPTY:
            return "List가 비어있습니다.";
        case e_OUT_OF_RANGE:
            return "참조하는 index가 List의 size보다 큽니다.";
        }
        return "";
    }
};

template<typename TYPE>
class List{
protected:
    struct Node{
        TYPE content;
        Node * nextNode;
    };

    Node ** lastNode;
    Node * firstNode;

    Node * curIndexNode;    // typename 키워드를 사용해서 Node가 변수가 아닌 형식임을 알려준다.?

    struct BD{
        Node * curNode;
        int index;

        BD(){
            init();
        }        
        BD(Node * initNode, int initIndex) : curNode(initNode), index(initIndex){}

        void update(BD update){
            curNode = update.curNode;
            index = update.index;
        }

        void init(){
            curNode = nullptr;
            index = 0;
        }

    }bracketData;    // Bracket 오버로딩을 효율적으로 처리하기 위해 이전 index값을 저장하는 변수.

    int size;

public:

    List(){
        initData();
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
                if (bracketData.curNode == tempNode)
                    bracketData.init();
                    
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

        initData();

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

    void initData(){
        firstNode = nullptr;
        lastNode = &firstNode;
        size = 0;
        curIndexNode = firstNode;

        bracketData.init();
    }

#pragma region METHOD_IS_FOR_TRAVERSAL
    // List의 증가연산를 사용할 때 초기화를 해줘야 한다.
    // return : 빈 List면 False, 요소가 있으면 True
    bool setNextCurNode(){
        curIndexNode = firstNode;
        return !emptyList();
    }

    TYPE nextCurNode(){
        Node * tempNode;

        if (firstNode == nullptr)
            throw ListException(ListException::e_EMPTY);
        
        if(curIndexNode == nullptr)
            curIndexNode = firstNode;      
        tempNode = curIndexNode;

        curIndexNode = curIndexNode->nextNode;

        return tempNode->content;
    }

    TYPE returnCurNode(){
        return curIndexNode->content;
    }

    TYPE operator++(){
        return nextCurNode();
    }
    TYPE operator++(int){
        return nextCurNode();
    }
#pragma endregion

#pragma region METHOD_IS_FOR_INDEX_REF
    TYPE operator[] (int index){
        BD start(firstNode, 0);

        if (index >= getSize())
            throw ListException(ListException::e_OUT_OF_RANGE);
        
        if (index >= bracketData.index && bracketData.curNode != nullptr)
            start.update(bracketData);
        

        for (; start.index < index; start.index++)
            start.curNode = start.curNode->nextNode;

        bracketData.update(start);

        return bracketData.curNode->content;    
    }

#pragma endregion
};
