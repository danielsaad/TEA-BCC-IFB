#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;

// Grafo
vector<vii> g;
// Vetor que marca os nós que já foram processados
vector<bool> processed;


/**
 * @brief Processa um nó u
 * 
 * @param pq fila de prioridades
 * @param u nó a ser processado
 */
void process(priority_queue<ii>& pq,int u){
    // marca u como processado
    processed[u] = true;
    // para cada vizinho de u
    for(auto& v: g[u]){
        // se o vizinho v.first não foi processado
        if(!processed[v.first]){
            /*** 
             * Insira na fila de prioridades a negação do custo
             * da aresta e a negação do identificador do nó vizinho.
             * Utiliza-se a negação pois a priority_queue é uma heap
             * de máximo.
             */
            pq.push({-v.second,-v.first});
        }
    }
}

/**
 * @brief Algoritmo de Prim
 * 
 * @return int retorna o custo da árvore espalhada mínima
 */
int prim(){
    int cost = 0;
    // marca todos os nós como não processados
    processed.assign(g.size(),false);
    // declara uma fila de prioridades que dá o próximo nó com menor custo
    priority_queue<ii> pq;
    // Processa o primeiro nó
    process(pq,0);
    // Enquanto houver nós a serem processados
    while(!pq.empty()){
        // Obtém o próximo nó de menor custo
        ii front = pq.top();
        pq.pop();
        // Restaura o peso e o id do nó ao negá-los
        auto u = -front.second;
        auto w = -front.first;
        // Se o nó não foi processado
        if(!processed[u]){
            // adicione ele á MST
            cost+=w;
            // Processe o nó
            process(pq,u);
        }
    }
    return cost;
}