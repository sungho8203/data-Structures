#pragma once

#include "./Tree.h"

class ConsoleApp{
public:
    ConsoleApp();
    ~ConsoleApp();

    bool commandLine();
private:
    Tree tree;

    unordered_map<string, void(ConsoleApp::*)()> cmdMap;
    void exitCommand();
    void lsCommand();
    void cdCommand();
};