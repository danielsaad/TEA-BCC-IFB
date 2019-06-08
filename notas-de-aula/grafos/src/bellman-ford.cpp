#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;

/***
 * Dividimos por dois para evitar overflow na soma 
 * de um valor INF com um valor positivo.
 ***/
const int INF = numeric_limits<int>::max()/2;

vector<int> cost;

/**
 * @brief Aplica o método de Bellman-Ford no grafo g para calcular
 * o custo do menor caminho entre u e qualquer outro nó de g
 * 
 * @param g Grafo
 * @param u Nó de partida
 */
void bellman_ford(vector<vii>& g,int u){

    cost.assign(g.size(),INF);
    // Inicializa o custo de u para ele mesmo
    cost[u] = 0;

    /***
     * Aplica o método de bellman ford: para cada aresta, aplique
     * a condição de relaxamento. Isso deve ser repetido |V| - 1 vezes,
     * pois um caminho possui no máximo |V|-1 arestas.
     ***/
    for(size_t k=0;k<g.size()-1;k++){
        for(size_t u=0;u<g.size;u++){
            for(auto& v: g[u]){
                cost[v.first] = min(cost[v.first],cost[u]+v.second);
            }
        }
    }

    /*** 
     * Realiza uma última verificação para checar se existem ciclos
     * negativos no grafo
     ***/
    bool has_negative_cycle = false;
    for(size_t u=0;u<g.size();u++){
        for(auto& v: g[u]){
            if(cost[u]+v.second < cost[v.first]){
                has_negative_cycle = true;
            }
        }
    }
}