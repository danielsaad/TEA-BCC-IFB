int update(int i,int val){
    int sum = 0;
    while(i<=n){
        ft[i] += val;
        // Vai para o próximo nó que contém o índice i
        i += i & ~i; 
    }
}