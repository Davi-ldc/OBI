//https://neps.academy/br/exercise/2792
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //K -> alfabeto alienigena
    //N-> normal
    int K; int N; cin >> K; cin >> N;

    set<char> A;//alfabeto alienigena
    for (int i=0; i<K; i++){
        char temp; cin >> temp;
        A.insert(temp);
    }

    vector<char> M(N);//mensagem
    for (int i =0;i<N;i++){
        cin >> M[i];
    }

    /*
    A gente tem que checar todos os itens da Mensagem e ver se algum deles não está no alfabeto alienigena

    Isso resolve em O(log(N))
    */
    bool alienigena = true;
    for (char c: M){//N
        //se a mensagem não estiver no alfabeto alienigena
        if (find(A.begin(),A.end(),c) == A.end()){//LOG(N)
            alienigena = false;
            break;
        }
    }
    if (alienigena){
        cout << "S";
    }
    else {
        cout << "N";
    }

    return 0;
}