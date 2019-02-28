#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5;

struct pessoa{
    string nome;   
    int idade; 
    double renda_mensal;
};

bool cmp_pessoa(const pessoa& lhs, const pessoa& rhs){
    // A função estabelece uma ordem entre duas pessoas
    // Critério: primeiro pessoas mais novas e
    // caso tenham a mesma idade, selecionar aquela
    // com maior renda mensal.
    if(lhs.idade < rhs.idade){
        return true;
    }
    if(lhs.idade == rhs.idade){
        return lhs.renda_mensal > rhs.renda_mensal;
    }
    return false;
}


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
    // Ordenação de acordo com um functor
    sort(v.begin(),v.end(),cmp_pessoa());
    // O vetor é ordenado e as pessoas são impressas.
    for(auto p: v){
        imprime_pessoa(p);
    }
    return 0;
}