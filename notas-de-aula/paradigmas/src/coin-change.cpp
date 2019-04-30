/**
 * @brief Retorna o número mínimo de moedas de um conjunto v
 * a ser utilizadas para págar um troco W. Adimite-se
 * que existem infinitdas moedas de cada valor de v.
 * 
 * @param v valor das moedas
 * @param W valor do troco.
 * @return número mínimo de moedas para pagar W admitindo que
 * podemos utilizar várias moedas de um mesmo valor.
 */
int boolean_knapsack(vector<int>& v,int W){
    vector<vector<int>> dp(v.size(),vector<int>(W+1,0));
    const int infinity = numeric_limits<int>::max() - 1;
    /***
     * Caso base: quando não há o que pagar, utiliza-se 0
     * moedas
     ***/
    dp[0][0] = 0;

    /***
     * Caso base, olhando só o primeiro item, pagamos só 
     * quando o valor a ser pago é divisível por v[0].
     ***/
    for(int j=1;j<=W;j++){
        if(j%v[0]==0) dp[0][j] = j/v[0];
        else dp[0][j] = infinity;
    }    
    /***
     * Caso geral, a solução para as i primeiras moedas
     * vem dos i-1 primeiros itens com troco  j
     * (a i-ésimo moeda não é incluída), ou da solução
     * das i primeiras moedas com troco j-v[i] mais uma
     * moeda (a i-ésima).
     ***/
    for(int i=1;i<v.size();i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = min(dp[i][j],dp[i-1][j-v[i]]+1)
        }
    }
    /*** 
     * A solução ótima tem que estar na célula que considera todas
     * as moedas e o troco a ser pago.
     ***/
    return dp[v.size()-1][W];
}