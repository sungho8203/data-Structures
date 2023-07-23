#include <Graph.h> 

Graph::Graph() : curVertex(nullptr) {

}

Graph::~Graph(){

}

bool Graph::addVertex(string title){
    try{
        Graph::Vertex * newVertex = newVertex;
        newVertex->data.title = title;

        vertexList.add(newVertex);
        return true;
    }
    catch(std::bad_alloc ex){
        cout << "메모리 할당 실패" << endl;
        return false;
    }
}

bool Graph::addEdgs(string target1, string target2){
    try{
        Graph::Vertex * targetVertex1 = searchVertex(target1);
        Graph::Vertex * targetVertex2 = searchVertex(target2);

        Graph::Vertex ** tempIncidence;

        if (targetVertex1 == nullptr || targetVertex2 == nullptr || targetVertex1 == targetVertex2)
            return false;

        // 서로의 간선을 연결한다.
        tempIncidence = (Graph::Vertex **) malloc(sizeof(Graph::Vertex *) * 2);
        tempIncidence[0] = targetVertex1;
        tempIncidence[1] = targetVertex2;

        incidenceList.add(tempIncidence);

        targetVertex1->edgs.add(tempIncidence);
        targetVertex2->edgs.add(tempIncidence);

        return true;
    }
    catch(std::bad_alloc){
        return false;
    }
}

Graph::Vertex * Graph::searchVertex (string title){
    try{
        Graph::Vertex * resultVertex = nullptr;

        if(vertexList.setNextCurNode()){
            for(int i = 0; i < vertexList.getSize(); i++){
                if((resultVertex = vertexList++)->data.title == title)
                    return resultVertex;
            }
        }
        return nullptr;
    }
    catch(ListException ex){
        return nullptr;
    }
}

bool Graph::delVertex(string title){
    return true;
}

bool Graph::delEdgs(string target1, string target2){
    Graph::Vertex * refVertex = searchVertex(target1);
    Graph::Vertex ** delEdgs;

    if(refVertex->edgs.setNextCurNode()){
        for (int i = 0; i < refVertex->edgs.getSize(); i++){
            delEdgs = refVertex->edgs++;
            
            if (delEdgs[0]->data.title == target2 || delEdgs[1]->data.title == target2){
                refVertex->edgs.remove(delEdgs);
                incidenceList.remove(delEdgs);
                free(delEdgs);
                return true;
            }
        }
    }
    return false;
}