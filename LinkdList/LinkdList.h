#ifndef LINKDLIST_DEFINE
#define LINKDLIST_DEFINE

#include <iostream>

#define FOR_FIRST_NUMBER 2 // for문에서 index변수인 i의 초기화 값

using namespace std;

class LinkdList{
public:

    struct Node{
        int content;
        LinkdList::Node * prevNode;
        LinkdList::Node * nextNode;
    };

    LinkdList::Node * firstNode;
    LinkdList::Node * endNode;

    LinkdList();

    ~LinkdList();

// 리스트 처리 함수들
    bool initLinkdList();
    
    bool addLinkdListNode(unsigned int addIndex, int addContent = 0);

    bool deletLinkdList_index(unsigned int delIndex);
    bool deletLinkdList_content(int delContent);

    int searchLinkdList_index(unsigned int searchIndex);
    int searchLinkdList_content(int searchContent);
    
    void showAllData();

    int replaceNodeContent(unsigned int replaceIndex, int replaceContent);

// 리스트 정보와 관련된 함수들
    int getCount(){
        return countNode;
    }

private:
    // addLinkdListNode function
    void addNodeFirstOrEnd(int addIndex, int addContent, LinkdList::Node * addNode);
    int countNode;
};
#endif