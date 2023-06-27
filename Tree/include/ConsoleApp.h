#pragma once

#include "./Tree.h"
#include <string>

class ConsoleApp{
public:
    ConsoleApp();
    ~ConsoleApp();

    void commandLine();
private:
    Tree tree;

    unordered_map<string, void(ConsoleApp::*)(vector<string>)> cmdMap; // 명령어만 있으면 되는 명령어
    void exitCommand(vector<string> cmdToken);
    void lsCommand(vector<string> cmdToken);
    void cdCommand(vector<string> cmdToken);
    void touchCommand(vector<string> cmdToken);
};