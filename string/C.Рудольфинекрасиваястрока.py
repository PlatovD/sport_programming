t = int(input())

for _ in range(t):
    n = int(input())
    s: str = input()
    total = s.count('mapie')
    s = s.replace('mapie', 'ma_ie')
    total += s.count('map')
    total += s.count('pie')
    print(total)
