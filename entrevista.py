N = int(input('N'))
L = []

for c in range(N):
    m = input('NxN')
    L.append(m)

def ck(i1, i2):
    print(i1-1,i2-1)
    print(L[i1-1][i2-1], bool(int(L[i1-1][i2-1])))
    return bool(int(L[i1-1][i2-1]))#int pq bool('0') retorna true

def checkFryend(K, Numeros):
    for c in range(int(K)):
        Resposta = 0
        for i in range(len(Numeros)-c-1):
            Resposta = ck(int(Numeros[c]), int(Numeros[i+c+1]))
            if Resposta:
                return True
    return Resposta

E = int(input('E'))

for c in range(E):
    K = input('K')
    K = K.split()
    if checkFryend(K[0],K[1:]):
        print('S')
    else:
        print('N')



    


"""
01001
10001
00000
00000
11000
"""

"""
    1   2   3   4   5 
1   0   1   0   0   1
2   1   0   0   0   1
3   0   0   0   0   0
4   0   0   0   0   0
5   1   1   0   0   0

def checkFryend(i1, i2):
    return bool(L[i1-1][i2-1])
"""


"""
A B C 
AB AC 
BA BC
CA CB


A B C D
AB AC AD 
BA BC BD
CA CB CD
DA DB DC 

Logica é que depois de compara A, Não precisa mais comparar ninguem com ele
depois de comparar B nao precisa comparar ninguem com B e A e assim por diante 
Então o caluculo é AB AC AD, depois BC BD depois CD

Pra cada N numeros comparamos o primeiro com N
O segundo com N-1
O terceiro com N-2 
e o ultimo não precisa ser comparado

Pra cada N numeros comparamos o primeiro n com o
""" 