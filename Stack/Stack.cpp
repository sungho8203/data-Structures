#include "Stack.h"

Stack::Stack(){
    topNode = nullptr;
    countNode = 0;
}

Stack::~Stack(){
    while(countNode)
        this->popStack();
}

bool Stack::pushStack(int pushContent){
    try{
        Stack::Node * addNode = new Stack::Node;
        
        addNode->content = pushContent;
        addNode->prevNode = topNode;
        topNode = addNode;

        countNode++;

        return true;
    }
    catch(exception ex){
        return false;
    }
}

int Stack::popStack(){
    try{
        Stack::Node * nextTopNode = topNode->prevNode;
        int returnValue = topNode->content;

        delete(topNode);

        topNode = nextTopNode;

        countNode--;

        return returnValue;
    }
    catch(exception ex){
        cout << "예외 상황 바생" << endl;
        return 0;
    }
}

bool Stack::showAllData(){
    try{
        cout << "\n\n=============================" << endl;

        cout << "=============================\n\n" << endl;
    }
    catch(exception ex){
        return false;
    }
}