#include <iostream>
#include <stack>

using namespace std;

const int MAX = 5;

int main(){
    // Pilha vazia de strings
    stack<string> stck;
    // Lê MAX nomes e os coloca em uma pilha
    for(int i=0;i<MAX;i++){
        string s;
        getline(cin,s);
        stck.push(s);
    }
    // Enquanto a pilha não está vazia
    // imprima o topo da pilha
    // e remova o elemento do topo 
    while(!stck.empty()){
        cout << stck.top() << endl;
        stck.pop();
    }
    return 0;	
}
