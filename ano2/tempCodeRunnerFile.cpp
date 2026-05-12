
signed main (){

    int N; cin >> N; 

    if (N == 1) {cout << 1; return 0;}
    int r = 1;
    for (int i =1; i<N; i++){
        r += i % 2; 
    }
    cout << r;

    return 0;
}