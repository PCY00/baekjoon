N = int(input())
arr = list(map(int, input().split()))

yeongshik = 0
minshik = 0

for i in range(N):

    yeongshik +=  (arr[i] // 30 + 1) * 10
    minshik += (arr[i] // 60 + 1) * 15


if yeongshik > minshik:
    print(f"M {minshik}")
elif yeongshik < minshik:
    print(f"Y {yeongshik}")
else:
    print(f"Y M {minshik}")