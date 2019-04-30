

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
    int s = 0;
    for(int k=i;k<=ii;k++){
        for(int l=j;l<=jj;l++){
            s += M[k][l];
        }
    }
    return s;
}




/**
 * @brief Acha a maior soma dentre todos os possíveis retângulos.
 * 
 * @return int a maior soma.
 */
int find_max_sum(){
    int max_sum = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int ii=i;ii<n;ii++){
                for(int jj=j;jj<m;jj++){
                    max_sum = max(max_sum,sum(i,j,ii,jj));
                }
            }
        }
    }
    return max_sum;
}


