def is_palindrome(s):
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True

def solve():
    s = input().strip()
    n = len(s)

    t = 0
    for i in range(n - 1, -1, -1):
        if s[i] == 'a':
            t += 1
        else:
            break

    if t == n:
        print("Yes")
        return

    remaining = s[:n - t]

    if is_palindrome(remaining):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    solve()