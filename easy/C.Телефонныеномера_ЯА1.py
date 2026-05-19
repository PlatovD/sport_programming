def main():
    additional = input().replace('-', '').replace('(', '').replace(')', '').replace('+', '')
    n0 = input().replace('-', '').replace('(', '').replace(')', '').replace('+', '')
    n1 = input().replace('-', '').replace('(', '').replace(')', '').replace('+', '')
    n2 = input().replace('-', '').replace('(', '').replace(')', '').replace('+', '')
    numbers = [additional, n0, n1, n2]

    for i in range(4):
        number = numbers[i]
        if len(number) == 11:
            numbers[i] = number[1:]
        if len(number) == 8:
            numbers[i] = '495' + number[1:]
        if len(number) == 7:
            numbers[i] = '495' + number

    for i in range(1, 4):
        if numbers[i] == numbers[0]:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()
