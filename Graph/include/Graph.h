#pragma once

#include <iostream>
#include "../../Tree/include/List.h" // Graph폴더와 Tree폴더가 같은 level에 존재해야된다.(따로 사용시 List.h 파일 include 폴더에 추가)

using namespace std;



class Graph{
public:
    struct Vertex{
    public:
        List<Vertex **> edgs; // vertex와 연결된(?) 간선들의 List

        struct Data{
            string title;
            // 데이터 추가
        }data;
    };
    
    List<Vertex *> vertexList;
    List<Vertex **> incidenceList; 

    // Method

    Graph();
    ~Graph();

    bool addVertex(string title);
    bool addEdgs(string target1, string target2);

    Graph::Vertex * searchVertex(string title);

    bool delVertex(string title);
    bool delEdgs(string target1, string target2);

private:
    Vertex * curVertex;
};