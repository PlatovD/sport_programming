t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    l, r = 0, 1
    while l < n and r < n:
        if s[l] == s[r]:
            s = s[:l] + '**' + s[r + 1:]
            l += 2
            r += 2
        l += 1
        r += 1

    last_symb = ''
    stack = []
    for i in range(n):
        if s[i] != '*':
            if not len(stack) == 0 and stack[len(stack) - 1] == s[i]:
                stack.pop()
            else:
                stack.append(s[i])
    if len(stack) != 0:
        print('NO')
    else:
        print('YES')
