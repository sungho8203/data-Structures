#include "Stack.h"

int main(){
    Stack temp;

    temp.popStack();

    temp.pushStack(10);
    temp.pushStack(11);
    temp.pushStack(12);
    temp.pushStack(13);

    temp.showAllData();
    cout << temp.getLength() << endl;

    cout << "pop " << temp.popStack() << endl;

    temp.initStack();
}