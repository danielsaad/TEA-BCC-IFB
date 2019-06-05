#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;


/**
 * @brief Aplica o método de kruskal sobre o grafo.
 * 
 * @param edges um vetor contendo um par (peso, aresta), indicando
 * o peso de cada aresta do grafo. Cada aresta por sua vez é identificada
 * usando um par de vértices
 * @param n número de vértices do grafo
 * @return int o peso da árvore espalhada mínima
 */
int kruskal(vector<pair<int,ii>>& edges, int n){
    int cost = 0;
    // Ordena pelo peso
    sort(edges.begin(),edges.end());
    // Cria uma estrutura de conjuntos disjuntos de tamanho n;
    union_find uf(n);
    // Para cada aresta em ordem crescente de peso
    for(size_t i=0;i<edges.size();i++){
        /***
         * Caso os vértices das arestas estejam em componentes
         * distintas, a aresta tem que estar na árvore espalhada
         * mínima
         */
        if(!uf.is_same_set(edges[i].second.first,edges[i].second.second)){
            // Adiciona o peso da aresta no custo da MST
            cost += edges[i].first;
            // Une os dois vértices em uma mesma componente conexa
            uf.union_set(edges[i].second.first,edges[i].second.second);
        }
    }
    return cost;
}