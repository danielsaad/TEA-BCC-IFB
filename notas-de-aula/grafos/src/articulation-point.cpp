#include <bits/stdc++.h>

using namespace std;


using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;



enum{NIL = -1, WHITE=0,GREY=1,BLACK=2};

// Variáveis globais

int dfs_n = 0; // Numeração da DFS
vector<vi> g; // Lista de adjacências
vi dfs_num; // Estrutura dfs_num
vi dfs_low; // Estrutura dfs_low
vi visited; // Marca o estado do vértice
vector<bool> articulation_vertex;  // Marca quais vértices são pontos de articulação
vi parent; // Marca quem são os pais de cada nó na árvore de DFS. Inicializado com NIL.

/**
 * @brief A partir de um nó u, computa os vértices de articulação 
 * que são alcançáveis a partir de u.
 * 
 * @param u Nó inicial.
 */
void dfs_ap(int u) {
    dfs_num[u] = dfs_low[u] = dfs_n;
    dfs_n++;
    // Marca u como visitado
    visited[u] = BLACK;
    // Número de vizinhos imediatos de u não visitados
    int children = 0;
    for (auto v : g[u]) {
        // Para cada aresta (u,v)
        if (visited[v] == WHITE) {
            // Se v não foi visitado, aplique o algoritmo recursivamente
            children++;
            parent[v] = u;
            dfs_ap(v);
            // atualize o menor nó alcançável por u se preciso
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            /** Se u é a raiz da DFS e possui mais de um filho,
             * então u é um ponto de articulação
             */  
            if(parent[u] == NIL && children>1){
                articulation_vertex[u] = true;
            }
            /** Se u não é a raiz da DFS e o vértice com numeração mais
             * baixa alcançável por v é maior ou igual a numeração de u,
             * então u é um ponto de articulação.
             */
            if(parent[u] !=NIL  && dfs_low[v]>=dfs_num[u]){
                articulation_vertex[u] = true;
            }
            
        }
        /** Se v já foi visitado, então (u,v) é uma back-edge. Se
         * essa aresta não forma um ciclo imediato, então atualiza-se
         * low[u]
         */ 
        else if (v!=parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

/**
 * @brief Aplica o algoritmo dfs_ap para cada nó não visitado
 */
void find_ap(){
    for(size_t i=0;i<g.size();i++){
        if(visited[i]==WHITE){
            dfs_ap(i);
        }
    }
    for(size_t i=0;i<g.size();i++){
        if(articulation_vertex[i]){
            cout << i << " is an articulation vertex\n";
        }
    }
}