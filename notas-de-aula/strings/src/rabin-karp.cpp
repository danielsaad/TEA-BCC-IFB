#include <bits/stdc++.h>

using namespace std;

bool compare(string& t,string& p,size_t i){
    return p == t.substr(i,p.size());
}

int preprocess(string& s,int d,int q){
    int sum = 0;
    for(size_t i=0;i<s.size();i++){
        sum = (sum*d + s[i]) % q;
    }
    return sum;
}

void rabin_karp(string& t,string& p,int d, int q){
    int h = pow(d,p.size()-1);
    h = h % q;
    int p_v = preprocess(p,d,q);
    auto t_prefix = t.substr(0,p.size());
    int t_v = preprocess(t_prefix,d,q);
    for(size_t i=0;i<t.size()-p.size()+1;i++){
        if(p_v == t_v && compare(t,p,i)){
            cout << "Padrão ocorre na posição " << i << endl;
        }
        if(i<t.size()-p.size()){
            t_v = ((( d*(t_v- t[i]*h) + t[i+p.size()]) % q)+q) % q;
        }
    }
}


int main(){
    string t = "2359023141526739921";
    string p = "31415";

    for(size_t i=0;i<t.size();i++){ t[i] -='0';}
    for(size_t i=0;i<p.size();i++){ p[i] -= '0';}

    rabin_karp(t,p,10,13);
}