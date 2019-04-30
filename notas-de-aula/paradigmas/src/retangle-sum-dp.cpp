
/**
 * @brief Retorna a soma do retângulo definido pelas coordenadas 
 * (i,j) e (ii,jj).
 * 
 * @param i linha do canto superior esquerdo.
 * @param j coluna do canto superior esquerdo
 * @param ii linha do canto inferior direito
 * @param jj coluna do canto inferior direito
 */
int sum(int i,int j,int ii,int jj){
    int a = S[ii][jj];
    int b = S[i-1][jj];
    int c = S[ii][j-1];
    int d = S[i-1][j-1];
    return a-b-c+d;
}
