import sys

input = sys.stdin.readline
print = sys.stdout.write


def main():
    L, R = map(int, input().split())

    best_divider = 1
    best_x = L
    best_y = L + 1
    for x in range(L, R + 1):
        l = 1
        r = 12
        while l <= r:
            mid = (l + r) // 2
            if mid * x <= R:
                l = mid + 1
                if mid * x != x and best_divider < x:
                    best_divider = x
                    best_x = x
                    best_y = x * mid
            else:
                r = mid - 1

    print(str(best_x))
    print(' ')
    print(str(best_y))


if __name__ == "__main__":
    main()
