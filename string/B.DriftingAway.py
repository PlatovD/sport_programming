t = int(input())
for i in range(t):
    s = input()
    if '><' in s:
        print(-1)
        continue
    if '**' in s:
        print(-1)
        continue
    if '>*' in s:
        print(-1)
        continue
    if '*<' in s:
        print(-1)
        continue
    if s == '*':
        print(1)
        continue
    left_stars = 0
    center_stars = 0
    right_stars = 0
    left_char = 0
    right_char = 0
    for char in s:
        if char == '*':
            if left_char == 0:
                left_stars += 1
            elif left_char != 0 and right_char == 0:
                center_stars += 1
            else:
                right_stars += 1
        if char == '<':
            left_char += 1
        if char == '>':
            right_char += 1

    res = 0
    if right_char == 0:
        res = left_char + left_stars + center_stars + right_stars
    elif left_char == 0:
        res = right_char + left_stars + center_stars + right_stars
    else:
        res = max(left_stars + left_char + center_stars, center_stars + right_char + right_stars)
    print(res)
