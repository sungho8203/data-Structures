#ifndef LINKDLIST_DEFINE
#define LINKDLIST_DEFINE

#include <iostream>

using namespace std;

class LinkdList{
public:

    struct Node{
        int content;
        LinkdList::Node * nextNode;
    };

    LinkdList::Node * firstNode;
    LinkdList::Node **endNodeForAdd;

    int countNode;

    LinkdList();

    ~LinkdList();

    bool addLinkdListNode(int content);

    bool deletLinkdList_index(int delIndex);

    int searchLinkdList_index(int searchIndex);

    int searchLinkdList_content(int searchContent);
    
    void showAllData();
};
#endif