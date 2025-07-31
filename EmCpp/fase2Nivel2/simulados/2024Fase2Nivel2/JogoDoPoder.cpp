#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

/*
Ta, então a gente tem uma matriz NxM tipo:
2 3
2 3 9
1 7 200

A ideia do jogo é você escolhe um heroi que pode se mover pra cima pra baixo direita e esquerda e ai
ele vai lutando contra os caras do lado e ganha se o seu poder for >= ao do lado e nosso objeto é determinar
o maximo de pontos que cada casa inicial pode ter.

Bem, claramente não da pra fazer busca completa como é 10^6 tem que tar em O(N) ou O(NlogN)
E se a gente sortear a lista e pegar o maior cara ele vai logicamente ter uma pontuação máxima de 
soma(matriz) e se eu pergar o segundo... o chato a qui é que depende da posição

vamo pensar em como fazer uma busca completa primeiro, Tipo nesse exemplo:
2 3
2 3 9
1 7 2

Como poderiamos explorar todas as possiubilidades pro 2 do canto superior esquerdo? Ou melhor, como
você resolveria o jogo? como humano. Eu pensaria assim, 

Poder: 1
3 4 5 6 7
8 8 2 3 1
8 1 1 1 1 <- No caso de começar com esse 1

Repara que a ordem das jogas nao importa, imagina esses movimentos:

Poder: 2
3 4 5 6 7
8 8 2 3 1
8 1 1 # 0

Poder: 3
3 4 5 6 7
8 8 2 3 1
8 1 # 0 0

A lógica é: você pode ir pra todas as casas adjacentes a 0 (cima baixo esquerda direita)
A cada interação você deve andar até a batalha com menor poder necessário até que
Voce vença XD 
ou não tenha nenhuma batalha com poder >= seu poder

Pronto, já descobri como bruteforcear e pegar 1 ponto XD, hora de tentar pescar mais alguma coisa

A ideia já ta clara, temos que dar um jeito de cachear coisos repetidos, 

Uma primeira abordagem seria cachear todos os 2^N x M estados... mas não funciona
lembrando do tipo PD se desse pra encaixar isso em uma arvore tipo fibonat... 

em pseudo código ficaria (pensando que a posição sem nada é um 0 e a posição do heroi um -1)

solve (matrix, posição_inicial){
    int batalhas_vencidas = 1 //a inicial
    poder = matrix[posição_inicial]
    matrix[posição_inicial] = 0

    while (true){
        Encontra alguem vizinho a algum 0 com poder <= poder; 
        se achar
        poder+=matrix[i][j];
        matrix[i][j]=0;
        batalhas_vencidas++;
        se não achar:
        break;
    }
    return poder;//poder maximo que o cara alcançou
}

talvez de pra começar do menor numero da matrix ou ir da esquerda pra direita e ir salvando estados

Uma outra otimização seria ter um podermaximo (soma de todos os valor da matriz) e armazenar o valor
maximo em uma unica celula. Ai a gente que se alguma hora no while a gente atingir ou ultrapassar
o valor maximo de uma unica célula ta ganho, e poder = podemaximo.

mas vamos procurar uma solução otima, pensa no caso classo de fib onde fix(n) = fib(n-1)+fib(n-2) e 
antes de calcular o valor checamos em um map se fib[n] existe se existir usa o cache se não calcula e cacheia

Ou melhor ainda, se você quer algo tipo fib(10) a gente pode ir calculando de baixo pra cima
fib(3), ai depois fib(4) = fib(3) (já sabemos) + fib(2) (já sabemos)... 

a ideia aqui vai ser construir a arvore de baixo pra cima, quase certeza tipo olha esse exemplo onde
A e B valem 1;

3 4 5 6 7
8 8 2 3 1
8 1 1 B A

## Repara que começar em algum vizinho de A com poder = a ele é o mesmo que começar em A, o resultado 
final vai ser o mesmo

## é isso, eu posso resolver o jogo normal possibilidade por possibilidade, da direita pra esquerda pra cima
pra baixo só que se eu encontrar alguem ao longo do processo com poder <= ao vizinho o resultado vai ser
o mesmo 

Tipo se eu tenho:

9 9 9 9 5
10 2 1 1 1

resolveu o primeiro, olha o vizinho, se o poder for = ao dele ao inves de resolver usa o resultado cacheado
e isso em um while()
então com essa abordagem, da direita pra esquerda, resolveu o primeiro 9, seta o resultado e olha os vizinhos 
dele em um while, nesse primeiro step já ia matar os 4 primeiros 9. Ai depois resolve o 5...

to tendando pensar em um jeito de otimizar mais, tipo na fileira de baixo, esses 2 com 1 1 1...
Já sei, pensa que o primeiro que você ta resolvendo é o 1 do canto inferior direito, seguindo a 
abordagem de sempre ir a menor batalha, depois de 3 batalhas a matriz fica: 
poder: 5
9 9 9 9 5
10 0 0 0 0

## Se um dos vizinhos for = ao poder atual, ele tem obrigatoriamente o mesmo poder maximo que você

então a lógica fica -> Encontrar o valor máximo em uma unica celula (pequena otimização já que se o poder
atual for >= que o poder do melhor monstro então o poder maximo dessa posição é a soma de todos os
caras da matrix [precalculamos isso]) 

Depois de resolver pra alguma posição checamos seus vizinhos, Imagina que a gente tem uma matrix com a
resposta e a original. quando for adicionar o podermaximo em resposta[i][j] checa os adjacentes em
matrixTabuleiro e ve se o poder é igual a matrix[i][j], isso recursivamente ou em um while. 

Se em algum momento você tiver resolvendo o jogo e encontrar alguem com poder = poder atual. Salva esse
indice e depois quando for adicionar a resposta (daquele jeitinho recursivo) também adiciona essa mesma
resposta ao indice guardado. 

Ex: você resolveu o 1 do canto superior esquerdo
1 1 1 2 10
5 9 9 9 9

Adiciona ele na matrix -> checa vizinhos, acha o i=0,j=1  -> checa vizinhos acha o (i=0,j=2)
checa denovo-> não tem vizinhos (repara que tem que checar se o vizinho já nao foi calcula na matrix
com as respostas).

Ai vai pros guardados, no caso, seguindo a lógica de ir pra batalha mais facil, na terceira 
poder = 5 logo, o 5 tem o mesmo destino que esse cara que estamos calculando
0 0 0 0 10
5 9 9 9 9

mas e se fosse

1 1 1 9 10
5 9 1 1 1

depois de 4 batalhas:
poder = 5
0 0 0 9 10
5 9 0 0 1
mas a menor opção é 1 e não 5... nesse caso tem que buscar nas opções a cada turno tipo uma busca binária
por alguem com poder = poder...  nao sei se é uma otimização valida


E se eu resolver as mais baixas primeiro? tipo nesse exemplo:
5 6
10 10 10 10 10 10
10 10 1 1 1 10
10 10 10 1 10 10
10 10 10 4 10 10
10 10 10 10 10 2

eu posso resolver primeiro o 1, ai eu já sei que todos os 1 vao gerar 8 no final. Quer dizer que
quando outra pessoa for entrar nesse 1 o caminho todo que eu calculei na primeira vez pode ser reaproveitado
tipo, se ele pisar ali, (como 1 é o menor), automaticamente vai conquistar tudo que o 1 conquistou.

Outro exemplo, nesse caso, eu resolvi o 1 ai eu propago o mesmo resultado pros outros 1s, ai depois
resolve o 2, quando for resolver o 4 eu já sei que se ele consegue conqistar esse primeiro 1 conquista 
tambem todos os outros. Tipo quando e chegar nesse 1, como ele é um valor menor, eu posso ir na minha
matrix resposta somar o poder final dele ao meu e mudar todos os outros coisos pelo qual ele passou para 0

meh a ideia ta ok mas a implementação não é essa 
*/




main (){

    int N;M cin >> N >> M;

    vector<vector<int>> matriz(N, vector<int>(M));
    for (int i =0; i<N; i++){
        for (int j =0; j<N; j++){
            
        }
    }


}