#include <Graph.h> 

Graph::Graph() : curVertex(nullptr) {

}

Graph::~Graph(){

}

bool Graph::addVertex(string title){
    try{
        if (searchVertex(title) != nullptr)
            return false;

        Graph::Vertex * newVertex = new Graph::Vertex;
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

        Graph::Edgs * tempIncidence;

        // targetVertex가 존재해야 되고 같은 두 targetVertex가 같은 vertex면 안된다.
        if (targetVertex1 == nullptr || targetVertex2 == nullptr || targetVertex1 == targetVertex2)
            return false;

        if(findDataInVertex(targetVertex1, target2))
            return false;

        // 서로의 간선을 연결한다.
        tempIncidence = new Graph::Edgs;
        tempIncidence->vertex[0] = targetVertex1;
        tempIncidence->vertex[1] = targetVertex2;

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
    Graph::Vertex * deleteVertex = searchVertex(title);
    Graph::Edgs * deleteEdgs;

    if(deleteVertex->edgs.setNextCurNode()){
        for (int i = 0; i < deleteVertex->edgs.getSize(); i++){
            deleteEdgs = deleteVertex->edgs[i];
            
            incidenceList.remove(deleteEdgs);
            delete (deleteEdgs);
        }
    }
    deleteVertex->edgs.clear();

    delete (deleteVertex);
    vertexList.remove(deleteVertex);
    return true;
}

bool Graph::delEdgs(string target1, string target2){
    Graph::Vertex * refVertex = searchVertex(target1);
    Graph::Edgs * deleteEdgs;

    if(refVertex->edgs.setNextCurNode()){
        for (int i = 0; i < refVertex->edgs.getSize(); i++){
            deleteEdgs = refVertex->edgs++;
            
            if (deleteEdgs->vertex[0]->data.title == target2 || deleteEdgs->vertex[1]->data.title == target2){
                refVertex->edgs.remove(deleteEdgs);
                incidenceList.remove(deleteEdgs);
                delete (deleteEdgs);
                return true;
            }
        }
    }
    return false;
}

bool Graph::showGraph(){
    if (vertexList.emptyList()){
        cout << "빈 Graph 입니다.";
        return false;
    }

    cout << "Grap의 Vertex는 ";
    const char * seq = "";
    for (int i = 0; i < vertexList.getSize(); i++){
        printf("%s\"%s\"", seq, vertexList[i]->data.title.c_str());
        seq = " ,";
    }
    cout << " 입니다.\n" << endl;

    if (incidenceList.emptyList())
        cout << "현재 간선이 없습니다." << endl;
    else{
        cout << "Grap의 간선 List" << endl;
        for (int i = 0; i < incidenceList.getSize(); i++)
            printf("   \"%s\" ---- \"%s\"\n",
            incidenceList[i]->vertex[0]->data.title.c_str(),
            incidenceList[i]->vertex[1]->data.title.c_str());
    }

    return true;
}

#pragma region PRIVATE_METHOD

bool Graph::findDataInVertex(Graph::Vertex * findVertex, string title){
    bool result = false;
    
    for(int i = 0; i < findVertex->edgs.getSize() && !result; i++){
        result = (title == findVertex->edgs[i]->vertex[0]->data.title);
        result |= (title == findVertex->edgs[i]->vertex[1]->data.title);
    }

    return result;
}

#pragma endregion