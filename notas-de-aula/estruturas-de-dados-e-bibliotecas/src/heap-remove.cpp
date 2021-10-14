template<typename T>
void heap_remove(vector<T>& v){
    // trocamos o elemento da raiz pela última folha
    swap(v.front(),v.back());
    // Aplicamos heapify_top_down a partir da raiz
    //desconsiderando o último elemento, que será removido
    heapify_top_down(v,0,v.size()-1);
    // Removemos o último elemento
    v.pop_back();
}