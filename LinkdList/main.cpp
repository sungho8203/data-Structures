#include <iostream>
#include "LinkdList.h"

int main()
{
    LinkdList temp;

    temp.addLinkdListNode(1,5);
    temp.addLinkdListNode(2,3);
    temp.addLinkdListNode(3,11);
    temp.addLinkdListNode(1,11);

    temp.searchLinkdList_content(10);
    temp.deletLinkdList_content(10);
    temp.showAllData();

    return 0;
}