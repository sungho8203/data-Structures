#pragma once

#include "./Tree.h"
#include <string>

class ConsoleApp{
public:
    ConsoleApp();
    ~ConsoleApp();

    bool commandLine();
private:
    Tree tree;

    unordered_map<string, void(ConsoleApp::*)()> sCmdMap; // 명령어만 있으면 되는 명령어
    unordered_map<string, void(ConsoleApp::*)()> mCmdMap; // 부가적인 정보가 필요한 명령어
    void exitCommand();
    void lsCommand();
    void cdCommand();
    void touchCommand();
};