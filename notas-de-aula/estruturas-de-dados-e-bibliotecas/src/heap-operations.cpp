#include <iostream>      
#include <algorithm>     
#include <vector>       

using namespace std;

int main () {
    vector<int> v = {10,20,30,5,15};

    // Constrói a Heap a partir do vetor
    make_heap(v.begin(),v.end());
    std::cout << "Elemento de maior precedência   : " << v.front() << '\n';

    // Reestrutura a heap para remover o elemento de maior precedência
    std::pop_heap (v.begin(),v.end());
    // Remove o elemento de maior precedência
    v.pop_back();
    std::cout << "Elemento de maior precedência: " << v.front() << '\n';

    // Insere um elemento no fim do vetor e reestrutura a Heap
    v.push_back(99);
    std::push_heap (v.begin(),v.end());
    std::cout << "Maior elemento após inserção: " << v.front() << '\n';

    return 0;
}