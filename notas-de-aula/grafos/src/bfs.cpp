#include <bits/stdc++.h>

using namespace std;

const int INFINITY{ numeric_limits<int>::max() };

using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;

/***
 * Estrutura que diz a distância para o nó de origem.
 * Inicialmente inicializada com Infinito;
 ***/

vi d;

/***
 * Lista de adjacências de um grafo. Cada aresta é representada com um par,
 * contendo o nó destino e o peso da aresta. No caso de grafos sem peso, o
 * segundo membro do par pode ser ignorado
 ***/
vector<vii> adj_list;



/***
 * Busca em largura partindo de um nó u. Inicialmente, visita-se
 * os vizinhos de u, depois os vizinhos dos vizinhos de u, e assim por diante.
 * Uma fila é utilizada para implementar este comportamento
 ***/
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto& y: adj_list[x]){
            /** 
             * Se a distância até y.first é infinito, 
             * significa que ele não foi visitado 
             **/
            if(d[y.first]==INFINITY){
                d[y.first] = d[x]+1;
                q.push(y.first);
            }
        }
    }
}