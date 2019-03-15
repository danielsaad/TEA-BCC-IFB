
// Gera todas as possibilitades no intervalo [01234,98765]
for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
    int abcde = fghij * N; // Calcula abcde de fghij
    /***
     * used é uma sequência de bits de modo que o dígito i foi
     * utilizado se e somente se o i-ésimo bit desta sequência
     * está ligado. Obviamente o bit 0 estará ligado sempre que fghij < 10000.
     ***/
    int tmp, used = (fghij < 10000);
    tmp = abcde;

    /***
     *  Extrai os dígitos de tmp = abcde e marca os que foram usados 
     * na variável used
     ***/
    while (tmp) {
        used |= 1 << (tmp % 10);
        tmp /= 10;
    }
    /***
     *  Extrai os dígitos de tmp = fghij e marca os que foram usados 
     * na variável used.
     ***/
    tmp = fghij;
    while (tmp) {
        used |= 1 << (tmp % 10);
        tmp /= 10;
    }
    /***
     * Se todos os dígitos foram utilizados coletivamente, significa que
     * o par (A,B) foi encontrado.
     ***/
    if (used == (1<<10) - 1){
        printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
    }
}