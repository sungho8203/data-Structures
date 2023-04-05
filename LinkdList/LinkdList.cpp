#include <iostream>

using namespace std;

class LinkdList{

    struct Node{
        int content;
        LinkdList::Node * nextNode;
    };

    LinkdList::Node * firstNode;
    LinkdList::Node **endNodeForAdd;

    LinkdList(){
        endNodeForAdd = &firstNode;
    }

    ~LinkdList(){
        LinkdList::Node * nextNode, *curNode = firstNode;

        do{
            nextNode = curNode->nextNode;
            delete(curNode);                // null 포인터 세이프됨
            curNode = nextNode;
        }while (nextNode->nextNode);
    }

    bool addLinkdList(int content){
        try{
           *endNodeForAdd = new Node;

            endNodeForAdd = &((*endNodeForAdd)->nextNode);

            return true;
        }
        catch(exception ex){
            return false;
        }
    }

    bool deletLinkdList_index(int delIndex)
    {
        try{
            LinkdList::Node * delNode = firstNode;

            for(int i = 0 ; i <= delIndex; i++)
                delNode = delNode->nextNode;
            
            delete(delNode);

            return true;
        }
        catch(exception ex){
            return false;
        }
    }
};