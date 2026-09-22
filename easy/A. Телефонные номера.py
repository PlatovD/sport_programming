import sys

# input = sys.stdin.readline
print = sys.stdout.write


def main():
    num = input()

    to_code = [num[i * 3:i * 3 + 3] for i in range((len(num) + 2) // 3)]
    for s in to_code:
        cur_res = str(bin(int(s)))[2:]
        if len(s) == 3:
            while len(cur_res) < 10:
                cur_res = '0' + cur_res
            print(cur_res)

        if len(s) == 2:
            while len(cur_res) < 7:
                cur_res = '0' + cur_res
            print(cur_res)

        if len(s) == 1:
            while len(cur_res) < 4:
                cur_res = '0' + cur_res
            print(cur_res)


if __name__ == "__main__":
    main()
