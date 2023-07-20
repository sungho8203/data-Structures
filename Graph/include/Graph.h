#pragma once

#include <iostream>
#include "../../Tree/include/List.h" // Graph폴더와 Tree폴더가 같은 level에 존재해야된다.(따로 사용시 List.h 파일 include 폴더에 추가)

using namespace std;


class Graph{
public:
    // 데이터
    struct Data{
        string title;
        // 데이터 추가
    };

    struct Vertex;

    struct Vertex{
        List<Graph::Vertex *> edgs; // vertex와 연결된(?) 간선들의 List
        Data data;
    };

    List<Graph::Vertex *> vertexList; // vertex의 간선들

    // Method

    Graph();
    ~Graph();

    bool addVertex(string title);
    bool addEdgs(string target);

    bool searchVertex(string title);

private:
    Graph::Vertex * curVertex;
};