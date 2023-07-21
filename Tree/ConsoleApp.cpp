#include "./include/ConsoleApp.h"

ConsoleApp::ConsoleApp(){
    cmdMap["exit"] = &ConsoleApp::exitCommand;    
    cmdMap["ls"] = &ConsoleApp::lsCommand;

    cmdMap["cd"] = &ConsoleApp::cdCommand;
    cmdMap["touch"] = &ConsoleApp::touchCommand;
    cmdMap["rm"] = &ConsoleApp::rmCommand;
}

ConsoleApp::~ConsoleApp(){
}

void ConsoleApp::commandLine(){
    try{
        string cmdName, cmdData;
        while (1)
        {
            cin >> cmdName;
            getline(cin, cmdData);
            
            auto tempCmdMap = cmdMap.find(cmdName);

            if (tempCmdMap != cmdMap.end()){
                cmdData.erase(0,1); // 명령어 이름 뒤에 붙는 화이트 스페이스 제거
                vector<string> cmdToken = Tree::split(cmdData, ' ');// 스페이스를 기준으로 문자열을 조각낸다.

                (this->*(cmdMap[cmdName]))(cmdToken); // cmdMap에 연결된 함수를 실행한다.
            }
            else
                cout << INVALD_COMMAND << endl;

            putchar('\n');
        }
        return ;
    }
    catch(const char * ex){
        cout << ex << endl;
        return ;
    }
}

#pragma region ConsoleApp_Command_Method

void ConsoleApp::exitCommand(vector<string> cmdToken){
    throw "Exit Application";
}

void ConsoleApp::lsCommand(vector<string> cmdToken){

    if (cmdToken.size() == 0)
        tree.showChildNode();
    else if (cmdToken.size() == 1)
        tree.showChildNode(tree.searchNode(cmdToken[0]));
    else   
        cout << INVALD_COMMAND << endl;
}

void ConsoleApp::cdCommand(vector<string> cmdToken){
    
    if (cmdToken.size() == 1)
        tree.changeCurNode(cmdToken[0]);
    else
        cout << INVALD_COMMAND << endl;
}

void ConsoleApp::touchCommand(vector<string> cmdToken){

    if(cmdToken.size() == 1)
        tree.addNode(cmdToken[0]);
    else if (cmdToken.size() == 2)
        tree.addNode(tree.searchNode(cmdToken[0]), cmdToken[1]);
    else
        cout << INVALD_COMMAND << endl;
}

void ConsoleApp::rmCommand(vector<string> cmdToken){
    if (cmdToken.size() == 1)
        tree.delNode(cmdToken[0]);
    else if (cmdToken.size() == 2)
        tree.delNode(tree.searchNode(cmdToken[0]), cmdToken[1]);
    else
        cout << INVALD_COMMAND << endl;
}
#pragma endregion