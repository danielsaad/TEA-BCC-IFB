int sum(int i,int j){
    return sum(j) - sum(i-1);
}