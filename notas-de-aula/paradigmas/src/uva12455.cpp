
// Gera todos os subconjuntos possíveis
bool res = false;
for (i = 0; i < (1 << n); i++) {
    int sum = 0;
    // Para cada elemento do conjunto, verifique se ele pertence a S
    for (int j = 0; j < n; j++){
        // Caso o j-ésimo bit esteja ligado, o j-ésimo elemento de S
        // Pertence ao conjunto
        if (i & (1 << j)){
            // Adiciona S[j] ao acumulador 
            sum += S[j];
        }
    }
    // Caso o subconjunto tenha soma X, a resposta é sim
    if (sum == X){
        ans = true;
    }
}