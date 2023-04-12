#include "Queue.h"

Queue::Queue(){
    firstNode = nullptr;
    endNode = firstNode;
    countNode = 0;
}

Queue::~Queue(){
    while(countNode)
        this->popQueue();

}

bool Queue::initQueue(){
    try{
        while (countNode)
            this->popQueue();

        cout << "success init" << endl;

        return true;
    }
    catch(int ex){
        cout << "init fail" << endl;
        return false;
    }
}

int Queue::pushQueue(int queueContent){
    try{
        Queue::Node * addNode = new Queue::Node;
        addNode->content = queueContent;

        if (countNode <= 0)
            throw addNode;

        endNode->nextNode = addNode;
        endNode = addNode;
        countNode++;
    }
    // 노드가 하나도 없을 때
    catch(Queue::Node * addNode){
        firstNode = addNode;
        endNode = firstNode;
        countNode = 1;
    }
    // 찐 에러 상황
    catch(exception ex){
        cout << "push Error" << endl;
        return -1;
    }
    return queueContent;
}

int Queue::popQueue(){
    try{
        if (countNode <= 0)
            throw 0;
        
        Queue::Node * tempNode = firstNode->nextNode;
        int firstNodeValue = firstNode->content;

        delete(firstNode);
        firstNode = tempNode;
        countNode--;

        return firstNodeValue;
    }
    catch(int noneNode){
        cout << "없습니다 노드가" << endl;
        countNode = 0;
        return 0;
    }
    catch(exception ex){
        cout << "pop Error" << endl;
        return 0;
    }
}

bool Queue::showAllData(){
    try{

        cout << "\n\n=============================" << endl;
        if (countNode <= 0)
            throw 0;
        Queue::Node * tempNode = firstNode;
        for(int i = 0; i < countNode; i++){
            cout << tempNode->content << endl;
            tempNode = tempNode->nextNode;
        }
        
        cout << "=============================\n\n" << endl;
        return true;
    }
    catch(int noneNode){
        cout << "데이터가 없습니다." << std::endl;
        cout << "=============================\n" << endl;
        return false;
    }
    catch(exception ex){
        return false;
    }
}