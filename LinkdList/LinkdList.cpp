#include "LinkdList.h"

LinkdList::LinkdList(){
    endNodeForAdd = &firstNode;
    firstNode = nullptr;
    countNode = 0;
}

LinkdList::~LinkdList(){
    LinkdList::Node * nextLinkdList;
    LinkdList::Node * curNode = firstNode;

    while (curNode)
    {
        nextLinkdList = curNode->nextNode;
        delete(curNode);
        curNode = nextLinkdList;
    }
}

bool LinkdList::addLinkdListNode(int content){
    try{
        LinkdList::Node *addNode = new LinkdList::Node;

        addNode->content = content;             // content 저장
        *endNodeForAdd = addNode;               // 현재 마지막 노드에 추가한 노드를 넣어준다.
        endNodeForAdd = &(addNode->nextNode);   // 추가한 노드의 nextNode요소의 주소를 넣어준다. (항상 마지막 노드의 다음 노드를 가리킴)

        countNode++;

        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool LinkdList::deletLinkdList_index(int delIndex)
{
    try{
        if(!firstNode)
            return false;

        LinkdList::Node * delNode = firstNode;

        for(int i = 0 ; i <= delIndex; i++)
            delNode = delNode->nextNode;
        
        delete(delNode);

        countNode--;

        return true;
    }
    catch(exception ex){
        return false;
    }
}

int LinkdList::searchLinkdList_index(int searchIndex)
{
    if (countNode < searchIndex)
    {
        cout << "인덱스가 node값보다 큽니다.";
        return 0;
    }

    LinkdList::Node * tempNode = firstNode;

    for(int i = 1; i < searchIndex; i++) // firstNode를 넣어서 1부터 시작한다.
        tempNode = tempNode->nextNode;
    
    std::cout << searchIndex << "번째 리스트의 값은 == " << tempNode->content << std::endl;

    return tempNode->content;
}

int LinkdList::searchLinkdList_content(int searchContent){
    LinkdList::Node *tempNode = firstNode;

    for(int i = 1; tempNode; i++)
    {
        if (tempNode->content == searchContent){
            std::cout << "찾으시는 " << searchContent << "값은 " << i << "번째에 있습니다." << std::endl;
            return i;
        }
    }

    std::cout << "찾으시는 " << searchContent << "은 없습니다." << std::endl;
    return -1;
}

void LinkdList::showAllData(){
    LinkdList::Node *tempNode = firstNode;
    for(int i = 1; tempNode; i++)
    {
        std::cout << i << "번 데이터는 == " << tempNode->content << std::endl;
        tempNode = tempNode->nextNode;
    }
    
    if(!firstNode)
        std::cout << "데이터가 없습니다." << std::endl;
}