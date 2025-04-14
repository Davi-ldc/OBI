import sys

# sys.stdout.write('Oiii') 
# sys.stdout.write('Oiii') # Repara que ele nao adiciona O /n No final

input = sys.stdin.readline
print = sys.stdout.write

# n = int(input())  # lê um número
# print(str(n * 2) + "\n")  # imprime o dobro


"""
Ex de probleminha simples ler ume entrada com vários numeros tipo
1
3
6
7
0
8
e ir somando eles. Se aparecer um 0 para de somar
OBS: lembra que tem que ter um ctrl + Z + Enter se tiver mandando manualmente no 
terminal pra indicar que a entrada acabou
"""
all_data = sys.stdin.read().split("\n")
r = 0
for c in all_data:
    if c.strip()==0:
        break
    if c.strip():
        r+=int(c)
print(str(r))
