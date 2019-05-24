#include <bits/stdc++.h>

using namespace std;


using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;



enum{WHITE=0,GREY=1,BLACK=2};

// Variáveis globais

int dfs_n = 0; // Numeração da DFS
vector<vi> g; // Lista de adjacências
vi dfs_num; // Estrutura dfs_num
vi dfs_low; // Estrutura dfs_low
vi visited; // Marca o estado do vértice
stack<int> st; // Pilha para armazenar a componente fortemente conexa

/**
 * @brief A partir de um nó u, computa as componentes fortementes conexas
 * dos nós alcançáveis a partir de u
 * 
 * @param u Nó inicial.
 */
void scc(int u) {
    dfs_num[u] = dfs_low[u] = dfs_n;
    dfs_n++;
    // Marca o nó como em processamento
    visited[u] = GREY;
    // Insere o nó na pilha
    st.push(u);
    for (auto v : g[u]) {
        // Para cada aresta (u,v)
        if (visited[v] == WHITE) {
            // Se v não foi visitado, aplique o algoritmo recursivamente
            scc(v);
            // atualize o menor nó alcançável por u se preciso
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (visited[v] == GREY) {
            /** Se v foi visitado, porém não finalizado, então existe uma
             * back-edge de u para v, correspondendo a um ciclo, logo
             * atualiza-se dfs_low com a numeração de DFS de v, caso 
             * necessário
             **/
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
    /**
     * Caso dfs_low[u] == dfs_num[u] então todos os nós pertencentes à
     * componente fortemente conexa de u estão na pilha.
     **/
    if (dfs_low[u] == dfs_num[u]) {
        int v;
        /** Imprime os nós que compartilham a mesma componente 
         * fortemente conexa de u.
         */
        do {
            v = st.top();
            st.pop();
		    visited[v] = BLACK;
            cout << v << " "; 
        } while (u != v);
        cout << endl;
    }
}

/**
 * @brief Aplica o algoritmo scc para cada nó não visitado
 */
void find_scc(){
    for(size_t i=0;i<g.size();i++){
        if(visited[i]==WHITE){
            scc(i);
        }
    }
}