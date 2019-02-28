
f = vector<int>(v.size());
f[0] = 0;
for(size_t i=1;i<v.size();i++){
    f[i] = f[i-1]+c[i];
}