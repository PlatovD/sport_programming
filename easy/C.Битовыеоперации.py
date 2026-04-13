n = int(input())
a = input()
b = input()

res = ''
was_first = False
for i in range(n):
    if a[i] == b[i]:
        if not was_first: continue
        res += '0'
    else:
        res += '1'
        was_first = True
if not res:
    print('0')
else:
    print(res)
