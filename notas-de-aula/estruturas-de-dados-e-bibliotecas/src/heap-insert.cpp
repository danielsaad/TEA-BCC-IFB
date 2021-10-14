template<typename T>
void heap_insert(vector<T>& v, T& value){
    // Inserimos o novo elemento como uma folha da heap
    v.push_back(value);
    // Aplicamos Heapify de baixo para cima a partir da folha
    heapify_bottom_up(v,v.size()-1);
}