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

    unordered_map<string, void(ConsoleApp::*)(string)> cmdMap; // 명령어만 있으면 되는 명령어
    void exitCommand(string cmdData);
    void lsCommand(string cmdData);
    void cdCommand(string cmdData);
    void touchCommand(string cmdData);
};