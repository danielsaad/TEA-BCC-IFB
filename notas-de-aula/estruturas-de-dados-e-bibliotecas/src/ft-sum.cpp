int sum(int i){
    int sum = 0;
    while(i>0){
        sum+=ft[i];
        i -= (i & -i);
    }
    return sum;
}