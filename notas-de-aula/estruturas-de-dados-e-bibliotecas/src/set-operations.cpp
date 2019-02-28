#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> s;
    for(int opt=1;opt!=4;){
        string name;
        cout << "Opção 1: Inserir nome." << endl;
        cout << "Opção 2: Remover nome." << endl;
        cout << "Opção 3: Buscar nome." << endl;
        cout << "Opção 4: sair." << endl;
        cout << "\nDigite a opção: ";
        cin >> opt;
        cin.ignore(1); //Pula caractere de quebra de linha
        if(opt==1){
            cout << "Digite um nome a ser inserido: ";
            getline(cin,name);
            // Insere o nome e captura o retorno.
            // Caso o elemento já conste no conjunto
            // o segundo membro do par é falso.
            auto rv = s.insert(name);
            if(!rv.second){
                cout << "Nome já inserido, ignorando.\n";
            }
        }
        else if(opt==2){
            cout << "Digite o nome a ser removido: ";
            getline(cin,name);
            // Erase retorna o número de elementos apagados com sucesso
            auto rv = s.erase(name);
            if(rv>0){
                cout << name << " apagado com sucesso.\n";
            }
            else{
                cout << "Nome não constava no conjunto.\n";
            }
        }
        else if(opt==3){
            cout << "Digite o nome a ser buscado: ";
            getline(cin,name);
            if(s.find(name) != s.end()){
                cout << name << " consta no conjunto.\n";
            }
            else{
                cout << name << " não consta no conjunto.\n";
            }
        }
        else if(opt!=4) {
            cout << "Opção não reconhecida.";
        }
    }
    cout << "Imprimindo nomes em ordem lexicográfica\n";
    for(auto value: s){
        cout << value << endl;
    }
    return 0;
}
