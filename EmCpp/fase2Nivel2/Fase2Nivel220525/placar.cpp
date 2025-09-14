#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
2 24 38
3 1 21 63

0 
2 60 70
*/
int main (){
    int P; cin >> P;
    vector<int> GolsP(P);
    for (int i=0; i<P; i++){
        cin >> GolsP[i];
    }

    int C; cin >> C;
    vector<int> GolsC(C);
    for (int i=0; i<C; i++){
        cin >> GolsC[i];
    }

    int Paulo =0;
    int Camila =0;
    for(int i =0; i<C+P+1; i++){
        cout << Paulo << " " << Camila << endl;
        //Paulo é 2 Camila é 2 e os vetores são 24, 38 (paulo) 1 21 63 camila
        int v1=10000; int v2 =10000;
        if (Paulo < P){//false
            v1 = GolsP[Paulo];//V1 =0 
        }
        if (Camila < C){//True
            v2 = GolsC[Camila];//V2 = 63
        }
        // cout << v1 << " " << v2 << endl;
        if (v1<v2){
            Paulo++;
        }
        else{
            Camila++;//isso aq
        }
    }
    return 0;
}