#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

// Dividimos por 2 para evitar overflow na soma entre dois valores INF
const int INF = numeric_limits<int>::max()/2;

/**
 * @brief Dado um grafo representado por uma uma matrix de 
 * adjacências, calcule o menor caminho entre quaisquer par de vértices.
 * Ao término do algoritmo, a matriz de adjacências na posição g[u][v]
 * contém o custo do menor caminho entre u e v; 
 * 
 * @param g Grafo representado por uma matriz de adjacências
 */
void floyd_warshall(vector<vi>& g){

    /***
     * Caso base, o custo de cada nó para ele mesmo é zero e o custo
     * de todo nó u para todo nó v conectado por uma aresta (u,v) é o
     * peso da aresta (u,v). Caso contrário, o custo de u para v é infinito.
     ***/

    for(size_t i=0;i<g.size();i++){
        for(size_t j=0;j<g.size();j++){
            /***
             * Se não existe aresta de i para j, então a distância de
             * i para j é sinalizada como infinito
             ***/
            if(g[i][j]==-1){
                g[i][j] = INF;
            }
        }
        // Distância de um nó para ele mesmo é 0
        g[i][i] = 0;
    }

    /***
     * Calcula a menor distância entre todos os nós utilizando
     * os nós {0,1,2,...,k}
     ***/
    for(int k=0;k<g.size();k++){
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g.size();j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}