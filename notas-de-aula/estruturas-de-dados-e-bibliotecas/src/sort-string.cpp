#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> vs = {"Joao","Ariosvaldo","Godofredo","Astrogilda","Hortolina"};
    sort(vs.begin(),vs.end());
    for(auto s: vs){
        cout << s << endl;
    }
    return 0;
}