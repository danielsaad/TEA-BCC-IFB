/***
 * (...)
 * Ordene as listas primeiramente
 * (...)
 ***/

gold = d = k = 0;

// Enquanto não se chega no fim de uma das listas
while(d<n && k<m){
    // Enquanto o diâmetro da cabeça é maior que a altura do cavaleiro
    while(dragon[d] > knight[k] && k<m){
        // Passe para o próximo cavaleiro 
        k++; 
    }
    if(k==m)
        break;
    gold+= knight[k];
    d++; 
    k++;
}
if(d==n)
    cout << gold << endl;
else
    cout << "Loowater is doomed!" << endl;
