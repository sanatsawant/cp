const int M=1e9+7;

int powm(int a, int b) {
    if (b == 0) return 1;
    ll res = powm(a, b / 2); 
    res = (res * res) % M; 
    if (b & 1) {         
        res = (res * a) % M;
    }
    return res;
}
