/**
 * @brief Computa a matriz S em tempo quadrático.
 * 
 */
void pre_process(){
    S[0][0] = M[0][0];
    for(int i=1;i<n;i++) S[i][0] = S[i-1][0] + M[i][0];
    for(int j=1;j<m;j++) S[0][j] = S[0][j-1] + M[0][j];
    for(int i=1;i<n;i++){
        for(j=1;j<m;i++){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1]+M[i][j];
        }
    }
}