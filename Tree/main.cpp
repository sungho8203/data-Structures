#include "./include/Tree.h"
#include <string>
#include <exception>

int main(){
    Tree temp;

    temp.addCurNode("fasdf");
    temp.addCurNode("fasd");
    temp.addCurNode("fasd1");
    temp.showCurNodeData();
    temp.deleteCurNode();
    temp.showCurNodeData();
}