//
//  graph.hpp
//  dynamic_graph
//
//  Created by Mattia Gaggi on 1/21/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>


const int MAXEDGELENGHT=10, MINEDGELENGHT=1;

class Graph{
    
    Graph(unsigned int n_nodes, float density);
    
    ~Graph();
    
    unsigned int initialise_edges(float density);
    
    unsigned int V(void);
    
    unsigned int E(void);
    
    
private:
    
    float** graph;
    unsigned int size;
    unsigned int edges;
    float density;
    
};

#endif /* graph_hpp */
