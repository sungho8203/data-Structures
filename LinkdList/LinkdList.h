#ifndef LINKDLIST_DEFINE
#define LINKDLIST_DEFINE

#include <iostream>

using namespace std;

class LinkdList{
public:

    struct Node{
        int content;
        LinkdList::Node * prevNode;
        LinkdList::Node * nextNode; // 메모리 주소값 연산을 이용해서 prevNode를 참조하기 위해 nextNode멤버는 prevNode 바로 뒤에 위치한다. (이를 어길시 심히 심각한 오류를 경험하게 된다.)
    };

    LinkdList::Node * firstNode;
    LinkdList::Node * endNode;

    int countNode;

    LinkdList();

    ~LinkdList();

    bool addLinkdListNode(int content);

    bool deletLinkdList_index(int delIndex);
    bool deletLinkdList_content(int delContent);

    int searchLinkdList_index(int searchIndex);
    int searchLinkdList_content(int searchContent);
    
    void showAllData();
};
#endif