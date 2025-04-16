L = '1 2 3 4 5 6 7'
arr = [print(x) for x in L.split() if int(x)%2==1]
print(arr)  # [5, 3, 2, 6, 8, 1]