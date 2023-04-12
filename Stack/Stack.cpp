#include "Stack.h"

Stack::Stack(){
    topNode = nullptr;
    countNode = 0;
}

Stack::~Stack(){
    while(countNode)
        this->popStack();
}

bool Stack::initStack(){
    try{
        while (countNode)
            this->popStack();

        cout << "success init" << endl;

        return true;
    }
    catch(int ex){
        cout << "init fail" << endl;
        return false;
    }
}

bool Stack::pushStack(int pushContent){
    try{
        Stack::Node * addNode = new Stack::Node;
        
        addNode->content = pushContent;
        addNode->underNode = topNode;
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
        if (countNode <= 0)
            throw string("노드가 없음");

        Stack::Node * nextTopNode = topNode->underNode;
        int returnValue = topNode->content;

        delete(topNode);

        topNode = nextTopNode;

        countNode--;

        return returnValue;
    }
    catch(string ex){
        cout << ex << endl;
        return 0;
    }
}

bool Stack::showAllData(){
    try{
        Stack::Node * tempNode = topNode;

        cout << "\n\n=============================" << endl;

        if(!countNode){
            std::cout << "데이터가 없습니다." << std::endl;
            cout << "=============================\n" << endl;
            return false;
        }

        for(int i = 1; i <= countNode; i++){
            cout << "위에서 부터 " << i << "번째 값은 " << tempNode->content << endl;
            tempNode = tempNode->underNode;
        }

        cout << "=============================\n\n" << endl;
        return true;
    }
    catch(exception ex){
        return false;
    }
}