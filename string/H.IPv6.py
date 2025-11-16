s = input()
if s == '::':
    print("0000:0000:0000:0000:0000:0000:0000:0000")
else:
    s = s.split(':')
    res = ''
    cnt = s.count('')
    if cnt > 1:
        s.remove('')
    add = 8 - (len(s) - 1)
    for word in s:
        if word == '':
            res += ':0000' * add
            continue
        res += ':'
        res += '0' * (4 - len(word))
        res += word.lower()

    print(res[1:] if res[-1] != ':' else res[1:-1])
