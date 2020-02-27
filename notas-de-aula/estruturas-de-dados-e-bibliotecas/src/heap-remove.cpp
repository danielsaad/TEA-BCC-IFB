template<typename T>
void heap_remove(vector<T>& v){
    int root = 0;
    int largest;
    std::swap(v[0],v.back());
    // Enquanto não for uma folha
    while(root<v.size()/2){
        int l,r;
        // Seleciona os índices dos filhos da direita e da esquerda
        l = root*2 +1;
        r = root*2 +2;
        // O filho da esquerda é considerado o maior
        largest = l;
        // Se o filho da direita existe e ele é maior do que o filho
        // da esquerda, atualizamos largest para o filho da direita.
        if(r<v.size() && v[r]>v[l]){
            largest = r;
        }
        // Trocamos o pai com o maior dos filhos
        swap(v[root],v[largest]);
        // Atualizamos o valor de root para continuar o processo
        root = largest;
    }
    v.pop_back();
}