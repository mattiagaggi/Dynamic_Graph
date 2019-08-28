//
//  graph.cpp
//  dynamic_graph
//
//  Created by Mattia Gaggi on 1/21/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#include "graph.hpp"
#include <ctime>
#include <cstdlib>
using namespace std;

Graph::Graph(unsigned int size,float density): size(size),density(density){
    srand(time(0));
    graph = new float*[size];
    for (int i=0;i<size;i++){
        graph[i]=new float[size];
    }
    edges=Graph::initialise_edges(density);
}

unsigned int Graph::initialise_edges(float density){
    unsigned int tot_edges;
    for (int i=0; i<size; i++){
        for (int i2=0; i<size; i++){
            if (i2==i) graph[i][i2]=0;
            else{
                tot_edges++;
                graph[i][i2]= ( ( (float) rand() / (float) (RAND_MAX)) < density) * ( (float) rand() /  (float) (RAND_MAX) * (float) (MAXEDGELENGHT-MINEDGELENGHT) + MINEDGELENGHT );
            }
            
        }
    }
    return ((unsigned int)( (float)tot_edges/2.));
}

Graph::~Graph(){
    for (int i=0;i<size;i++){
        delete[] graph[i];
    }
    delete[] graph;
}


unsigned int Graph::V(void){
    return size;
}

unsigned int Graph::E(void){
    return edges;
}
