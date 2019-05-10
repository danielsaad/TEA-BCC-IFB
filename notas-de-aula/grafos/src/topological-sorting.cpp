#include <bits/stdc++.h>

using namespace std;

enum{NOT_VISITED,VISITED};

using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;


/***
 * Lista de adjacências de um grafo. Cada aresta é representada com um par,
 * contendo o nó destino e o peso da aresta. No caso de grafos sem peso, o
 * segundo membro do par pode ser ignorado
 ***/
vector<vii> adj_list;

/***
 * dfs_num marca se um nó foi visitado ou não. Deve ser utilizado em uma
 * busca em profundidade para que ela não proceda a nós que já 
 * foram visitados de modo a evitar um laço infinito. Inicialmente,
 * deve ser inicializada com NOT_VISITED
 ***/
vi dfs_num;


/**
 * tp é o vetor contendo a ordem dos vértices segundo a ordenação
 * topológica
 **/
vi tp;


/***
 * Busca em profundidade, parte de um nó u e, para cada vizinho não visitado,
 * faz a chamada recursiva para este vizinho.
 ***/
void dfs(int u){
    dfs_num[u] = VISITED;
    for(auto& v: adj_list[u]){
        if(dfs_num[v.first]==NOT_VISITED){
            dfs(v.first);
        }
    }
    tp.push_back(u);
}

// reverse(tp.begin(),tp.end()) 

