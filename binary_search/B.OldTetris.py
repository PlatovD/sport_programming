def calc_points(x: int) -> int:
    return 20 * x + 50 * x * x


x = int(input())
l = 0
r = 10 ** 1000

total_level = 0
while l <= r:
    mid = l + (r - l) // 2
    if calc_points(mid) >= x:
        total_level = mid
        r = mid - 1
    else:
        l = mid + 1

total_points = calc_points(total_level)
total_level = total_level * 2

current_price = total_level * 10
cnt_steps = 0
while total_points - current_price >= x and cnt_steps < 2 and total_points - current_price >= 0:
    cnt_steps += 1
    total_points -= current_price

if cnt_steps > 0:
    total_level -= 1
    total_level = max(0, total_level)

cnt_steps = 0
current_price = total_level * 10
while total_points - current_price >= x and cnt_steps < 2 and total_points - current_price >= 0:
    cnt_steps += 1
    total_points -= current_price
if cnt_steps > 0:
    total_level -= 1
    total_level = max(0, total_level)

print(total_level, total_points)
