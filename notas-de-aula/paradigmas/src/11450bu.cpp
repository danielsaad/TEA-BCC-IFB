#include <bits/stdc++.h>

using namespace std;

int M,C;
vector<vector<int>> price;
vector<int> quantity;

void solve(){
    vector<vector<bool>> dp;    
    dp.assign(C+1,vector<bool>(M+1,false));
    
    // Caso base
    for(int i=0;i<quantity[0];i++){
        /***
         * Considerando apenas o primeiro tipo, verificamos cada item 
         * deste tipo e, caso o preço dele seja menor que o montante inicial
         * indicamos que conseguimos pagar a quantia.
         ***/
        if(M - price[0][i] >= 0){
            dp[0][M-price[0][i]]=true;
        }
    }

    // Caso geral, para cada tipo de item
    for(int k=1;k<C;k++){
        // Para cada quantia, de 0 a M
        for(int m = 0 ;m<=M;m++){
            /***
             * Se for possível pagar o valor m utilizando os k-1 primeiros
             * itens, testamos os itens do k-ésimo tipo
             ***/
            if(dp[k-1][m]){
                for(int i=0;i<quantity[k];i++){
                    /*** Se é possível incluir o i-ésimo tipo na solução
                     * respeitando o teto m, marcamos como verdadeiro ***/
                    if(m - price[k][i] >= 0){
                        dp[k][m-price[k][i]]=true;
                    }
                }
            }
        }
    }

    /*** Verificamos qual a maior quantia que é possível pagar com os C
     * items ***/

    int ans;
    for(ans = 0; ans<=M && !dp[C-1][ans];ans++);

    if(ans == M+1)
        cout << "no solution" << endl;
    else
        cout << M - ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> M >> C;
        quantity.assign(C,0);
        price.clear();
        price.resize(C);
        for(int i=0;i<C;i++){
            cin >> quantity[i];
            price[i].resize(quantity[i]);
            for(int j=0;j<quantity[i];j++){
                cin >> price[i][j];
            }
        }
        solve();
    }
}