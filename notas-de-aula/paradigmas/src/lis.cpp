/**
 * @brief Computa o tamanho da maior subsequência 
 * crescente de v
 * 
 * @param v entrada
 * @return int retorna o tamanho da maior 
 * subsequência crescente de v
 */
int lis(vector<int>& v){
    // Inicializamos uma tabela com 1s
    vector<int> dp(v.size(),1);
    // Tamanho da maior subsequência crescente
    int max_l = dp[0]; // caso base, dp[0] = 1
    for(size_t i =1;i<v.size();i++){
        for(size_t j=0;j<i;j++){
            /***
             * Testamos se conseguimos estender a maior 
             * subsequência crescente
             * que tem v[j] como último elemento
             ***/
            if(v[i]>v[j])
                /***
                 * Em caso positivo, dp[i] guarda a 
                 * maior extensão possível
                 ***/
                dp[i] = max(dp[i],dp[j]+1);
        }
        max_l = max(max_l,dp[i]);
    }
    return max_l;
}