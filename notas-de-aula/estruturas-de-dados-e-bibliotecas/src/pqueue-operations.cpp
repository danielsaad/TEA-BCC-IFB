#include <iostream>
#include <queue>

using namespace std;

const int MAX = 5;

struct pessoa{
    string nome;   
    int idade; 
    double renda_mensal;
    // O operador < é definido para estabelecer
    // prioridade entre duas pessoas
    // Critério: primeiro pessoas mais velhas e
    // caso tenham a mesma idade, selecionar aquela
    // com menor renda mensal.
    bool operator<(const pessoa& rhs) const{
        if(this->idade < rhs.idade){
            return true;
        }
        if(this->idade == rhs.idade){
            return this->renda_mensal > rhs.renda_mensal;
        }
        return false;
    }
};


void le_pessoa(pessoa& p){
    cout << "Digite o nome: ";
    getline(cin,p.nome);
    cout << "Digite a idade: ";
    cin >> p.idade;
    cout << "Digite a renda mensal em R$: ";
    cin >> p.renda_mensal;
    cin.ignore(1);
}

void imprime_pessoa(pessoa& p){
    cout << p.nome << "\n" << p.idade << "\n"
        << p.renda_mensal << "\n\n";
}
int main(){
    priority_queue<pessoa> pq;
    // MAX pessoas são lidas e inseridas em
    // uma fila de prioridade.
    for(int i=0;i<MAX;i++){
        pessoa p;
        le_pessoa(p);
        pq.push(p);
    }
    // As pessoas são retiradas da fila de prioridade
    // com base na ordem estabelecida pelo operador <
    while(!pq.empty()){
        pessoa p = pq.top();
        imprime_pessoa(p);
        pq.pop();
    }
    return 0;
}