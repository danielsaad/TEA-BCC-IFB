template<typename T>
void heap_insert(vector<T>& v, T& value){
    // Inserimos o novo elemento como uma folha da heap
    v.push_back(value);
    int root = v.size()-1;
    while(root!=0){
        // Verifica se o elemento inserido é maior do que o pai
        // Em caso verdadeiro, troque com o pai e continue o procedimento
        int parent = (root-1)/2;
        if(v[parent]<v[root]){
            // Trocamos o elemento recém inserido pelo seu pai e continuamos
            // o processo
            swap(v[parent],v[root]);
            root = parent;
        }
        else{
            break;
        }
    }
}