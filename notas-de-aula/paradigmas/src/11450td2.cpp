
int shop(int current_m, int idx){
    if(current_m<0){
        /*** Caso base, retornamos um inteiro negativo grande caso o 
         * montante atual seja negativo 
         ***/
        return numeric_limits<int>::min();
    }
    if(idx==C){
        /*** Caso contrário, chegamos em uma solução, não necessariamente
         * ótima, e o valor total gasto é M - current_m */
        return M-current_m;
    }
    // Verificamos se o problema já foi resolvido
    int& ans = memo[current_m][idx];
    if(ans !=-1) return ans;
    for(int i=0;i<quantity[idx];i++){
        ans = max(ans,shop(current_m-price[idx][i],idx+1));
    }
    return ans;
}