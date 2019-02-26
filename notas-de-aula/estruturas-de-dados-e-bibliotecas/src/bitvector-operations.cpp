#include <cstdint>
#include <vector>

using namespace std;

/**
 * @brief Liga o k-ésimo bit do vetor 
 * @param v: vetor de bits
 * @param k: o bit a ser ligado
 */
void set_bit(vector<uint64_t>& v,size_t k){
    v[k>>6] |= (1ULL << (k & (63)));
}

/**
 * @brief Desliga o k-ésimo bit do vetor 
 * @param v: vetor de bits
 * @param k: o bit a ser ligado
 */
void reset_bit(vector<uint64_t>& v,size_t k){
    v[k>>6] &= ~(1ULL << (k & (63)));
}

/**
 * @brief Alterna o k-ésimo bit do vetor 
 * @param v: vetor de bits
 * @param k: o bit a ser ligado
 */
void flip_bit(vector<uint64_t>& v,size_t k){
    v[k>>6] ^= 1ULL << (k & (63));
}

/**
 * @brief Consulta o k-ésimo bit do vetor 
 * 
 * @param v: vetor de bots
 * @param k: o bit a ser desligado 
 * @return true caso o k-ésimo bit seja 1
 * @return false caso o k-ésimo bit seja 0
 */
bool query_bit(vector<uint64_t>& v,size_t k){
    return v[k>>6] & (1ULL << (k & (63)));
}