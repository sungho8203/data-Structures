#ifndef LINKDLIST_DEFINE
#define LINKDLIST_DEFINE

#include <iostream>

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

    int countNode;

    LinkdList();

    ~LinkdList();

    bool addLinkdListNode(int addIndex, int addContent = 0);

    bool deletLinkdList_index(int delIndex);
    bool deletLinkdList_content(int delContent);

    int searchLinkdList_index(int searchIndex, int *searchContent);
    int searchLinkdList_content(int searchContent);
    
    void showAllData();

private:
    // addLinkdListNode function
    void addNodeFirstOrEnd(int addIndex, int addContent, LinkdList::Node * addNode);
};
#endif