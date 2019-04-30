/**
 * @brief Retorna o valor máximo considerando n itens cada um
 * com um valor e peso sem exceder uma capacidade
 * 
 * @param v valor dos itens
 * @param w peso dos itens
 * @param W capacidade máxima
 * @return valor máximo dos itens sem exceder a capacidade W
 */
int boolean_knapsack(vector<int>& v, vector<int>& w,int W){
    vector<vector<int>> dp(2,vector<int>(W+1,0));
    /***
     * Caso base, olhando só o primeiro item, pegamos ele
     * só quando a capacidade é maior ou igual ao peso dele
     ***/
    for(int i=0;i<=W;i++){
        if(i>=w[i]) dp[0][i] = v[i];
    }
    
    /***
     * Caso geral, a solução para os i primeiros itens vem da solução
     * dos i-1 primeiros itens com capacidade máxima de j
     * (o i-ésimo item não é incluído), ou da solução
     * dos i-1 priemiros itens com capacidade máxima j-w[i]
     *  mais o valor v[i] (o i-ésimo item é incluído)
     ***/
    int last = 0;
    int cur = 1;
    for(int i=1;i<v.size();i++){
        for(int j=0;j<=W;j++){
            dp[cur][j] = dp[last][j];
            if(j>=w[i])
                dp[cir][j] = max(dp[cur][j],dp[last][j-w[i]]+v[i])
        }
        swap(cur,j);
    }
    /*** 
     * A solução ótima tem que estar na célula que considera todos os 
     * itens e a capacidade máxima
     ***/
    return dp[last][W];
}