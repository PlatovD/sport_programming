n = int(input())
l = []
for _ in range(n):
    l.append(input())

m = -1
for s in l:
    m = max(m, len(s))

res = []
for s in l:
    diff = (m - len(s)) // 2
    res.append('.' * diff + s + '.' * diff)

for s in res:
    print(s)
