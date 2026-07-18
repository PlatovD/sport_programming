import sys

input = sys.stdin.readline
print = sys.stdout.write


def fast_pow(num, power):
    res = 1
    while power > 0:
        if power % 2 == 1:
            res *= num
        num *= num
        power //= 2
    return res


def main():
    n, k = map(int, input().split())
    res = 0
    determinator = fast_pow(k, n)

    for x in range(1, k + 1):
        ways = fast_pow(x, n) - fast_pow(x - 1, n)
        res += x * ways / determinator

    print(str(round(res, 10)))


if __name__ == "__main__":
    main()
