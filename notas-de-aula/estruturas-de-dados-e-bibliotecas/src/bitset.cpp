#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // Criação de uma sequência estática de 10 bits
    bitset<10> b;
    // Ligamos os bits 0, 5 e 7
    b.set(0);
    b.set(5);
    b.set(7);

    for(size_t i=0;i<b.size();i++){
        cout << "Valor do bit " << i << ": " << b[i] << "\n";
    }
    return 0;
}
