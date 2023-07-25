#include <Graph.h>

int main(){
    Graph temp;
    temp.addVertex("1");
    temp.addVertex("2");
    temp.addVertex("3");

    temp.addEdgs("1", "2");
    temp.addEdgs("1", "3");
    temp.addEdgs("1", "2");

    temp.delVertex("3");

    temp.showGraph();
    return 0;
}