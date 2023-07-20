#include <Graph.h> 

Graph::Graph() : curVertex(nullptr) {

}

Graph::~Graph(){

}

bool Graph::addVertex(string title){
    try{
        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool Graph::addEdgs(string target){
    try{
        return true;
    }
    catch(exception ex){
        return false;
    }
}

bool Graph::searchVertex (string title){
    try{
        return true;
    }
    catch(exception ex){
        return false;
    }
}