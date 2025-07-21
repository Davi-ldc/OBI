//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/o-banco-inteligente

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int S; cin >> S; //Soma desejada
    /*
    a gente tem a moedas de 2, b de 5, c de 10, d de 20, e de 50 e f de 100 
    e quer saber quantas formas há de somar S. A solução intuitiva seria olhar todas as somas
    possiveis o que é 2 elevado a N opções, pra cada moeda a mais, é x2. Mas, como na aula anterior
    A logica aqui é quebrar em mine probleminhas. tipo da pra guardar quantas maneiras a de atingir cada soma
    em um vetor dp (dinamic Programing) tal que dp[0]=1 já que tem uma maneira de somar 0.

    A ideia é:
    Se eu já consigo atingir a soma i de dp[i] formas, então, ao adicionar j moedas de valor valor,
    também consigo atingir a soma i + valor * j de dp[i] formas adicionais.

    Tipo se eu ja consigo somar 4 de 3 formas (dp[4] = 3) e somar 6 de 2 dp[6]=2, ao adicionar mais uma moeda de 2 
    posso somar 6 de mais 3 formas (tipo cada uma das formas de somar 4 agora gera um ramo para somar 6)

    Se fossem mais 2 moedas então seria 
    */

    map<int, int> ValorQuantidade;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ValorQuantidade[2] = a;
    ValorQuantidade[5] = b;
    ValorQuantidade[10] = c;
    ValorQuantidade[20] = d;
    ValorQuantidade[50] = e;
    ValorQuantidade[100] = f;

    // número de formas de atingir cada soma
    vector<int> dp(S + 1, 0);
    dp[0] = 1; //(não usar nenhuma moeda) = uma forma

    // Para cada tipo de moeda
    for (auto par : ValorQuantidade) {
        int valor = par.first;      
        int quantidade = par.second; 

        //de trás para frente pra nao reutilizar a mesma moeda
        for (int i = S; i >= 0; i--) {
            for (int j = 1; j <= quantidade; j++) {
                if (i + valor * j <= S) {
                    dp[i + valor * j] += dp[i];
                }
            }
        }
    }

    cout << dp[S] << endl;

    return 0;
}