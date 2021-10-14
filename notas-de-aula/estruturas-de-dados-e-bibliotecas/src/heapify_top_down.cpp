template<typename T>
void heapify_top_down(vector<T>& v,size_t idx,size_t heap_size){
    while(idx < heap_size){
 
        // Seleciona os índices dos filhos da direita e da esquerda
        size_t l = 2*idx+1;
        size_t r = 2*idx+2; 

        size_t largest = idx;

        // Verifica se o filho da esquerda existe e ele
        // é maior que o pai
        if(l<heap_size && v[l] > v[largest]){
            // O filho da esquerda é considerado o maior
            largest = l;            
        }
        // Verifica se o filho da direita existe e ele é maior
        // do que o maior até o momento 
        if(r<heap_size && v[r]>v[largest]){
            largest = r;
        }

        if(idx == largest){
            // se o maior continua sendo o pai, paramos.
            break;
        }

        // Trocamos o pai com o maior dos filhos
        swap(v[idx],v[largest]);
        // Atualizamos o valor de idx para continuar o processo
        idx = largest;
    }
}