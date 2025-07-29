//https://neps.academy/br/exercise/291

#include <iostream> 
#include <bits/stdc++.h>
#define int long long

using namespace std;

main(){
    //Comprimento do cartão e numero de frases
    int c = 1;
    while (true){
        //Comprimento do cartão/frases coletadas
        int C, F; cin >> C >> F;

        if (C==F && F==0) break;

        vector<pair<int,int>> V(F);
        for (int i=0; i<F; i++){
            //peso, valor
            int p,v; cin >> p >> v;
            V[i] = {p,v};
        }

        //A logica é a mesma do problema da mochila, criamos um vetor dp de tamanho capacidade+1
        //onde dp[i] é o valor máximo pra maior capacidade i 
        vector<int> dp(C+1);
        dp[0] = 0;//logicamente, com 0 objetos o máximo que pode ser carregado é 0

        //Ai pra cada par {peso,valor} no vetor
        for (auto par: V){
            int p = par.first;
            int v = par.second;
            for (int i = C; i>=p; i--){
                //Tipo imagina que eu to adicionando um objeto com peso 8 e valor 2, como ele contri-
                //bui com o vetor dp? Bem, como você já pode imaginar, a partir de peso >= 8 pode ser
                //que a existencia dele mude o maior valor possivel para uma capacidade C;
                //Imagina que estamos analisando a capacidade 10, qual o maior valor que pode ser
                //atingido com esse novo objeto? Ora, é a maior capacidade com C=2 + o valor atual
                //Ou seja, o valor máximo em uma posição i  é o máximo com capacidade i-p +
                //valor que o peso atual nos da.

                if (dp[i-p] + v > dp[i]){
                    dp[i] = dp[i-p] + v;
                } 
            }
        }
        cout << "Teste " << c << endl;
        cout << dp[C] << endl;
        c++;
    }


}