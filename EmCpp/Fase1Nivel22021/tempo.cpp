#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* OBI 2021->
as únicas mensagens que Sara envia são respostas a mensagens que ela recebeu
Sara envia no máximo uma mensagem como reposta a uma mensagem que recebeu
um amigo de Sara nunca envia uma nova mensagem para Sara até que tenha recebido resposta 
da mensagem que enviou anteriormente

R X -> recebido de X
E X -> Enviado para X
T X-> Tempo entre eventos

Se não há registro do tipo T X entre dois registros de eventos consecutivos significa que exatamente
1 segundo se passou entre esses dois eventos.

O Tempo de Resposta de uma mensagem é o tempo que se passa entre o recebimento da mensagem
por Sara e o envio da resposta a essa mensagem por Sara. Se um amigo recebeu respostas para todas
as suas mensagens, o Tempo de Resposta Total para esse amigo é a soma dos Tempos de Respostas
para as mensagens desse amigo; caso contrário o Tempo de Resposta Total para esse amigo é −1

1 ≤ X ≤ 100

R 12
T 2
R 23
T 3
R 45
E 45
R 45
E 23
R 23
T 2
E 23
R 34
E 12
E 34


Ta, recebeu do 12 e passou 2 segundos, ou seja matrix [12] = 2
*/

int main(){

    int N; cin >> N;
    
    // vector<pair<char,int>> V();
    map<int,int> V;
    map<int,int> Resposta;
    int t = 0;
    
    bool b = false;
    for (int i =0; i<N; i++){
        string c;
        int x;
        cin >> c >> x;
        if (c == "R"){
            V.insert({x,0});
            b = true;
        }
        else if (c == "E"){
            Resposta.insert({x,V[x]});
            V.erase(x);
            // b = true;
        }
        else if (c == "T"){
            for(auto& p : V){
                p.second += x;
            }
            b = false;
        }
        else if(b=true){
            for(auto& p : V){
                p.second += 1;
            }
        }
    }

    for( auto p: Resposta){
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}