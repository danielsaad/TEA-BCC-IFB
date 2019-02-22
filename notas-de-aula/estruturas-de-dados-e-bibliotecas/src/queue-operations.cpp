#include <iostream>
#include <queue>

using namespace std;

const int MAX = 5;

int main(){
    // Fila vazia de strings
    queue<string> q;
    // Lê MAX nomes e os coloca em uma fila
    for(int i=0;i<MAX;i++){
        string s;
        getline(cin,s);
        q.push(s);
    }

    // Enquanto a fila não está vazia,
    // imprima a frente da fila
    // e remova o elemento da frente. 
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    return 0;	
}