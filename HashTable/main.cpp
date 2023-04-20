#include "HashTable.h"

int main(){
    CHashTable temp;

    temp.addContent(1, "fads");
    temp.deleteContent(1);
    temp.addContent(1, "fads");

    cout << temp.searchContent(1);

    return 0;
}