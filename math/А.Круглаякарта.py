import math
from math import atan2

x0, y0 = map(float, input().split())
x1, y1 = map(float, input().split())
n = int(input())

cos_angle = x0 * x1 + y0 * y1
sin_angle = x0 * y1 - y0 * x1

angle = atan2(sin_angle, cos_angle)
if angle < 0:
    angle += math.pi * 2

ratio = 2 * math.pi / angle
k = (n - 1) % ratio
total_angle = k * angle
cos_k = math.cos(total_angle)
sin_k = math.sin(total_angle)

print(f'{x1 * cos_k - y1 * sin_k} {x1 * sin_k + y1 * cos_k}')
