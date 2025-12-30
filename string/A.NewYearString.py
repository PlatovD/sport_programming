t = int(input())
for i in range(t):
    n = input()
    s = input()
    if '2025' in s and not '2026' in s:
        print(1)
    else:
        print(0)