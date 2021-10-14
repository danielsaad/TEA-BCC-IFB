#include <bits/stdc++.h>

using namespace std;

int M,C;
vector<vector<int>> price;
vector<vector<int>> memo;
vector<int> quantity;

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
    if(memo[current_m][idx]!=-1){
        return memo[current_m][idx];
    }
    int ans = numeric_limits<int>::min();
    for(int i=0;i<quantity[idx];i++){
        ans = max(ans,shop(current_m-price[idx][i],idx+1));
    }
    memo[current_m][idx] = ans;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> M >> C;
        quantity.assign(C,0);
        price.clear();
        price.resize(C);
        memo.assign(M+1,vector<int>(21,-1));
        for(int i=0;i<C;i++){
            cin >> quantity[i];
            price[i].resize(quantity[i]);
            for(int j=0;j<quantity[i];j++){
                cin >> price[i][j];
            }
        }
        int ans = shop(M,0);
        if(ans<0)
            cout << "no solution" << endl;
        else
            cout << ans << endl;

    }
}