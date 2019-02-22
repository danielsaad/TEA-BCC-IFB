#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print_vector(vector<T>& v){
	for(auto value: v){
		cout << value;
	}
	cout << "\n";
}

int main(){
	// declara um vetor sem elementos
	vector<int> empty_vector(); 
	// declara um vetor de 100 posições inicializadas com 1
	vector<int> v(3,1); 
	// declara um vetor contendo os números inteiros de 1 a 5
	vector<int> v2 = {1,2,3,4,5}; 
	// Remove todos os dados do vetor v2
	v2.clear(); 
	// Insere o valor 3 na última posição de v (1,1,1,3);
	v.push_back(3); 
	// Insere o valor 4 na última posição de v (1,1,1,3,4);
	v.push_back(4); 
	// Remove o último elemento de v (1,1,1,3)
	v.pop_back(); 

	// Redimensiona v2 para 100 elementos. 
	v2.resize(10); 

	// Imprime o primeiro elemento do vetor v (1)
	cout << v.front() << "\n"; 
	// Imprime o último elemento do vetor v (3)
	cout << v.back() << "\n" ; 
	// Imprime o terceiro elemento do vetor v (1)
	cout << v[2] << "\n"; 
	// Imprime o tamanho do vetor (4)
	cout << v.size() << "\n"; 

	print_vector(v); // Imprime 1 1 1 3
	print_vector(v2); // O que será impresso?

	return 0;	
}