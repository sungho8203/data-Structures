#pragma once

#include <iostream>

using namespace std;

class Queue{
public :
    struct Node{
        int content;
        Queue::Node * nextNode;
    };

    Queue::Node * firstNode;
    Queue::Node * endNode;

    Queue();
    ~Queue();

    bool initQueue();

    int pushQueue(int queueContent);

    int popQueue();

    bool showAllData();

    int getLength(){
        return countNode;
    }

private :
    int countNode;
};