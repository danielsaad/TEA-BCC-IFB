#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Realiza o backtracking para encontrar a melhor solução. Obviamente
 * a chamada inicial deve ser backtracking(M,0).
 * 
 * @param current_m montante atual
 * @param idx: indíce do tipo da peça de roupa considerada
 * @return int o máximo valor que pode ser gasto sem exceder a quantia M ou
 * o menor inteiro possível caso não haja solução.
 */
int backtracking(int current_m,int idx){
    if(current_m < 0){
        // Caso excedamos  o montante M, retorna-se um número negativo grande
        return numeric_limits<int>::min();
    }
    if(idx==C && current_m >=0){
        // Pegamos C elementos de diferentes tipos
        return M - current_m;
    }

    /*** 
     * Inicializamos a resposta como número negativo, representando a 
     * impossibilidade da solução.
     ***/
    int ans = numeric_limits<int>::min();

    for(int i=0;i<qtd[idx];i++){
        /***
         * Para cada uma das peças do tipo idx, resolva o problema
         * recursivamente considerando que a i-ésima peça do tipo IDX foi
         * escolhida, subtraindo sempre o preço da peça do tipo idx do montante
         * atual
         ***/
        ans = max(ans,backtracking(current_m-preco[idx][i],idx+1));
    }
    return ans;
}
