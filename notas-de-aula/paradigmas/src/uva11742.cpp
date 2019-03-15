int count = 0;
vector<int> perm;
// Perm = {0,1,...,n-1}
for(int i=0;i<n;i++){
    perm.push_back(i);
}
// Gera todas as permutações
do{
    // Verifica se a permutação é consistente com as restrições
    if(check(perm,restricoes)){
        // Se for o caso, incremente o número de possibilidades
        count++;
    }
}while(next_permutation(perm.begin(),perm.end()));

cout << count << endl;
