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

bool ConsoleApp::commandLine(){
    try{
        string cmdName, cmdData;
        while (1)
        {
            cin >> cmdName;
            getline(cin, cmdData);
            
            auto tempCmdMap = cmdMap.find(cmdName);

            if (tempCmdMap != cmdMap.end()){
                cmdData.erase(0,1);
                (this->*(cmdMap[cmdName]))(cmdData);
            }
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

#pragma region ConsoleApp_Command_Method

void ConsoleApp::exitCommand(string cmdData){
    throw "Exit Application";
}

void ConsoleApp::lsCommand(string cmdData){
    tree.showChildNode(tree.curNode);
}

void ConsoleApp::cdCommand(string cmdData){
    vector<string> cmdToken = Tree::split(cmdData, ' ');
    Tree::Node * targetNode = tree.searchNode(cmdToken[0]);

    if (targetNode != nullptr)
        tree.curNode = targetNode;
}

void ConsoleApp::touchCommand(string cmdData){
    vector<string> cmdToken = Tree::split(cmdData, ' ');
    Tree::Node * targetNode = tree.curNode;

    if(cmdToken.size() == 2)
        if ((targetNode = tree.searchNode(cmdToken[0])) == nullptr)
            throw "Invalid Argument";
    
    if (cmdToken.size() == 2){
        Tree::Node * tempTargetNode = nullptr;

        if ((tempTargetNode = tree.searchNode(cmdToken[0])) != nullptr)
            tree.addNode(tempTargetNode, cmdToken[1]);
    }
    else
        cout << "Invalid Argument" << endl;
}
#pragma endregion