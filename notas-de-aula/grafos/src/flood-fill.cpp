/**
 * Coordenada das movimentações
 **/
int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

/**
 * @brief Flood-fill em um tabuleiro RxC
 * @param r número da linha
 * @param c número da coluna
 * @param c1 caractere de água
 * @param c2 caractere a substituir o caractere da água
 * @return Retorna a área do lago formado a partir da célula (r,c)
 */
int floodfill(int r, int c, char c1, char c2) {
    // Se está fora do grid, a área é 0
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    // Se a célula não é uma posição com água, a área é 0
    if (grid[r][c] != c1) return 0;
    // Caso contrário já temos área do lago igual a 1
    int ans = 1;
    // Marca a posição (r,c) como visitada
    grid[r][c] = c2;
    // Aplica a busca em profundidade (flood-fill) nas adjacências
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    // Retorna a área total do lago
    return ans;
}