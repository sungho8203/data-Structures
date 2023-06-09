#include "./include/ConsoleApp.h"

ConsoleApp::ConsoleApp(){
    cmdMap["exit"] = &ConsoleApp::exitCommand;
    cmdMap["ls"] = &ConsoleApp::lsCommand;
    cmdMap["cd"] = &ConsoleApp::cdCommand;
}

ConsoleApp::~ConsoleApp(){
}

bool ConsoleApp::commandLine(){
    try{
        string cmdName;
        while (1){
            cin >> cmdName;

            auto tempCmdMap = cmdMap.find(cmdName);
            if (tempCmdMap != cmdMap.end())    
                (this->*(cmdMap[cmdName]))();
            else
                cout << "Invalid Command" << endl;

            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력버퍼 비우기
        }
        return true;
    }
    catch(const char * ex){
        cout << ex << endl;
        return false;
    }
}

#pragma region ConsoleApp_Private_Method

void ConsoleApp::exitCommand(){
    throw "Exit Application";
}

void ConsoleApp::lsCommand(){
    tree.showCurNodeData();
}

void ConsoleApp::cdCommand(){
    string cmdContent;
    cin >> cmdContent;
    cout << cmdContent << endl;
}
#pragma endregion