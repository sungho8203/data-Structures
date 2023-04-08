#include <iostream>
#include "LinkdList.h"

int main()
{
    LinkdList temp;

    temp.addLinkdListNode(10);
    temp.addLinkdListNode(11);
    temp.addLinkdListNode(1);
    temp.addLinkdListNode(100);

    temp.searchLinkdList_content(10);
    temp.deletLinkdList_content(10);
    temp.searchLinkdList_index(4);
    temp.showAllData();

    return 0;
}