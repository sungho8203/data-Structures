#include "LinkdList.h"

LinkdList::LinkdList(){
    firstNode = nullptr;
    endNode = firstNode;
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

		// countNode가 0이 아니면 prevNode에 이전 노드의 주소를 넣는다.
        if (countNode){            
            addNode->prevNode = endNode->nextNode - sizeof(LinkdList::Node *);
        	endNode->nextNode = addNode;            // 현재 마지막 노드의 nextNode에 추가한 노드를 넣어준다.
		}
		//현재 노드가 없으면
		else{
			firstNode = addNode;					// firstNode를 업데이트 해준다.
			endNode = addNode;						// endNode에 addNode를 넣어준다.
		}
        addNode->content = content;             	// content 저장
		endNode = addNode;							// endNode에 추가한 노드를 넣어 마지막 노드를 업데이트 한다.

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
        if(!firstNode || delIndex > countNode)
            return false;

        LinkdList::Node * delNode = firstNode;

        for(int i = 1 ; i <= delIndex; i++)
            delNode = delNode->nextNode;

        if(!delNode->nextNode)									
            endNode = delNode->prevNode;						// 마지막 노드면 마지막 노드를 가리키는 변수를  업데이트 한다.
		else if(firstNode == delNode)
			firstNode = delNode->nextNode;						// 첫 노드면 첫 노드를 가리키는 변수를 업데이트 한다.
		else{
			delNode->prevNode->nextNode = delNode->nextNode;	// 앞 순번의 노드의 다음노드를 가리키는 멤버를 지우는 노드의 다음 노드로 업데이트한다.
			delNode->nextNode->prevNode = delNode->prevNode;	// 위의 연산의 반대
		} 

        delete(delNode);

        countNode--;

        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool LinkdList::deletLinkdList_content(int delContent)
{
    try{
        if (!firstNode)
            return false;

        LinkdList::Node * delNode = firstNode, *prevDelNode = firstNode;
        int i;

        for (i = 1; i < delContent; i++){
            if (delNode->content == delContent)
                break;
            prevDelNode = delNode;
            delNode = delNode->nextNode;
        }

        if(!delNode->nextNode)									
            endNode = delNode->prevNode;						// 마지막 노드면 마지막 노드를 가리키는 변수를  업데이트 한다.
		else if(firstNode == delNode)
			firstNode = delNode->nextNode;						// 첫 노드면 첫 노드를 가리키는 변수를 업데이트 한다.
		else{
			delNode->prevNode->nextNode = delNode->nextNode;	// 앞 순번의 노드의 다음노드를 가리키는 멤버를 지우는 노드의 다음 노드로 업데이트한다.
			delNode->nextNode->prevNode = delNode->prevNode;	// 위의 연산의 반대
		} 
        
        prevDelNode->nextNode = delNode->nextNode;      // 서로의 노드를 이어준다.
        delete(delNode);
        countNode--;
        return true;
    }
    catch (exception ex){
        return false;
    }
}

int LinkdList::searchLinkdList_index(int searchIndex)
{
    if (countNode < searchIndex)
    {
        cout << "인덱스가 node값보다 큽니다." << endl;
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