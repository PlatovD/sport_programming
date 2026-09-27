import sys

input = sys.stdin.readline
print = sys.stdout.write


def main():
    a, b = map(int, input().split())
    min_good_res = 10 ** 18 + 1

    for k in range(1, 14):
        c = round(a ** (1 / k))
        if c ** k == a:
            for p in range(1, 61):
                x = c ** p
                if k * x == p * b:
                    min_good_res = min(min_good_res, x)

    if min_good_res > 10 ** 18:
        print("0")
    else:
        print(str(int(min_good_res)))


if __name__ == "__main__":
    main()
