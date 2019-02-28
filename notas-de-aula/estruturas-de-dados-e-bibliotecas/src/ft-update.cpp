void update(int i,int val){
    while(i<n){
        ft[i] += val;
        i += (i & -i);
    }
}