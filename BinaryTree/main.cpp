#include <BinarySearchTree.h>

int main(){
    BinaryTree temp;

    cout << temp.searchValue(10) << endl;

    temp.addValue(10, "이정빈");
    cout << temp.searchValue(10) << endl;

    temp.deleteTree();

    cout << temp.searchValue(10) << endl;

    for(int i = 0; i < 11; i++){
        char tempStr[10] = "f0as";
        tempStr[1] = '0' + i;
        temp.addValue(i, tempStr);
    }

    for(int i = 0; i > -11; i--){
        char tempStr[10] = "f9as";
        tempStr[1] = '0' + i;
        temp.addValue(i, tempStr);
    }
    
    temp.addValue(1000, "fadsfa");
    temp.addValue(100, "temp");
    temp.addValue(1001, "큰");

    cout << "\n\n==================================" << endl;
    for (int i = 0; i < 11; i++){
        cout << temp.searchValue(i) << endl;
    }
    cout << "==================================\n\n" << endl;

    cout << "\n\n==================================" << endl;
    for (int i = -1; i > -11; i--){
        cout << temp.searchValue(i) << endl;
    }
    cout << "==================================\n\n" << endl;

    // temp.deleteSubTree(1);

    temp.showAllData();

    temp.deleteTree();

    cout << temp.searchValue(8) << endl;

    return 0;
}