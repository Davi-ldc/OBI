//https://neps.academy/br/exercise/2713
//o mais dificl da prova na minha opinião 

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Ta acho que o meta aqui é ir computando segundos, minutos e dps hrs
pera, melhor ainda, repara que 100 segundos é 100/60 minutos +
100%60 segundos e o mesmo dai pra frente.

Repara tmb que x minutos são 60*x segundos

e x horas são 60*x minutos

então com essa logica agente pode converter

X horas = X*60M
X minutos = X*60S

Segundos += isso 

Ta ai agente tem o tempo total
tipo 100segundos.

Ai agente tem que separar. 100s são 1m e 40s
ou seja o segundos vai ser T%60, já os minutos é
T/60
e as hora são (T/60)

em uma hora tem 60*60 segundos 
em um segundo tem 

*/

int main(){

    long long H, M, S, T;
    cin >> H >> M >> S >> T;

    int respostaS = (S+(T%60))%60;

    M += 60*H;//hora pra mim
    S += 60*M;//Minuto pra Segundo
    T += S;//tempo total

    M = (T/60)%60;//Em x segundos tem X/60 M, e isso vai até 59
    H = (T/3600)%24; //msm lgoica aq mas /60²

    cout << H << endl;
    cout << M << endl;
    cout << respostaS << endl;

    return 0;
}