void connected_components(){
    int n = 1;
    for(size_t i=0;i<adj_list.size();i++){
        if(dfs_num[i]==NOT_VISITED){
            cout << "Component #" << n << ": ";
            dfs(i);
            n++;
            cout << endl;
        }
    }
}

void dfs(int u){
    cout << u << " "; // imprime-se um nó da i-ésima componente 
    dfs_num[u] = VISITED;
    for(auto& v: adj_list[u]){
        if(dfs_num[v.first]==NOT_VISITED){
            dfs(v.first);
        }
    }
}