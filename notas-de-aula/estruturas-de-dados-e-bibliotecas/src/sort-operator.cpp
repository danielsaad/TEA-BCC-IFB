#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5;

struct pessoa{
    string nome;   
    int idade; 
    double renda_mensal;
    // O operador < é definido para estabelecer
    // uma ordem entre duas pessoas
    // Critério: primeiro pessoas mais novas e
    // caso tenham a mesma idade, selecionar aquela
    // com maior renda mensal.
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
    vector<pessoa> v;
    // MAX pessoas são lidas e inseridas em
    // um vetor.
    for(int i=0;i<MAX;i++){
        pessoa p;
        le_pessoa(p);
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    // O vetor é ordenado e as pessoas são impressas.
    for(auto p: v){
        imprime_pessoa(p);
    }
    return 0;
}