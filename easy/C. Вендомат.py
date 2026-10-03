import sys

input = sys.stdin.readline
print = sys.stdout.write


def to_nums(s):
    return map(int, s.strip().split(','))


def main():
    n, money = input().split()
    a, b = to_nums(money)

    best_prise = (-1, -1)
    name = '-1'
    for i in range(int(n)):
        cur_name, money = input().split()
        new_a, new_b = to_nums(money)
        if new_a <= a and new_b <= b:
            if best_prise[0] < new_a or (best_prise[0] == new_a and best_prise[1] < new_b):
                best_prise = (new_a, new_b)
                name = cur_name

    print(name)


if __name__ == "__main__":
    main()

