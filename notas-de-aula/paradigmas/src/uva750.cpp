#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

// Posição da rainha em cada coluna
int row[8];
// Posição da primeira rainha
int a, b;
// Contador da linha
int lineCounter;


// Tenta inserir a c-ésima rainha na linha r da c-ésima coluna
bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++){
        // Para cada uma das c-1 rainhas anteriores, checa se a nova rainha
        // Está na mesma linha ou diagonal
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))){
            // Se sim, não é possível inserir a c-ésima rainha na posição
            // r da c-ésima coluna
            return false;
        }
    }
    return true; 
}



void backtrack(int c) {
    /***
     * Se o número de rainhas inseridas é 8 e existe uma rainha na posição 
     * (a,b), então é uma solução válida 
     ***/
    if (c == 8 && row[b] == a) {
        ++lineCounter;
        cout << setw(2) << lineCounter << "      "  << row[0]+1;
        for (int j = 1; j < 8; j++){ 
            cout << " " <<  row[j] + 1;
        }
        cout << endl;
        return;
    }
    // Para cada posição possível da coluna, tenta inserir a rainha
    for (int r = 0; r < 8; r++){
        // Tenta inserir a c-ésima rainha na posição r da coluna
        if (place(r, c)) {
            // Se for possível, insere a rainha e tenta inserir a próxima
            // recursivamente
            row[c] = r; 
            backtrack(c + 1);
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        // Posição da primeira rainha
        cin >> a >> b;
        // Conversão para base 0
        a--; b--;
        // Zera o vetor
        memset(row, 0, sizeof row); 
        lineCounter = 0;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        // Generate solutions
        backtrack(0);
        if (tc) 
            cout << endl;
    } 
    return 0;
}
