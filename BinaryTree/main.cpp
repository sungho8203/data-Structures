#include <BinarySearchTree.h>

int main(){
    BinaryTree temp;

    cout << temp.searchValue(10) << endl;

    temp.addValue(10, "이정빈");
    cout << temp.searchValue(10) << endl;

    return 0;
}