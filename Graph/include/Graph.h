#pragma once

#include <iostream>
#include "../../Tree/include/List.h" // Graph폴더와 Tree폴더가 같은 level에 존재해야된다.(따로 사용시 List.h 파일 include 폴더에 추가)

using namespace std;



class Graph{
public:
    struct Vertex; // struct Edgs의 edgs요소의 선언을 위한 전방 선언

    struct Edgs{ // 실제 간선 데이터를 저장하는 공간
        Vertex * vertex[2]; // Edgs로 연결된 두 정점
        // int wieght;
    };

    struct Vertex{
    public:
        List<Graph::Edgs *> edgs; // 각 정점에 맞는 간선들을 엮어주는 변수

        struct Data{
            string title;
            // 데이터 추가
        }data;
    };
    
    List<Vertex *> vertexList;
    List<Graph::Edgs *> incidenceList; // 간선 데이터를 엮어주는 변수

    // Method

    Graph();
    ~Graph();

    bool addVertex(string title);
    bool addEdgs(string target1, string target2);

    Graph::Vertex * searchVertex(string title);

    bool delVertex(string title);
    bool delEdgs(string target1, string target2);

    bool showGraph();

private:
    Vertex * curVertex;

    bool findDataInVertex(Graph::Vertex * findVertex, string title);
};