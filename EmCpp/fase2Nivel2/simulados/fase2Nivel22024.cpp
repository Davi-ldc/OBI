//https://neps.academy/br/exercise/2797
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Restrição -> sempre mais de 2 lados

Ela só vai pintar a parte de fora, Ou seja, todos os de dentro vão ter 0 faces pintadas
A questão é, o que determina quantos quadrados estão na parte de fora?
Pensando em faces, cada cubo tem 6 lados com N² *faces externas*. 
Os quadrados do meio, sempre vão ter 1 única face pintada, 
Hora da tabela:
N   Quadrados do meio
2 -> 0²
3->1²
4->2²
5->3²
BUMM formula de quem só tem uma face pintada = (N-2)² * 6 (por que são 6 faces) 

ta, mas e os cubinhos de 2 faces pintadas (os da borda sem ser o da ponta).
Primeiro já vamos perceber que TODO cubo tem 8 cubos da ponta que vão ter 3 faces pintadas, opa, mais uma formula

BUMM formula de quem tem 3 faces pintadas = 8

De volta a 2 faces, agora que a gente já sabe que das 6xN² faces 8*6 são da ponta, (N-2)²*6 é do meio, o que
sobrou /2 = cubos com 2 lados pintados 

dava até pra simplificar o 6 mas vamo deixar pra ficar mais legivel
*/

int main(){

    int N; cin >> N;
    
    long long totais = pow(N, 3);//4³ = 64
    int faces_externas = 6 * N * N;//6*4² = 96
    int uma = pow(N-2, 2)*6;//(4-2)²*6 = 24
    int tres = 8;//sempre 8 cubos com 3 pintadas
    //Se a gente sabe que tem 96 faces externas. 8*3 são dos cubos da ponta
    //24 são dos cubos do meio
    int duas = ( faces_externas - (uma+tres*3) ) /2;//96-( 24+(8*6) )/ 2 -> 96-48/2 = 48/2 = 24

    int nenhuma = totais - (uma + duas + tres);//64 - (24 + 8 + 24) = 8

    cout << nenhuma << endl;//8
    cout << uma << endl;//24
    cout << duas << endl;//24 
    cout << tres;//8

    return 0;
}