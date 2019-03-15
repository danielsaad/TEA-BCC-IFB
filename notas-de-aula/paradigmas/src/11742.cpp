#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;


struct solver{
    int n,m;
    vector<tuple<int,int,int>> constraint;
    bool read_input(){
        // Limpa o vetor de constraint
        constraint.clear();
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            constraint.push_back(make_tuple(a,b,c));
        }
        return n || m;
    }
    bool check(vector<int>& p){
        bool ok = true;
        vector<int> pos(p.size(),0);
        for(size_t i=0;i<p.size();i++){
            pos[p[i]] = i;
        }
        for(const auto& value: constraint){
            int a,b,c;
            std::tie(a,b,c) = value;
            // cout << a << " " << b << " " << c << endl;
            if(c>0){
                ok = abs(pos[a]-pos[b]) <= c;
            }
            else{
                ok = abs(pos[a]-pos[b]) >= -c;
            }
            if(!ok){
                break;
            }
        }
        return ok;
    }
    void solve(){
        int count = 0;
        vector<int> perm;
        for(int i=0;i<n;i++){
            perm.push_back(i);
        }
        do{
            if(check(perm)){
                count++;
            }
        }while(next_permutation(perm.begin(),perm.end()));
        cout << count << endl;
    }
};
int main(){
    solver s;
    while(s.read_input()){
        s.solve();
    }
    return 0;
}