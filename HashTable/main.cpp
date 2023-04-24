#include "HashTable.h"

int main(){
    CHashTable temp;

    temp.addNewNode(1, "fads");
    temp.deleteContent(1);
    for(int i = 0; i < COUNT_HASH; i++)
        temp.addNewNode(i, "fads");

    cout << temp.searchContent(1) << endl;
    temp.changeCotentValue(1000, "문성호");
    cout << temp.searchContent(1000) << endl;

    temp.showAllContnet();

    return 0;
}