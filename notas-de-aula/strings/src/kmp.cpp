#include <bits/stdc++.h>

using namespace std;

vector<int> preprocess(string& p){
    vector<int> next(p.size()+1);
    int j;
    next[0] = j = -1;
    for(size_t i=1;i<=p.size();i++){
        while(j>=0 && p[i-1]!=p[j]){
            j = next[j];
        }
        j++;
        next[i] = j;
    } 
    return next;
}

void kmp(string& t,string& p){
    auto next = preprocess(p);
    size_t i,j;
    i = j = 0;
    while(i<t.size()){
        while(j>=0 &&  p[j]!=t[i]){
            j = next[j];
        }
        j++;
        i++;
        if(j==p.size()){
            cout << "Padrão encontrado na posição " << i-j << endl;
            j = next[j];
        }
    }
}


int main(){
    string t = "xyxxyxyxyyxyxyxyyxyxyxx";
    string p = "xyxyyxyxyxx";
    kmp(t,p);
}