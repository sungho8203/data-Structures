#include "./include/ConsoleApp.h"

ConsoleApp::ConsoleApp(){
    sCmdMap["exit"] = &ConsoleApp::exitCommand;    
    sCmdMap["ls"] = &ConsoleApp::lsCommand;

    sCmdMap["q"] = &ConsoleApp::exitCommand; //!!!!!!! 테스트할 때 편의를 위해서 사용(나중에 삭제)

    mCmdMap["cd"] = &ConsoleApp::cdCommand;
    mCmdMap["touch"] = &ConsoleApp::touchCommand;
}

ConsoleApp::~ConsoleApp(){
}

bool ConsoleApp::commandLine(){
    try{
        string cmdName;
        while (1)
        {
            cin >> cmdName;

            auto sTempCmdMap = sCmdMap.find(cmdName);
            auto mTempCmdMap = mCmdMap.find(cmdName);

            if (sTempCmdMap != sCmdMap.end())
            {
                (this->*(sCmdMap[cmdName]))();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력버퍼 비우기
            }
            else if (mTempCmdMap != mCmdMap.end())
                (this->*(mCmdMap[cmdName]))();
            else
                cout << "Invalid Command" << endl;

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
    tree.showCurNodeChildNode();
}

void ConsoleApp::cdCommand(){
    string cmdContent;
    cin >> cmdContent;
    tree.changeCurNode(cmdContent);
}

void ConsoleApp::touchCommand(){
    string cmdContent;
    getline(cin, cmdContent);

    tree.addCurNode(cmdContent);
}
#pragma endregion