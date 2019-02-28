#include <iostream>
#include <vector>

using namespace std;

class fenwick_tree{
public:
    
private:
    vector<int> ft;
    size_t n;

public:
    fenwick_tree(vector<int>& v){
        vector<int> c = v;
        n = v.size();
        // Cria a soma cumulativa
        cout << " c = ";
        for(size_t i=1;i<v.size();i++){
            c[i] = c[i-1]+v[i];
            cout << c[i] << " ";
        }
        cout << endl;
        build_ft(c);
    }
    int sum(int i){
        int sum = 0;
        while(i>0){
            sum+=ft[i];
            i -= (i & -i);
        }
        return sum;
    }
    int sum(int i,int j){
        return sum(j) - sum(i-1);
    }
    void update(int i,int val){
        while(i<n){
            ft[i] += val;
            i += (i & -i);
        }
    }

private:
    void build_ft(vector<int>& c){
        // Inicializa ft
        cout << "ft = ";
        ft.assign(c.size(),0);
        for(size_t i=1;i<c.size();i++){
            size_t offset = (i & -i);
            ft[i] = c[i] - c[i-offset];
            cout << ft[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    // Vetor com base no índice 1.
    vector<int> v = {0,1,3,2,5,2,8,7,3,0,4};
    fenwick_tree fent(v);
    for(size_t i=1;i<v.size();i++){
        cout << "sum(" << i << ") = " << fent.sum(i) << endl;
    }
    cout << "Atualizando FT" << endl;
    fent.update(3,-1);
    fent.update(2,5);
    for(size_t i=1;i<v.size();i++){
        cout << "sum(" << i << ") = " << fent.sum(i) << endl;
    }
    cout << "sum(2,6) = " << fent.sum(2,6) << endl;
    return 0;
}