#include <bits/stdc++.h>

using namespace std;

enum{WHITE=-1,BLUE=0,RED=1};

using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;

/***
 * Estrutura que diz a cor do nó.
 * color[u] = -1 se u  é branco, isto é, não foi visitado.
 * color[u] = 0 se u é azul
 * color[u] = 1 se u é vermelho.
 * Inicialmente todos os nós são brancos
 ***/

vi color;

/***
 * Lista de adjacências de um grafo. Cada aresta é representada com um par,
 * contendo o nó destino e o peso da aresta. No caso de grafos sem peso, o
 * segundo membro do par pode ser ignorado
 ***/
vector<vii> adj_list;



/**
 * @brief Busca em largura partindo de um nó u para verificar se um 
 * grafo é bipartido.
 * 
 * @param u nó inicial
 * @return true se o grafo é bipartido
 * @return false se o grafo não é bipartido.
 */
bool bfs(int u){
    queue<int> q;
    // u é pintado de vermelho e colocado na fila0
    q.push(u);
    color[u] = RED;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto& y: adj_list[x]){
            /***
             * Se a cor do vizinho de x é branca, ele é pintado da cor
             * oposta de x
             ***/
            if(color[y.first]==WHITE){
                color[y.first] = 1-color[x];
                q.push(y.first);
            }
            /***
             * Se x e seu vizinho y tem a mesma cor, o grafo não
             * pode ser bipartido
             ***/
            else if(color[y.first]==color[u]){
                return false;
            }
        }
    }
    return true;
}