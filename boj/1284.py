
arr = [4, 2, 3, 3, 3, 3, 3, 3, 3, 3]

while True:
    N = input()

    if N == "0":
        break

    blank = len(N) + 1

    my_sum = 0
    for i in range(len(N)):
        my_sum += arr[int(N[i])]
    
    print(f"{my_sum + blank}")



# width = [4, 2, 3, 3, 3, 3, 3, 3, 3, 3]

# while True:
#     s = input()
#     if s == "0":
#         break

#     result = sum(width[int(ch)] for ch in s) + len(s) + 1
#     print(result)
