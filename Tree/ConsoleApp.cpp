#include "./include/ConsoleApp.h"

ConsoleApp::ConsoleApp(){
    cmdMap["exit"] = &ConsoleApp::exitCommand;    
    cmdMap["ls"] = &ConsoleApp::lsCommand;

    cmdMap["q"] = &ConsoleApp::exitCommand; //!!!!!!! 테스트할 때 편의를 위해서 사용(나중에 삭제)

    cmdMap["cd"] = &ConsoleApp::cdCommand;
    cmdMap["touch"] = &ConsoleApp::touchCommand;
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
                cmdData.erase(0,1);
                vector<string> cmdToken = Tree::split(cmdData, ' ');
                (this->*(cmdMap[cmdName]))(cmdToken);
            }
            else
                cout << "Invalid Command" << endl;

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
    tree.showChildNode();
}

void ConsoleApp::cdCommand(vector<string> cmdToken){
    
    if (cmdToken.size() == 1)
        tree.changeCurNode(cmdToken[0]);
    else
        cout << "Invalid Argument" << endl;
}

void ConsoleApp::touchCommand(vector<string> cmdToken){

    if(cmdToken.size() == 1)
        tree.addNode(cmdToken[0]);
    else if (cmdToken.size() == 2)
        tree.addNode(tree.searchNode(cmdToken[0]), cmdToken[1]);
    else
        cout << "Invalid Argument" << endl;
}
#pragma endregion