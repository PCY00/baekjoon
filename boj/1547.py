N = int(input())
ball = 1

for _ in range(N):
    x, y = map(int, input().split())
    
    if ball in (x, y):
        ball = y if ball == x else x

print(f"{ball}")