int sum(int i){
    int sum = 0;
    while(i>0){
        sum += ft[i];
        // Vai para o próximo nó que continua a cobrir o intervalo.
        i -= i & ~i; 
    }
}