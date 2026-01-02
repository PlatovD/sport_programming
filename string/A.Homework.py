t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    m = int(input())
    b = input()

    c = input()
    i = 0
    for symb in c:
        if symb == 'V':
            a = b[i] + a
        else:
            a = a + b[i]
        i+=1
    print(a)
