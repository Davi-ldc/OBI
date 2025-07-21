#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Cada consoante deve ser substituída por exatamente três letras, na seguinte ordem:

a própria consoante (vamos chamar de consoante original);
a vogal mais próxima da consoante original no alfabeto, com a regra adicional de que se a consoante original está à mesma distância de duas vogais, então a vogal mais próxima do início do alfabeto é usada. Por exemplo, se a consoante original é d, a vogal que deve ser usada é e, pois esta é a vogal mais próxima; se a consoante original é c, a vogal que deve ser utilizada é a, porque c está à mesma distância de a e e, e a é mais próxima do início do alfabeto.
a consoante que segue a consoante original, na ordem do início ao fim do alfabeto. Por exemplo, se a consoante original é d, a consoante a ser utilizada é f. No caso de a consoante original ser z, deve ser utilizada a própria letra z.
*/

int main(){
    string s; cin >> s;
    vector<char> Resposta;

    string vogais = "aeiou";
    //sem w e sem y por causa do anunciado!!
    string alfabeto = "abcdefghijklmnopqrstuvxz";

    for (char c : s){
        //se nao for uma vogal
        if (find(vogais.begin(), vogais.end(),c)==vogais.end()){
            Resposta.push_back(c);//primeiro passo

            auto posE = find(alfabeto.begin(), alfabeto.end(), c);
            auto posD = posE;
            for(int i=0; i<alfabeto.size();i++){//segundo
                if (posE != alfabeto.begin()){
                    posE--;
                    auto achou = find(vogais.begin(), vogais.end(), *posE);
                    if(achou != vogais.end()){//se tiver achado
                        Resposta.push_back(*achou);
                        break;
                    }
                    
                }
                if(posD != alfabeto.end()-1){
                    posD++;
                    auto achou = find(vogais.begin(), vogais.end(), *posD);
                    if(achou != vogais.end()){//se tiver achado
                        Resposta.push_back(*achou);
                        break;
                    }
                }
            }
            //terceiro
            if(c == 'z'){
                Resposta.push_back(c);
                continue;
            }

            auto posicao = find(alfabeto.begin(), alfabeto.end(), c);
            posicao++;
            //se a proxima for consoante
            if(find(vogais.begin(), vogais.end(), *posicao) == vogais.end()){
                Resposta.push_back(*posicao);
            }
            else {
                posicao++;
                Resposta.push_back(*posicao);
            }

        }
        else{
            Resposta.push_back(c);
        }
    }

    for(auto x : Resposta){
        cout << x;
    }

    return 0;
}
