#include <iostream>
#include <vector>

using namespace std;

class segment_tree{
private:
    // Vetor da árvore de segmentos
    vector<int> st;
    // Cópia do vetor original
    vector<int>& v;
    // size of v
    int n;

public:
    /**
     * @brief Constrói um objeto do tipo Árvore de Segmentos
     * 
     * @param vec vetor original 
     */
    segment_tree(const vector<int>& vec):v(vec){
        n = vec.size();
        // Aloca espaço para a árvore de segmentos
        st = vector<int>(4*n,0);
        // Constrói a partir da raiz (índice 1) e do intervalo [0,n-1]
        build(1,0,n-1);
    }
    /**
     * @brief Sobrecarga de rmq, deixa a chamada de função mais limpa
     * 
     * @param i limite inferior do intervalo da consulta.
     * @param j limite superior do intervalo da consulta
     * @return int RMQ(i,j)
     */
    int rmq(int i,int j){
        // Simplesmente chama a versão completa de rmq
        return rmq(1,0,n-1,i,j);
    }

private:
    /**
     * @brief Retorna o índice do filho da direita.
     * 
     * @param p índice do pai
     * @return int índice do filho da direita.
     */
    int left(int p){
        return p << 1;
    }
    /**
     * @brief Retorna o índice do filho da esquerda.
     * 
     * @param p índice do pai.
     * @return int índice do filho da direita.
     */
    int right(int p){
        return (p << 1) + 1;
    }
    /**
     * @brief Contrói a árvore de segmentos st
     * 
     * @param p índice do pai
     * @param i limite inferior do intervalo do nó p
     * @param j limite superior do intervalo do nó p
     */
    void build(int p,int i,int j){
        /***
         * Caso base: o nó com índice p corresponde a uma folha, então
         * st[p] = i
         ***/
        if(i==j){
            st[p] = i;
        }
        /***
         * Caso geral. O nó não é uma folha. Calculamos recursivamente as
         * respostas dos filhos da esquerda e da direita para poder calcular
         * a resposta nó com índice p
         ***/
        else{
            build(left(p),i,(i+j)/2);
            build(right(p),(i+j)/2 + 1,j);
            int a = st[left(p)];
            int b = st[right(p)];
            /***
             * Seja a a resposta do filho a esquerda e b a do filho da direita.
             * Pegamos o índice cujo valor é o menor e armazenamos em st[p].
             ***/
            st[p] = (v[a] <= v[b]) ? a : b;
        }
    }
    /**
     * @brief Executa a consulta de rmq
     * 
     * @param p índice do nó na árvore de segmentos
     * @param l limite inferior do intervalo do nó
     * @param r limite superior do intervalo do nó
     * @param i limite inferior do intervalo da consulta
     * @param j limite superior do intervalo da consulta
     * @return int RMQ(i,j)
     */
    int rmq(int p,int l,int r,int i,int j){
        // Se [l,r] é disjunto de [i,j] retorna indefinição
        if(i>r || j<l) return -1;
        // Se [l,r] está contido em [i,j], retorne st[p] = RMQ(l,r)
        if(l>=i && r<=j) return st[p];
        /***
         * Senão, obtenha recursivamente as respostas nos filhos da esquerda 
         * e direita e selecione a resposta que minimiza o valor do intervalo
         * [i,j]
         */
        int a = rmq(left(p),l,(l+r)/2,i,j);
        int b = rmq(right(p),(l+r)/2 + 1,r,i,j);
        if(a == -1) return b;
        if(b == -1) return a;
        return(v[a] <= v[b]) ? a : b;
    }
};


int main(){
    vector<int> v = {19,17,12,20,16,12,21};
    segment_tree segtree(v);
    cout << "RMQ(1,4) = " << segtree.rmq(1,4) << endl;
    return 0;
}