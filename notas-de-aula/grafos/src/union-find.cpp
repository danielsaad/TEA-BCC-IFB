#include <bits/stdc++.h>

using namespace std;

class union_find{
public:
    /**
     * @brief Construtor, inicializa as estruturas
     * rank e parent, além de colocar o parent[i] para
     * cada elemento i
     * 
     * @param n número de elementos
     */
    union_find(int n){
        rank.assign(n,0);
        parent.assign(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    /**
     * @brief Retorna o elemento representativo do conjunto em que i
     * se encontra. Utiliza os ponteiros dos pais para localizar o
     * elemento representativo enquanto adota a técnica de path-compression;
     * 
     * @param i elemento inicial
     * @return int elemento representativo do conjunto em que i se encontra
     */
    int find(int i){
        return (parent[i]==i) ? i : (parent[i] = find(parent[i]));
    }

    /**
     * @brief Une os conjuntos em que i e j se encontram ao fazer
     * o merge entre duas árvores.
     * 
     * @param i primeiro elemento
     * @param j segundo elemento
     */
    void union_set(int i,int j){
        // Procura os elementos representativos de i e j
        auto x = find(i);
        auto y = find(j);
        // Se i e j não fazem parte do mesmo conjunto, a união é feita
        if(x!=y){
            if(rank[x] > rank[y]){
                parent[y] = x;
            }
            else{
                parent[x] = y;
                if(rank[x]==rank[y]){
                    rank[y]++;
                }
            }
        }        
    }

    /**
     * @brief Verifica se i e j estão no mesmo conjunto
     * 
     * @param i primeiro elemento
     * @param j segundo elemento
     * @return true caso i e j estejam no mesmo conjunto
     * @return false caso contrário
     */
    bool is_same_set(int i,int j){
        return find(i) == find(j);
    }
private:
    vector<int> parent,rank;
};