#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;

const int INF = numeric_limits<int>::max();

// Vetores de custo e processamento
vector<int> cost;
vector<bool> processed;

/**
 * @brief Dado um grafo g e um nó de partida u, calcula o vetor
 * cost, que contém o tamanho do menor caminho entre u e qualquer
 * outro vértice de g
 * 
 * @param g grafo
 * @param u nó de partida
 */
void dijkstra(vector<vii>& g,int u){
    // Inicializa o custo de todos os nós como infinito
    cost.assign(g.size(),INF);
    // Marca todos os nós como não processados
    processed.assign(g.size(),false);

    priority_queue<ii> pq;
    // O custo do nó de partida só pode ser zero
    cost[u] = 0;
    // Insere o nó de partida na fila de prioridades
    pq.push({-cost[u],u});

    // Enquanto houver nós a serem retirados da fila de prioridades
    while(!pq.empty()){
        // Obtém o próximo nó de menor custo
        int v = pq.top().second;
        // Remove o nó da fila de prioridades
        pq.pop();
        // Se o nó já foi processado, pule esta iteração
        if(processed[v]){ 
            continue;
        }
        // Marque o nó como processado
        processed[v] = true;
        
        /***
         * Para cada vizinho w de v, verifique a condição de relaxamento,
         * isto é, se o custo de u até w for maior do que o custo de u
         * até v mais o peso da aresta (v,w), atualize o custo de u até
         * w.
         ***/
        for(auto& w: g[v]){
            if(!processed[w.first] && cost[w.first] > cost[v]+w.second){
                cost[w.first] = cost[v] + w.second;
                /***
                 * Após a atualização, insira o nó w com o custo atualizado
                 * na fila de prioridades. Aqui inserimos a negação do custo
                 * pois por padrão, a fila de prioridades é uma heap de 
                 * máximo
                 ***/
                pq.push({-cost[w.first],w.first});
            }
        }
    }
}
